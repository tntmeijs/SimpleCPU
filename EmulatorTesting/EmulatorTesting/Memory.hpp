#pragma once

using byte = unsigned char;

class Memory
{
public:
	Memory();
	~Memory();

	// Resets every bit to zero
	void clearMemory();

	// Return the byte at this address
	const byte & read(const byte & p_address);

	// Set the byte at this address
	void write(const byte & p_address, const byte & p_value);

	// Maximum address we can read from
	const byte MAX_ADDRESS;

private:
	// Memory to work with
	byte * m_memory;
};