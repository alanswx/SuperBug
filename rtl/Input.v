// Switch and steering input circuitry for Atari Super Bug
// (c) 2018 James Sweet
//
// This is free software: you can redistribute
// it and/or modify it under the terms of the GNU General
// Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your
// option) any later version.
//
// This is distributed in the hope that it will
// be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A
// PARTICULAR PURPOSE. See the GNU General Public License
// for more details.

module Input(
    DIP_Sw,
    Coin1_n,
    Coin2_n,
    Start_n,
    TrackSel_n,
    Gas_n,
    Gear1_n,
    Gear2_n,
    Gear3_n,
    Test_n,
    HScoreRes_n,
    Slam_n,
    Steering1A_n,
    Steering1B_n,
    SteerReset_n,
    In1_n,
    Opt_n,
    SkidIn_n,
    CrashIn_n,
    Adr,
    DBus
);
    input [7:0]  DIP_Sw;		// DIP switches
    input        Coin1_n;		// Coin switches
    input        Coin2_n;
    input        Start_n;		// Start switch
    input        TrackSel_n;		// Track Select switch
    input        Gas_n;
    input        Gear1_n;
    input        Gear2_n;
    input        Gear3_n;
    input        Test_n;		// Self test switch
    input        HScoreRes_n;		// High score reset switch
    input        Slam_n;		// Slam switch
    input        Steering1A_n;		// Steering wheel signals
    input        Steering1B_n;
    input        SteerReset_n;
    input        In1_n;
    input        Opt_n;
    input        SkidIn_n;
    input        CrashIn_n;
    input [2:0]  Adr;		// Adress bus, only the lower 3 bits used by IO circuitry
    output [7:0] DBus;		// Out to data bus, only bits 7, 1, and 0 are actually used
    
    
    wire         Coin1;
    wire         Coin2;
    
    reg          SteerDir;
    reg          SteerFlag;
    wire         Steering1A;
    
    reg          InputMux1;
    reg          InputMux2;
    reg [1:0]    DIP_Mux;
    
    assign Coin1 = ((~Coin1_n));		// Coin inputs are inverted by gates in H11
    assign Coin2 = ((~Coin2_n));
    assign Steering1A = (~Steering1A_n);
    
    // Steering inputs, handled by 7474's at H10 and J10 
    
    // 7474 D-FF: D tied high, clocked by Steering1B_n rising edge,
    // async clear by SteerReset_n. SteerDir samples Steering1A on each clock.
    always @(posedge Steering1B_n or negedge SteerReset_n)
    begin: SteeringA
        if (SteerReset_n == 1'b0)
        begin
            SteerFlag <= 1'b0;
            SteerDir  <= 1'b0;
        end
        else
        begin
            SteerFlag <= 1'b1;
            SteerDir  <= Steering1A;
        end
    end
    
    // 74153 data selector/multiplexer at F9, inverting since active-low
    // output is used. This drives DBus bit 7.
    //
    // The select order here is not Adr[2:0] counting up. Both this mux and E9
    // below had their inputs listed in schematic order but indexed with the
    // raw address, which scrambled every signal: gas was answered at offset 4
    // where the program reads offset 1, so the gas pedal never reached the
    // CPU at all and the engine sat at its idle value for the whole game.
    //
    // The order below is MAME's firetrk_state::input_r reading the BIT_7 port
    // for superbug, which agrees with the original memory map in
    // superbug/SUPMEM.MAC.
    always @(*)
    begin: F9
        case (Adr[2:0])
            3'b000 :
                InputMux1 = ((~Gear3_n));
            3'b001 :
                InputMux1 = ((~Gear1_n));
            3'b010 :
                InputMux1 = ((~SteerFlag));
            3'b011 :
                InputMux1 = ((~Coin1_n));
            3'b100 :
                InputMux1 = ((~Coin2_n));
            3'b101 :
                InputMux1 = ((~Start_n));
            3'b110 :
                InputMux1 = ((~CrashIn_n));
            3'b111 :
                InputMux1 = ((~TrackSel_n));
            default :
                InputMux1 = 1'b1;
        endcase
    end
    
    // 74153 data selector/multiplexer at E9, inverting since active-low
    // output is used. This drives DBus bit 0. Same correction as F9: order
    // taken from MAME's BIT_0 port for superbug.
    always @(*)
    begin: E9
        case (Adr[2:0])
            3'b000 :
                InputMux2 = (~Gear2_n);
            3'b001 :
                InputMux2 = (~Gas_n);
            3'b010 :
                InputMux2 = (~SteerDir);
            3'b011 :
                InputMux2 = (~HScoreRes_n);
            3'b100 :
                InputMux2 = 1'b0;
            3'b101 :
                InputMux2 = (~Test_n);
            3'b110 :
                InputMux2 = (~SkidIn_n);
            3'b111 :
                InputMux2 = (~Slam_n);
            default :
                InputMux2 = 1'b1;
        endcase
    end
    
    // 74153 dual selector/multiplexer at C6
    
    always @(*)
    begin: C6
        case (Adr[1:0])
            2'b00 :
                DIP_Mux = {DIP_Sw[7], DIP_Sw[6]};
            2'b01 :
                DIP_Mux = {DIP_Sw[5], DIP_Sw[4]};
            2'b10 :
                DIP_Mux = {DIP_Sw[3], DIP_Sw[2]};
            2'b11 :
                DIP_Mux = {DIP_Sw[1], DIP_Sw[0]};
            default :
                DIP_Mux = 2'b11;
        endcase
    end
    
    // Input data mux
    // Bits 1..6 read back as 0, not 1. MAME's input_r builds the byte from
    // just bit 0 and bit 7 for superbug and leaves the rest clear.
    assign DBus = (In1_n == 1'b0) ? {InputMux1, 6'b000000, InputMux2} : 
                  (Opt_n == 1'b0) ? {6'b000000, DIP_Mux} : 
                  8'hFF;
    
endmodule
