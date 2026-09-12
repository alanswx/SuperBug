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
    DBus,
    Clk6,
    Game,
    VBlank,
    Start2_n,
    Start3_n,
    Bell_n,
    Cabinet,
    DiagHold_n,
    DiagStep_n,
    Steering2A_n,
    Steering2B_n
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
    input        Clk6;
    input [1:0]  Game;		// 0 = Super Bug, 1 = Fire Truck
    // Fire Truck only. Super Bug ties these off.
    input        VBlank;		// Fire Truck reads vertical blank through the port
    input        Start2_n;		// back player start
    input        Start3_n;		// both players start
    input        Bell_n;		// back player's bell button
    input        Cabinet;		// 1 = two player Fire Truck, 0 = one player Smokey Joe
    input        DiagHold_n;
    input        DiagStep_n;
    input        Steering2A_n;	// back player's wheel
    input        Steering2B_n;
    
    
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
    
    // Steering inputs, handled by 7474's at H10 and J10.
    //
    // The schematic clocks these on the rising edge of Steering1B_n with
    // SteerReset_n as an async clear. Written literally, that is an always
    // block sensitive to two edges of two combinational signals, which the
    // simulator can fire at moments that have nothing to do with the wheel:
    // the flag would set on its own, the program would read continuous
    // steering, and the car span on the spot with no input at all. The same
    // mistake was already corrected in car.v and playfield.v; this was the
    // last one left.
    //
    // Rebuilt as an edge detector in the Clk6 domain. The reset strobe is a
    // whole CPU cycle wide, so sampling it on Clk6 cannot miss it.
    reg prev_Steering1B_n;
    always @(posedge Clk6)
    begin: SteeringA
        prev_Steering1B_n <= Steering1B_n;
        // Only the flag flip-flop has the async clear. The direction one just
        // samples, which is what the reference does too: its steer_reset_w
        // sets the flag and leaves the direction alone.
        if (SteerReset_n == 1'b0)
        begin
            SteerFlag <= 1'b0;
        end
        else if (Steering1B_n & ~prev_Steering1B_n)
        begin
            SteerFlag <= 1'b1;
            SteerDir  <= Steering1A;
        end
    end
    
    // Fire Truck has a second wheel for the back player, handled by the same
    // pair of flip-flops as the first. Both reset strobes are the same line.
    reg SteerDir2, SteerFlag2;
    reg prev_Steering2B_n;
    wire Steering2A = (~Steering2A_n);
    always @(posedge Clk6)
    begin: SteeringB
        prev_Steering2B_n <= Steering2B_n;
        if (SteerReset_n == 1'b0)
            SteerFlag2 <= 1'b0;
        else if (Steering2B_n & ~prev_Steering2B_n)
        begin
            SteerFlag2 <= 1'b1;
            SteerDir2  <= Steering2A;
        end
    end

    localparam GAME_FIRETRK = 2'd1;
    wire firetrk = (Game == GAME_FIRETRK);

    // Fire Truck answers on three data bits where Super Bug uses two, and
    // assigns them differently. Order from MAME's input_r reading the BIT_0,
    // BIT_6 and BIT_7 ports for firetrk; see docs/firetruck_port.md.
    reg ft_bit0, ft_bit6, ft_bit7;
    always @(*) begin
        case (Adr[2:0])
            3'd0: begin ft_bit0 = 1'b0;            ft_bit6 = ~Start_n;      ft_bit7 = 1'b0;          end
            3'd1: begin ft_bit0 = ~Gas_n;          ft_bit6 = ~Start2_n;     ft_bit7 = 1'b0;          end
            3'd2: begin ft_bit0 = SteerDir;        ft_bit6 = ~Start3_n;     ft_bit7 = ~SteerFlag;    end
            3'd3: begin ft_bit0 = SteerDir2;       ft_bit6 = ~TrackSel_n;   ft_bit7 = ~SteerFlag2;   end
            3'd4: begin ft_bit0 = ~Bell_n;         ft_bit6 = 1'b0;          ft_bit7 = ~Coin1_n;      end
            3'd5: begin ft_bit0 = ~Slam_n;         ft_bit6 = VBlank;        ft_bit7 = ~Coin2_n;      end
            3'd6: begin ft_bit0 = ~SkidIn_n;       ft_bit6 = Cabinet;       ft_bit7 = ~CrashIn_n;    end
            3'd7: begin ft_bit0 = ~Test_n;         ft_bit6 = ~DiagHold_n;   ft_bit7 = ~DiagStep_n;   end
        endcase
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
                // Not inverted. With the inversion this read 1 while the wheel
                // sat still, where the reference reads 0, so the program saw a
                // steering command on every pass and the car span on the spot
                // with no input at all. Reading it straight gives 0 at rest,
                // 1 turning left and 0 turning right, which is what the
                // reference reports.
                InputMux2 = SteerDir;
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
    // Fire Truck reads its switches in a different order and puts coinage on
    // the first bank, at bits 2 and 3, where Super Bug leaves that bank empty
    // and has coinage first in the second bank. The MRA byte is laid out the
    // same for both games, so only the read order changes:
    //   offset 0 language, 1 game time, 2 extended play, 3 unused
    reg [1:0] ft_dip_mux;
    always @(*) begin
        case (Adr[1:0])
            2'b00: ft_dip_mux = {DIP_Sw[1], DIP_Sw[0]};   // language
            2'b01: ft_dip_mux = {DIP_Sw[5], DIP_Sw[4]};   // game time
            2'b10: ft_dip_mux = {DIP_Sw[3], DIP_Sw[2]};   // extended play
            2'b11: ft_dip_mux = 2'b00;
        endcase
    end
    wire [7:0] ft_dip = {4'b0000, DIP_Sw[7], DIP_Sw[6], ft_dip_mux};

    assign DBus = firetrk
                ? ((In1_n == 1'b0) ? {ft_bit7, ft_bit6, 5'b00000, ft_bit0} :
                   (Opt_n == 1'b0) ? ft_dip :
                   8'hFF)
                : ((In1_n == 1'b0) ? {InputMux1, 6'b000000, InputMux2} : 
                   (Opt_n == 1'b0) ? {6'b000000, DIP_Mux} : 
                   8'hFF);
    
endmodule
