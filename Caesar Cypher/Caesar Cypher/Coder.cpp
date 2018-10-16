#include "pch.h"
#include "Coder.h"
#include <string>
#include "string.h"

using namespace std;

int Coder::get_abc() const
{
	return abc_offset;
}

void Coder::set_abc(int abcproxy)
{
	abc_offset = abcproxy;
}

int Coder::get_ascii(string& u_input)
{
	for (int i = 0; i < (int)u_input.length(); i++)
	{
		return ascii_per_char[i] = borrow.get_char_array(i);
	}
	
}


