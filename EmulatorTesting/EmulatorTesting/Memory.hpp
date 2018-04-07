#pragma once

using byte = unsigned char;

enum class OpCode : byte
{
	HLT = 1 << 0,	// 0000 0000	Halt the processor

	MOV = 1 << 1,	// 0000 0001	Copies the data from register zero to register one
	ADD = 1 << 2,	// 0000 0010	Adds register zero and register one and stores the result in register zero
	SUB = 1 << 3,	// 0000 0100	Subtracts register zero from register one and stores the result in register zero
	JMP = 1 << 4,	// 0000 1000	Jumps to the specified memory address

	STO = 1 << 5,	// 0001 0000	Stores the data specified in register zero
	INC = 1 << 6,	// 0010 0000	Increments the current register value
	PRT = 1 << 7,	// 0100 0000	Print the value of the specified byte in memory
};

class Memory
{
public:
	Memory();
	~Memory();

	// Resets every bit to zero
	void clearMemory();

	// Return the byte at this address
	const byte & read(const byte & p_address);

	// Return the instruction pointer
	const byte & getInstructionPointer() const;

	// Set the byte at this address
	void write(const byte & p_address, const byte & p_value);

	// Advance the instruction pointer by two bytes
	void nextInstruction();

	// Sets an op-code
	void setInstruction(OpCode opCode);

	// Sets an op-code and some data
	void setInstruction(OpCode opCode, byte data);

	// Sets the instruction pointer to a specific address
	void setInstructionPointer(const byte & p_address);

	// Maximum address we can read from
	const byte MAX_ADDRESS;

private:
	// Memory to work with
	byte * m_memory;

	// Keeps track of the current position in memory
	// Starts at memory index two since zero will trigger HALT
	byte m_instructionPointer;
};