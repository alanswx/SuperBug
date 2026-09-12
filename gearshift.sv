//============================================================================
//  gearshift
//
//  Turn gear-up and gear-down buttons into the switch pattern the game
//  expects. Three switches, active low and one hot for gears 1 to 3; fourth
//  gear is none of them closed.
//
//  Copyright (c) 2019 Alan Steremberg - alanswx
//
//============================================================================
module gearshift
(
	input  CLK,
	input  reset,

	input  gearup,
	input  geardown,

	output reg gear1,
	output reg gear2,
	output reg gear3
);

// The edge detection here used to be broken in a way that made every up-shift
// jump straight to fourth: the branch handling gear-down cleared the gear-up
// edge flag rather than its own, so while the gear-up button was held the flag
// was cleared again on every clock and a gear was counted on every clock. At
// six megahertz a single button press ran the counter to the top instantly.
// Selecting fourth gear from a standstill bogs the car down, so shifting up
// made the game slower rather than faster, and gear-down only ever worked once.

reg [1:0] gear = 2'd0;
reg       old_gearup = 1'b0;
reg       old_geardown = 1'b0;

always @(posedge CLK) begin
	old_gearup   <= gearup;
	old_geardown <= geardown;

	if (reset) begin
		gear <= 2'd0;
	end else if (gearup & ~old_gearup) begin
		if (gear != 2'd3) gear <= gear + 2'd1;
	end else if (geardown & ~old_geardown) begin
		if (gear != 2'd0) gear <= gear - 2'd1;
	end
end

always @(*) begin
	gear1 = ~(gear == 2'd0);
	gear2 = ~(gear == 2'd1);
	gear3 = ~(gear == 2'd2);
end

endmodule
