module shiftaddmul(mpr, mpd, prd);
   input [23:0]  mpr, mpd;
   output [47:0] prd;
   integer i;
	reg [47:0] product;
	assign prd=product;
   always @(mpr or mpd)
     begin
        product = 0;  
        for(i=0; i<24; i=i+1)
          if( mpr[i] == 1'b1 ) product = product + ( mpd << i );
     end
endmodule