#include "Memory.hpp"

Memory::Memory()
	: MAX_ADDRESS(255)
	, m_memory(new byte[MAX_ADDRESS])
	, m_instructionPointer(2)
{
	clearMemory();
}

Memory::~Memory()
{
	if (m_memory)
	{
		delete[] m_memory;
		m_memory = nullptr;
	}
}

void Memory::clearMemory()
{
	for (byte b = 0; b < MAX_ADDRESS; ++b)
		m_memory[b] = 0;
}

const byte & Memory::read(const byte & p_address)
{
	return m_memory[p_address];
}

const byte & Memory::getInstructionPointer() const
{
	return m_instructionPointer;
}

void Memory::write(const byte & p_address, const byte & p_value)
{
	m_memory[p_address] = p_value;
}

void Memory::nextInstruction()
{
	// Do not read past the maximum memory range
	if (m_instructionPointer >= MAX_ADDRESS - 1)
	{
		// HALT the processor by pointing to position zero
		m_instructionPointer = 0;
		return;
	}

	// Advance the instruction pointer by two bytes (using two byte instruction encoding)
	m_instructionPointer += 2;
}

void Memory::setInstruction(OpCode opCode)
{
	write(m_instructionPointer + 0, static_cast<byte>(opCode));

	nextInstruction();
}

void Memory::setInstruction(OpCode opCode, byte data)
{
	write(m_instructionPointer + 0, static_cast<byte>(opCode));
	write(m_instructionPointer + 1, data);

	nextInstruction();
}

void Memory::setInstructionPointer(const byte & p_address)
{
	m_instructionPointer = p_address;
}
