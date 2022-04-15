// Video mixer for Atari/Kee Games Super Bug 
// This combines the various video signals from the playfield, car generator and sync
// circuits into a composite video signal.
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

module mixer(
    Clk6,
    HSync,
    VSync,
    HBlank_n,
    VBlank_n,
    PCC1,
    PCC2,
    PFWndo,
    Flash,
    Pfld,
    CarVideo,
    A_NVideo,
    CSync,
    Video1,
    Video2
);
    input     Clk6;
    input     HSync;
    input     VSync;
    input     HBlank_n;
    input     VBlank_n;
    input     PCC1;
    input     PCC2;
    input     PFWndo;		// Playfield Window
    input     Flash;
    input     Pfld;		// Playfield video
    input     CarVideo;		// Player car video 
    input     A_NVideo;		// Alpha-Numerics video
    output    CSync;
    output    Video1;
    output    Video2;
    
    
    wire      CompSync;
    wire      CompBlank;
    
    wire      FlashWndo;
    wire      PCC1Pfld;
    wire      PCC2Pfld;
    wire      CarPfld1;
    wire      CarPfld2;
    wire      CarPfWndo1;
    wire      CarPfWndo2;
    wire      CarPfAN1;
    wire      CarPfAN2;
    wire      CompVid1;
    wire      CompVid2;
    reg [2:0] VideoLatch;
    
    //K8
    assign CompSync = (~(HSync | VSync));
    //L8
    assign CompBlank = (~(HBlank_n & VBlank_n));
    //B9
    assign FlashWndo = (~(PFWndo & Flash));
    //H8
    assign PCC1Pfld = (PCC1 & Pfld);
    assign PCC2Pfld = (PCC2 & Pfld);
    //J8(1)
    assign CarPfld1 = (~(CarVideo | PCC1Pfld));
    assign CarPfld2 = (~(CarVideo | PCC2Pfld));
    //J9
    assign CarPfWndo1 = (CarPfld1 ^ FlashWndo);
    assign CarPfWndo2 = (CarPfld2 ^ FlashWndo);
    //J8(2)
    assign CarPfAN1 = (~(CarPfWndo1 | A_NVideo));
    assign CarPfAN2 = (~(CarPfWndo2 | A_NVideo));
    //K8
    assign CompVid1 = (~(CarPfAN1 | CompBlank));
    assign CompVid2 = (~(CarPfAN2 | CompBlank));
    
    //74LS175 DFF registers video output signals to 6MHz clock
    
    always @(posedge Clk6 )
    begin: K9
        
            VideoLatch <= ({CompVid1, CompVid2, CompSync});
    end
    assign Video1 = VideoLatch[2];
    assign Video2 = VideoLatch[1];
    assign CSync = VideoLatch[0];
    
endmodule
