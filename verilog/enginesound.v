//--------------------------------------------------------------------------------------------
//
// Generated by X-HDL VHDL Translator - Version 2.0.0 Feb. 1, 2011
// Wed Apr 13 2022 19:48:01
//
//      Input file      : 
//      Component name  : enginesound
//      Author          : 
//      Company         : 
//
//      Description     : 
//
//
//--------------------------------------------------------------------------------------------

// Motor sound generator for Kee Games Sprint 2 
// Similar circuits are used in a number of other games
// (c) 2017 James Sweet
//
// Original circuit used a 555 configured as an astable oscillator with the frequency controlled by
// a four bit binary value. The output of this oscillator drives a counter configured to produce an
// irregular thumping simulating the sound of an engine.
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

module EngineSound(
    Clk_6,
    Ena_3k,
    EngineData,
    Motor
);
    parameter    Freq_tune = 50;		// Value from 0-100 used to tune the overall engine sound frequency
    input        Clk_6;
    input        Ena_3k;
    input [3:0]  EngineData;
    output [5:0] Motor;
    
    
    reg [8:0]    RPM_val;
    wire [16:0]  Ramp_term_unfilt;
    reg [16:0]   Ramp_Count;
    reg [16:0]   Ramp_term;
    wire [8:0]   Freq_mod;
    reg          Motor_Clk;
    
    reg          Counter_A;
    reg [2:0]    Counter_B;
    reg          Counter_A_clk;
    
    wire [1:0]   Motor_prefilter;
    reg [3:0]    Motor_filter_t1;
    reg [3:0]    Motor_filter_t2;
    reg [3:0]    Motor_filter_t3;
    reg [5:0]    Motor_filtered;
    
    // The frequency of the oscillator is set by a 4 bit binary value controlled by the game CPU
    // in the real hardware this is a 555 coupled to a 4 bit resistor DAC used to pull the frequency.
    // The output of this DAC has a capacitor to smooth out the frequency variation.
    // The constants assigned to RPM_val can be tweaked to adjust the frequency curve
    
    
    always @(posedge Clk_6)
    begin: Speed_select
        
            case (EngineData)
                4'b0000 :
                    RPM_val <= 280;
                4'b0001 :
                    RPM_val <= 245;
                4'b0010 :
                    RPM_val <= 230;
                4'b0011 :
                    RPM_val <= 205;
                4'b0100 :
                    RPM_val <= 190;
                4'b0101 :
                    RPM_val <= 175;
                4'b0110 :
                    RPM_val <= 160;
                4'b0111 :
                    RPM_val <= 145;
                4'b1000 :
                    RPM_val <= 130;
                4'b1001 :
                    RPM_val <= 115;
                4'b1010 :
                    RPM_val <= 100;
                4'b1011 :
                    RPM_val <= 85;
                4'b1100 :
                    RPM_val <= 70;
                4'b1101 :
                    RPM_val <= 55;
                4'b1110 :
                    RPM_val <= 40;
                4'b1111 :
                    RPM_val <= 25;
                default :
                    RPM_val <= 25;
            endcase
    end
    
    // There is a RC filter between the frequency control DAC and the 555 to smooth out the transitions between the
    // 16 possible states. We can simulate a reasonable approximation of that behavior using a linear slope which is
    // not truly accurate but should be close enough.
    
    always @(posedge Clk_6 or Ena_3k or Ramp_term_unfilt)
    begin: RC_filt
        
        begin
            if (Ena_3k == 1'b1)
            begin
                if (Ramp_term_unfilt > Ramp_term)
                    Ramp_term <= Ramp_term + 5;
                else if (Ramp_term_unfilt == Ramp_term)
                    Ramp_term <= Ramp_term;
                else
                    Ramp_term <= Ramp_term - 3;
            end
        end
    end
    
    // Ramp_term terminates the ramp count, the higher this value, the longer the ramp will count up and the lower
    // the frequency. RPM_val is multiplied by a constant which can be adjusted by changing the value of freq_tune
    // to simulate the function of the frequency adjustment pot in the original hardware.
    assign Ramp_term_unfilt = ((200 - Freq_tune) * RPM_val);
    
    // Variable frequency oscillator roughly approximating the function of a 555 astable oscillator
    
    always @(posedge Clk_6)
    begin: Ramp_osc
        
        begin
            Motor_Clk <= 1'b1;
            Ramp_Count <= Ramp_Count + 1;
            if (Ramp_Count > Ramp_term)
            begin
                Ramp_Count <= 0;
                Motor_Clk <= 1'b0;
            end
        end
    end
    
    // 7492 counter with XOR on two of the outputs creates lumpy engine sound from smooth pulse train
    // 7492 has two sections, one div-by-2 and one div-by-6.
    
    always @(posedge Motor_Clk or Counter_A_clk or Counter_B)
    begin: Engine_counter
        
            Counter_B <= Counter_B + 1'b1;
        Counter_A_clk <= Counter_B[0] ^ Counter_B[2];
        if (posedge Counter_A_clk)
            Counter_A <= ((~Counter_A));
    end
    assign Motor_prefilter = ({1'b0, Counter_B[2]}) + ({1'b0, Counter_B[1]}) + ({1'b0, Counter_A});
    
    // Very simple low pass filter, borrowed from MikeJ's Asteroids code
    
    always @(posedge Clk_6)
    begin: Engine_filter
        
        begin
            if (Ena_3k == 1'b1)
            begin
                Motor_filter_t1 <= ({2'b00, Motor_prefilter}) + ({2'b00, Motor_prefilter});
                Motor_filter_t2 <= Motor_filter_t1;
                Motor_filter_t3 <= Motor_filter_t2;
            end
            Motor_filtered <= ({2'b00, Motor_filter_t1}) + ({1'b0, Motor_filter_t2, 1'b0}) + ({2'b00, Motor_filter_t3});
        end
    end
    
    assign Motor = Motor_filtered;
    
endmodule
