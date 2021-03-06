//--------------------------------------------------------------------------------------------
//
// Generated by X-HDL VHDL Translator - Version 2.0.0 Feb. 1, 2011
// Wed Apr 13 2022 19:48:01
//
//      Input file      : 
//      Component name  : deltasigma
//      Author          : 
//      Company         : 
//
//      Description     : 
//
//
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// Company: 
// Engineer: 
// 
// Create Date:    20:12:02 06/27/2011 
// Design Name: 
// Module Name:    deltasigma - Behavioral 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//--------------------------------------------------------------------------------

//-- Uncomment the following library declaration if instantiating
//-- any Xilinx primitives in this code.
//library UNISIM;
//use UNISIM.VComponents.all;

module deltasigma(
    inval,
    output_xhdl0,
    clk,
    reset
);
    parameter         width = 8;
    input [width-1:0] inval;
    output reg        output_xhdl0;
    input             clk;
    input             reset;
    
    reg [width+1:0]   reg_xhdl1;
    wire [width+1:0]  reg_d;
    wire [width+1:0]  ddcout;
    
    
    always @(posedge clk or posedge reset)
    begin: ds
        if (reset == 1'b1)
        begin
            reg_xhdl1 <= {width+2{1'b0}};
            output_xhdl0 <= 1'b0;
        end
        else 
        begin
            reg_xhdl1 <= reg_d;
            output_xhdl0 <= reg_xhdl1[width];
        end
    end
    assign ddcout[width + 1:width] = 2'b00;
    assign ddcout[width - 1:0] = (reg_xhdl1[width] == 1'b1) ? {width+2{1'b1}} : 
                                 {width+2{1'b0}};
    assign reg_d = (({2'b00, inval}) - ddcout) + reg_xhdl1;
    
endmodule
