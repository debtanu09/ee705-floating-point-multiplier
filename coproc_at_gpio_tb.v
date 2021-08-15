`timescale 1ns/1ps
module coproc_at_gpio_tb;

reg [31:0] inp0, inp1;
wire [31:0] coproc_result;
wire coproc_result_ready;

coproc_at_gpio multi(inp0, inp1, coproc_result, coproc_result_ready);
initial begin
	inp0 = 32'b01000000110111110101110000101001; // 6.98
	inp1 = 32'b11000010100111011101000111101100; // -78.91
	#100;
end

endmodule