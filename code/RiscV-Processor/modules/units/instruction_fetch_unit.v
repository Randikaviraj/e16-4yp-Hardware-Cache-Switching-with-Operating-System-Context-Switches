
module instruction_fetch_unit (
    input [31:0] branch_jump_addres,
    input branch_or_jump_signal,
    input data_memory_busywait,
    input reset,
    input clock,
    output reg [31:0] PC,INCREMENTED_PC_by_four,
    output [31:0]instruction,
    output busywait
);
wire [31:0]mux6out;
wire instruction_mem_busywait;

or(busywait,instruction_mem_busywait,data_memory_busywait);
mux2x1 mux6(INCREMENTED_PC_by_four,branch_jump_addres,branch_or_jump_signal,mux6out);
icache myicache(clock,reset,PC,instruction,instruction_mem_busywait);

/*
always @(posedge reset) begin //set the pc value depend on the RESET to start the programme
    PC= -4;
end
*/

always @(*) begin
    INCREMENTED_PC_by_four <=PC+4;
end

always @(posedge clock,posedge reset) begin //update the pc value depend on the positive clock edge

	if(reset)begin
		PC <= -4;
	 end
    else if(busywait == 1'b0)begin //update the pc when only busywait is zero 
        PC <= mux6out;
    end
end  
    
endmodule


/*
    addi x1 , x0,   1000       x1  = 1000 0x3E8 
    addi x2 , x1,   2000   x2  = 3000 0xBB8 
    sw      x1, 0x100(x0)
    lw      x3, 0x104(x0)
*/