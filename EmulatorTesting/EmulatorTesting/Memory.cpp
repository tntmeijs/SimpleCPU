#include "Memory.hpp"

Memory::Memory()
	: MAX_ADDRESS(255)
	, m_memory(new byte[MAX_ADDRESS])
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

void Memory::write(const byte & p_address, const byte & p_value)
{
	m_memory[p_address] = p_value;
}
