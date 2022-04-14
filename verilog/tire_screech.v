//--------------------------------------------------------------------------------------------
//
// Generated by X-HDL VHDL Translator - Version 2.0.0 Feb. 1, 2011
// Wed Apr 13 2022 19:48:01
//
//      Input file      : 
//      Component name  : tire_screech
//      Author          : 
//      Company         : 
//
//      Description     : 
//
//
//--------------------------------------------------------------------------------------------

// Tire screech sound generator for Kee Games Sprint 2 
// (c) 2017 James Sweet
//
// Original circuit used a 7414 Schmitt trigger oscillator operating at approximately
// 1.2kHz producing a sawtooth with the frequency modulated slightly by the pseudo-random 
// noise generator. This is an extension of work initially done in Verilog by Jonas Elofsson.
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

module tire_screech(
    Clk,
    Noise,
    Screech_out
);
    parameter   Inc1 = 24;		// These constants can be adjusted to tune the frequency and modulation
    parameter   Inc2 = 34;
    parameter   Dec1 = 23;
    parameter   Dec2 = 12;
    input       Clk;		// 750kHz from the horizontal line counter chain works well here
    input       Noise;		// Output from LFSR pseudo-random noise generator
    output reg  Screech_out;		// Screech output - single bit
    
    
    reg [13:0]  Screech_count;
    reg         Screech_state;
    
    
    always @(posedge Clk or Screech_state)
    begin: Screech
        
        begin
            if (Screech_state == 1'b1)		// screech_state is 1, counter is rising
            begin
                if (Noise == 1'b1)		// Noise signal from LFSR, when high increases the slope of the rising ramp
                    Screech_count <= Screech_count + Inc2;
                else
                    // When Noise is low, decreas the slope of the ramp
                    Screech_count <= Screech_count + Inc1;
                if (Screech_count > 10000)		// Reverse the ramp direction when boundary value of 10,000 is reached
                    Screech_state <= 1'b0;
            end
            else if (Screech_state == 1'b0)		// screech_state is now low, decrement the counter (ramp down)
            begin
                if (Noise == 1'b1)
                    Screech_count <= Screech_count - Dec2;		// Slope is influenced by the Noise signal
                else
                    Screech_count <= Screech_count - Dec1;
                if (Screech_count < 1000)		// Reverse the ramp direction again when the lower boundary of 1,000 is crossed
                    Screech_state <= 1'b1;
            end
        end
        Screech_out <= Screech_state;
    end
    
endmodule
