//--------------------------------------------------------------------------------------------
//
// Generated by X-HDL VHDL Translator - Version 2.0.0 Feb. 1, 2011
// Wed Apr 13 2022 19:50:42
//
//      Input file      : 
//      Component name  : jk_ff_vhdl
//      Author          : 
//      Company         : 
//
//      Description     : 
//
//
//--------------------------------------------------------------------------------------------


module JK_FF_VHDL(
    J,
    K,
    Reset,
    Clock_enable,
    Clock,
    Output
);
    input   J;
    input   K;
    input   Reset;
    input   Clock_enable;
    input   Clock;
    output  Output;
    
    reg     temp;
    
    always @(posedge Clock)
        
        begin
            if (Reset == 1'b1)
                temp <= 1'b0;
            else if (Clock_enable == 1'b1)
            begin
                if (J == 1'b0 & K == 1'b0)
                    temp <= temp;
                else if (J == 1'b0 & K == 1'b1)
                    temp <= 1'b0;
                else if (J == 1'b1 & K == 1'b0)
                    temp <= 1'b1;
                else if (J == 1'b1 & K == 1'b1)
                    temp <= (~(temp));
            end
        end
    assign Output = temp;
    
endmodule