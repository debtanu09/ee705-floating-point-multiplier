`timescale 1ns/1ps
module coproc_at_gpio(inp0,inp1,coproc_result,coproc_result_ready);

input [31:0] inp0, inp1;
output [31:0] coproc_result;
output coproc_result_ready;
wire [23:0] mpr, mpd;
wire [47:0] prd;
reg [22:0] mantissa;
reg [8:0] exponent;
wire [7:0] aexponent, bexponent;
wire norm_check;

shiftaddmul multiplier(mpr, mpd, prd);


assign coproc_result[31] = inp0[31] ^ inp1[31];
assign mpr = {1'b1, inp0[22:0]};
assign mpd = {1'b1, inp1[22:0]};
assign coproc_result[22:0] = mantissa;
assign coproc_result[30:23] = exponent[7:0];
assign norm_check = prd[47];
assign aexponent = inp0[30:23];
assign bexponent = inp1[30:23];
assign coproc_result_ready = 1'b1; 

always @(inp0, inp1, prd, aexponent, bexponent, norm_check) begin
	if(norm_check == 1'b1) begin
		exponent = aexponent + bexponent - 8'd126; // for normalization
		if(prd[23:22] == 2'd3) begin //for rounding off
		mantissa = prd[46:24];
		mantissa = mantissa + 23'd1;
		end
		else mantissa = prd[46:24];
	end
	else begin
		exponent = aexponent + bexponent - 8'd127; //for rounding off
		if(prd[22:21] == 2'd3) begin
		mantissa = prd[45:23];
		mantissa = mantissa + 23'd1;
		end
		else mantissa = prd[45:23];
	end
end
endmodule