// Engine sound generator for Kee Games Sprint 2 / Atari Super Bug.
// Hand-written Verilog port of source/motor.vhd (James Sweet, 2017).
// Replaces a broken X-HDL auto-translation that fused two rising_edge
// branches into a single illegal always block.
//
// Original VHDL: a 555-style ramp oscillator at a frequency selected by
// EngineData[3:0], divided by a 7492 (div-2 + div-6) and XOR-mixed to
// produce a "lumpy" engine pulse train, then 3-tap boxcar low-pass
// filtered. Six-bit unsigned PCM out on Motor.

`default_nettype none

module EngineSound #(
    parameter integer Freq_tune = 50    // 0..100, overall pitch trim
) (
    input  wire        Clk_6,
    input  wire        Ena_3k,
    input  wire [3:0]  EngineData,
    output wire [5:0]  Motor
);

    // -- Speed select: 4-bit code -> RPM_val (1..350 fits in 9 bits)
    reg [8:0] RPM_val;
    always @(posedge Clk_6) begin
        case (EngineData)
            4'd0:  RPM_val <= 9'd280;
            4'd1:  RPM_val <= 9'd245;
            4'd2:  RPM_val <= 9'd230;
            4'd3:  RPM_val <= 9'd205;
            4'd4:  RPM_val <= 9'd190;
            4'd5:  RPM_val <= 9'd175;
            4'd6:  RPM_val <= 9'd160;
            4'd7:  RPM_val <= 9'd145;
            4'd8:  RPM_val <= 9'd130;
            4'd9:  RPM_val <= 9'd115;
            4'd10: RPM_val <= 9'd100;
            4'd11: RPM_val <= 9'd85;
            4'd12: RPM_val <= 9'd70;
            4'd13: RPM_val <= 9'd55;
            4'd14: RPM_val <= 9'd40;
            default: RPM_val <= 9'd25;
        endcase
    end

    // -- Unfiltered ramp terminal count = (200 - Freq_tune) * RPM_val
    //    Max = 200 * 350 = 70000, fits in 17 bits.
    wire [16:0] Ramp_term_unfilt = (17'd200 - Freq_tune[16:0]) * {8'd0, RPM_val};

    // -- Slew-rate limiter approximating the RC filter on the DAC output
    reg [16:0] Ramp_term;
    always @(posedge Clk_6) begin
        if (Ena_3k) begin
            if      (Ramp_term_unfilt > Ramp_term) Ramp_term <= Ramp_term + 17'd5;
            else if (Ramp_term_unfilt < Ramp_term) Ramp_term <= Ramp_term - 17'd3;
        end
    end

    // -- Variable-frequency ramp oscillator (approx 555 astable)
    reg [16:0] Ramp_count;
    reg        Motor_Clk;
    always @(posedge Clk_6) begin
        if (Ramp_count > Ramp_term) begin
            Ramp_count <= 17'd0;
            Motor_Clk  <= 1'b0;
        end else begin
            Ramp_count <= Ramp_count + 17'd1;
            Motor_Clk  <= 1'b1;
        end
    end

    // -- 7492-style divider (split out of the original VHDL dual-edge
    //    process; auto-translator could not represent this in Verilog).
    reg [2:0] Counter_B;
    always @(posedge Motor_Clk) begin
        Counter_B <= Counter_B + 3'd1;
    end

    wire Counter_A_clk = Counter_B[0] ^ Counter_B[2];

    reg Counter_A;
    always @(posedge Counter_A_clk) begin
        Counter_A <= ~Counter_A;
    end

    // -- 2-bit prefilter sum
    wire [1:0] Motor_prefilter = {1'b0, Counter_B[2]} + {1'b0, Counter_B[1]} + {1'b0, Counter_A};

    // -- 3-tap boxcar low-pass at the 3 kHz enable rate
    reg [3:0] Motor_filter_t1, Motor_filter_t2, Motor_filter_t3;
    reg [5:0] Motor_filtered;

    always @(posedge Clk_6) begin
        if (Ena_3k) begin
            Motor_filter_t1 <= {2'b00, Motor_prefilter} + {2'b00, Motor_prefilter};
            Motor_filter_t2 <= Motor_filter_t1;
            Motor_filter_t3 <= Motor_filter_t2;
        end
        Motor_filtered <= {2'b00, Motor_filter_t1}
                        + {1'b0,  Motor_filter_t2, 1'b0}
                        + {2'b00, Motor_filter_t3};
    end

    assign Motor = Motor_filtered;

endmodule

`default_nettype wire
