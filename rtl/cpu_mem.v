// CPU, RAM, ROM and address decoder for Atari/Kee Games Super Bug 
// 2018 James Sweet
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

module cpu_mem(
    Clk6,
    Reset_n,
    VBlank,
    HBlank,
    VCount,
    HCount,
    RW_n,
    VMA,
    PHI2,
    StartLamp,
    TrakSelLamp,
    Attract,
    Flash,
    In1_n,
    Opt_n,
    PHP_Load_n,
    PVP_Load_n,
    CarRot_n,
    ArrowOff_n,
    SteerReset_n,
    CrashReset_n,
    SkidReset_n,
    MotorSnd_n,
    CrashSnd_n,
    SkidSnd_n,
    Adr,
    DBus_in,
    DBus_out
);
    input         Clk6;
    input         Reset_n;
    input         VBlank;
    input         HBlank;
    input [7:0]   VCount;
    input [8:0]   HCount;
    output        RW_n;
    output        VMA;
    output reg    PHI2;
    output reg    StartLamp;
    output reg    TrakSelLamp;
    output reg    Attract;
    output reg    Flash;
    output        In1_n;
    output        Opt_n;
    output        PHP_Load_n;
    output        PVP_Load_n;
    output        CarRot_n;
    output        ArrowOff_n;
    output        SteerReset_n;
    output        CrashReset_n;
    output        SkidReset_n;
    output        MotorSnd_n;
    output        CrashSnd_n;
    output        SkidSnd_n;
    output [15:0] Adr;
    input [7:0]   DBus_in;
    output [7:0]  DBus_out;
    
    
    wire          Reset;
    
    wire          H2;
    wire          V16;
    
    wire          Phi1;
    wire          Legit;
    
    wire [7:0]    CPU_Din;
    wire [7:0]    CPU_Dout;
    
    wire [7:0]    RAM_Dout;
    wire          RAMce;
    wire          RAMwe;
    
    wire [7:0]    ROM1_Dout;
    wire [7:0]    ROM2_Dout;
    wire [7:0]    ROM3_Dout;
    wire [7:0]    ROM_Dout;
    
    wire          ROM1ce_n;
    wire          ROM2ce_n;
    wire          ROM3ce_n;
    
    wire          R_nW;
    reg           IRQ_n;
    wire          NMI_n;
    wire          BVMA;
    
    wire          BA12nor11;
    wire          SysEn;
    
    wire          WdogReset_n;
    //signal CrashReset_n	: std_logic;
    //signal SkidReset_n	: std_logic;
    
    wire          rw;
    
    wire          IO_Wr;
    wire          Out2_n;
    
    wire          nmi;
    wire          irq;
    
    assign Reset = ((~Reset_n));
    
    assign H2 = HCount[1];
    assign V16 = VCount[4];
    
    // Clock
    // This is a bit ugly, should rewrite
    
    always @(posedge H2)
    begin: Clock
        if (Reset == 1'b1)
            PHI2 <= 1'b0;
        else
            PHI2 <= ((~PHI2));
    end
    assign Phi1 = ((~PHI2));
    assign Legit = (~(H2 | Phi1));
    
    // IRQ
   
    always @(negedge V16 or negedge HBlank)
    begin: IRQ_DFF
        if (HBlank == 1'b0)
            IRQ_n <= 1'b1;
        else 		// Real hardware uses rising edge of inverted 16V
            IRQ_n <= 1'b0;
    end
    

    assign NMI_n = ((~VBlank));
    
    // Watchdog
    
    assign irq = (~IRQ_n);
    assign nmi = (~NMI_n);
    
    
    cpu68 CPU(
        .clk(PHI2),		// E clock input (falling edge)
        .rst(Reset),		// reset input (active high)
        //rw => R_nW,					-- Write active high AJS
        .rw(rw),		//R_nW,					-- Write active high
        .vma(VMA),		// valid memory address (active high)
        .address(Adr),
        .data_in(CPU_Din),
        .data_out(CPU_Dout),
        .hold(1'b0),		// hold input (active high) extend bus cycle
        .halt(1'b0),		// halt input (active high) grants DMA
        .irq(irq),		// interrupt request input (active high)
        .nmi(nmi)		// non maskable interrupt request input (active high)
    );
    
    assign DBus_out = CPU_Dout;		// when phi2 = '0' else (others => '1');	-- added phi2 
    
    assign R_nW = (~rw);
    assign RW_n = rw;
    //RW_n <= (not R_nW);		
    
    //CPU RAM
    
    ram256 M1(
        .clock(Clk6),
        .address(Adr[7:0]),
        .wren(RAMwe),
        .data(CPU_Dout[3:0]),
        .q(RAM_Dout[3:0])
    );
    
    
    ram256 N1(
        .clock(Clk6),
        .address(Adr[7:0]),
        .wren(RAMwe),
        .data(CPU_Dout[7:4]),
        .q(RAM_Dout[7:4])
    );
    
    // Program ROM
    
    ROM_D1 D1(
        .clock(Clk6),
        .address(Adr[10:0]),
        .q(ROM1_Dout)
    );
    
    
    ROM_C1 C1(
        .clock(Clk6),
        .address(Adr[10:0]),
        .q(ROM2_Dout)
    );
    
    
    ROM_A1 A1(
        .clock(Clk6),
        .address(Adr[10:0]),
        .q(ROM3_Dout)
    );
    
    // Program ROM mux
    assign ROM_Dout = (ROM1ce_n == 1'b0) ? ROM1_Dout : 
                      (ROM2ce_n == 1'b0) ? ROM2_Dout : 
                      (ROM3ce_n == 1'b0) ? ROM3_Dout : 
                      8'hFF;
    
    // Address decoding
    
    assign ROM1ce_n = (BVMA == 1'b1 & Adr[12:11] == 2'b01) ? 1'b0 : 
                      1'b1;
    assign ROM2ce_n = (BVMA == 1'b1 & Adr[12:11] == 2'b10) ? 1'b0 : 
                      1'b1;
    assign ROM3ce_n = (BVMA == 1'b1 & Adr[12:11] == 2'b11) ? 1'b0 : 
                      1'b1;
    
    //	000 010 0000000000
    //		 011
    // 000 111 1111111111
    
    //ROM1ce_n <= '0' when VMA = '1' and Adr(12 downto 10) = "001" else '1';
    //ROM2ce_n <= '0' when VMA = '1' and Adr(12 downto 10) = "010" else '1';
    //ROM3ce_n <= '0' when VMA = '1' and Adr(12 downto 10) = "111" else '1';
    
    assign BVMA = VMA;		// and (not Adr(14));
    assign BA12nor11 = ~(Adr[12] | Adr[11]);
    assign SysEn = (BVMA & BA12nor11 & PHI2);
    assign RAMce = (Adr[11:8] == 4'b0000) ? 1'b1 : 
                   1'b0;
    //RAMce <= '1' when SysEn = '1' and Adr(11 downto 8) = "0000" else '0';
    //RAMwe <= '1' when RAMce = '1' and RW_n = '0' else '0';  -- AJS
    assign RAMwe = (RAMce == 1'b1 & RW_n == 1'b0) ? 1'b1 : 
                   1'b0;
    
    //J4_11
    assign IO_Wr = (SysEn & Legit & ((~RW_n)));
    //IO_Wr <= SysEn and Legit and R_nW ;
    
    // Memory map from MAME driver
    // FEDCBA9876543210           
    //	0000000000000000 - 0000000011111111	(0x0000, 0x00ff) AM_RAM
    //	0000000100000000							(0x0100, 0x0100) AM_MIRROR(0x001f) AM_WRITEONLY AM_SHARE("scroll_y")
    //	0000000100100000							(0x0120, 0x0120) AM_MIRROR(0x001f) AM_WRITEONLY AM_SHARE("scroll_x")
    //	0000000101000000							(0x0140, 0x0140) AM_MIRROR(0x001f) AM_WRITE(crash_reset_w)
    //	0000000101100000							(0x0160, 0x0160) AM_MIRROR(0x001f) AM_WRITE(firetrk_skid_reset_w)
    //	0000000110000000							(0x0180, 0x0180) AM_MIRROR(0x001f) AM_WRITEONLY AM_SHARE("car_rot")
    //	0000000110100000 							(0x01a0, 0x01a0) AM_MIRROR(0x001f) AM_WRITE(steer_reset_w)
    //	0000000111000000							(0x01c0, 0x01c0) AM_MIRROR(0x001f) AM_DEVWRITE("watchdog", watchdog_timer_device, reset_w)
    //	0000000111100000							(0x01e0, 0x01e0) AM_MIRROR(0x001f) AM_WRITE(blink_on_w) AM_SHARE("blink")
    //	0000001000000000 - 0000001000000111 (0x0200, 0x0207) AM_MIRROR(0x0018) AM_READ(firetrk_input_r)
    //	0000001000100000							(0x0220, 0x0220) AM_MIRROR(0x001f) AM_WRITE(firetrk_xtndply_w)
    //	0000001001000000 - 0000001001000011 (0x0240, 0x0243) AM_MIRROR(0x001c) AM_READ(firetrk_dip_r)
    //	0000001001100000 - 0000001001101111 (0x0260, 0x026f) AM_MIRROR(0x0010) AM_WRITE(superbug_output_w)
    //	0000001010000000 							(0x0280, 0x0280) AM_MIRROR(0x001f) AM_WRITE(superbug_motor_snd_w)
    //	0000001010100000							(0x02a0, 0x02a0) AM_MIRROR(0x001f) AM_WRITE(firetrk_crash_snd_w)
    //	0000001011000000							(0x02c0, 0x02c0) AM_MIRROR(0x001f) AM_WRITE(firetrk_skid_snd_w)
    //	0000010000000000 - 0000010000011111 (0x0400, 0x041f) AM_RAM AM_SHARE("alpha_num_ram")
    //	0000010100000000 - 0000010111111111 (0x0500, 0x05ff) AM_RAM AM_SHARE("playfield_ram")
    //	0000100000000000 - 0001111111111111 (0x0800, 0x1fff) AM_ROM
    //
    
    //	000 010 0000000000
    //		 011
    // 000 111 1111111111
    
    // Outputs
    assign MotorSnd_n = (IO_Wr == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b100) ? 1'b0 : 
                        1'b1;
    assign CrashSnd_n = (IO_Wr == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b101) ? 1'b0 : 
                        1'b1;
    assign SkidSnd_n = (IO_Wr == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b110) ? 1'b0 : 
                       1'b1;
    
    assign PHP_Load_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b000) ? 1'b0 : 
                        1'b1;
    assign PVP_Load_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b001) ? 1'b0 : 
                        1'b1;
    assign CrashReset_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b010) ? 1'b0 : 
                          1'b1;
    assign SkidReset_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b011) ? 1'b0 : 
                         1'b1;
    assign CarRot_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b100) ? 1'b0 : 
                      1'b1;
    assign SteerReset_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b101) ? 1'b0 : 
                          1'b1;
    assign WdogReset_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b110) ? 1'b0 : 
                         1'b1;
    assign ArrowOff_n = (IO_Wr == 1'b1 & Adr[10] == 1'b0 & Adr[8] == 1'b1 & Adr[7:5] == 3'b111) ? 1'b0 : 
                        1'b1;
    
    assign In1_n = (SysEn == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b000) ? 1'b0 : 
                   1'b1;
    assign Opt_n = (SysEn == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b010) ? 1'b0 : 
                   1'b1;
    assign Out2_n = (SysEn == 1'b1 & Adr[9] == 1'b1 & Adr[7:5] == 3'b011) ? 1'b0 : 
                    1'b1;
    // ASR (where does this go?)	-- Audio related
    
    
    always @(posedge Out2_n)
    begin: OutputLatch
        begin
            StartLamp <= Adr[0];
            TrakSelLamp <= Adr[3];
            Attract <= Adr[1];
            Flash <= Adr[2];
        end
    end
    
    // 74LS175 at C9
    //OutputLatch: process(Adr, Out2_n)
    //begin
    //       if (Reset='1') then
    //		StartLamp <= '0';
    //		TrakSelLamp <= '0';
    //		Attract <= '0';
    //		Flash <= '0';
    //        end if;
    //	if rising_edge(Out2_n) then
    //		StartLamp <= Adr(0);
    //		TrakSelLamp <= Adr(3);
    //		Attract <= Adr(1);
    //		Flash <= Adr(2);
    //	end if;
    //end process;
    
    // CPU data in mux
    assign CPU_Din = (ROM1ce_n == 1'b0 | ROM2ce_n == 1'b0 | ROM3ce_n == 1'b0) ? ROM_Dout : 
                     (RAMce == 1'b1 & RW_n == 1'b1) ? RAM_Dout : 
                     (In1_n == 1'b0 | Opt_n == 1'b0) ? DBus_in : 
                     8'hFF;
    
endmodule
