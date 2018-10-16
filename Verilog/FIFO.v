`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:06:48 12/22/2015 
// Design Name: 
// Module Name:    FIFO 
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
//////////////////////////////////////////////////////////////////////////////////
module FIFO(Clk, Reset, DataIn, W, FULL, DataOut, R, Empty, Count);


input 			Clk;
input 			Reset;
input [15:0] 	DataIn;
input 			W;
output 			FULL;
output	[7:0]	DataOut;
input				R;
output			Empty;
output reg [10:0]	Count;

reg 	[9:0]		WPointer;
reg 	[9:0]		RPointer;


My_FIFO_mem your_instance_name (
  .clka(Clk), // input clka
  .wea(W && (!FULL)), // input [0 : 0] wea
  .addra(WPointer), // input [9 : 0] addra
  .dina(DataIn), // input [7 : 0] dina
  .clkb(Clk), // input clkb
  .addrb(RPointer), // input [9 : 0] addrb
  .doutb(DataOut) // output [7 : 0] doutb
);

always @ (posedge Clk or posedge Reset)
	if (Reset) begin
		WPointer <= 0;
		RPointer <= 0;
		end
	else begin
	if (W && (!FULL))
		WPointer <= WPointer + 1;
	if (R && (!Empty))
		RPointer <= RPointer + 1;
	end

always @ (posedge Clk or posedge Reset)
	if (Reset) 
		Count <= 0;
	else 
	if (W && (!FULL) && R && (!Empty))
		Count <= Count;
	else if (W && (!FULL))
		Count <= Count + 1;
	else if (R && (!Empty))
		Count <= Count - 1;
	else  
		Count <= Count;
		
assign FULL = (Count==255);
assign Empty = (Count ==0);

	

endmodule
