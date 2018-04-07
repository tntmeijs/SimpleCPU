#include <iostream>

#include "Memory.hpp"

Memory ram;
bool halt = false;

byte register0 = 0;
byte register1 = 0;

void loadProgram()
{
	// Simple assembly program that computes 10 + 9 = 19:
	ram.setInstruction(OpCode::STO, 10);	// Store the value 10 in register zero
	ram.setInstruction(OpCode::MOV);		// Move the value of register zero to register one
	ram.setInstruction(OpCode::STO, 9);		// Store the value 9 in register zero
	ram.setInstruction(OpCode::ADD, 0);		// Add register zero to register one and store the result in register zero
	ram.setInstruction(OpCode::PRT, 0);		// Print the contents of register zero
	ram.setInstruction(OpCode::HLT);		// Exit the program
}

void fetchInstruction()
{
	// Two byte instructions, one op-code and some data associated with that op-code
	byte opCode = ram.read(ram.getInstructionPointer() + 0);
	byte data	= ram.read(ram.getInstructionPointer() + 1);

	switch (opCode)
	{
	case static_cast<byte>(OpCode::HLT) :
		halt = true;
		break;

	case static_cast<byte>(OpCode::MOV) :
		register1 = register0;
		register0 = 0;
		break;

	case static_cast<byte>(OpCode::ADD) :
		if (data == 0)
			register0 = register0 + register1;
		else
			register1 = register0 + register1;
		break;

	case static_cast<byte>(OpCode::SUB) :
		if (data == 0)
			register0 = register1 - register0;
		else
			register1 = register1 - register0;
		break;

	case static_cast<byte>(OpCode::JMP) :
		ram.setInstructionPointer(data);
		break;

	case static_cast<byte>(OpCode::STO) :
		register0 = data;
		break;

	case static_cast<byte>(OpCode::INC) :
		ram.write(ram.getInstructionPointer() + 1, data + 1);
		break;

	case static_cast<byte>(OpCode::PRT) :
		// Casting to an integer because C++ cannot print bytes (unsigned char)
		// It would just give a garbage value, hence the cast to an integer
		std::cout << "Virtual CPU result:\t" << static_cast<int>((data == 0) ? register0 : register1) << "." << std::endl;
		break;
	}
}

int main()
{
	loadProgram();

	while (!halt)
	{
		fetchInstruction();
		ram.nextInstruction();
	}

	std::cout << "\nProgram has halted, press 'Enter' to quit..." << std::endl;
	std::cin.get();

	return 0;
}