#include "pch.h"
#include "Coder.h"
#include <string>
#include "string.h"
#include <iostream>

using namespace std;

int Coder::get_abc(int i) const
{
	return abc_offset[i];
}

void Coder::set_abc(int abcproxy, int i)
{
	abc_offset[i] = abcproxy;
}

char Coder::return_encode(int i) const
{
	return ascii_per_char[i];
}

void Coder::encode(string input, string_processor borrow)
{
	int ascii_new;

	for (int i = 0; i < (int)input.length(); i++)
	{
		ascii_per_char[i] = borrow.input_processor(input, i);
	}

	for (int i = 0; i < (int)input.length(); i++)
	{
		ascii_new = ascii_per_char[i] + abc_offset[i];

		while (ascii_new > 126 || ascii_new < 33)
		{
			if (ascii_new > 126)
			{
				ascii_new = ascii_new - 126;
			}
			else if (ascii_new < 33)
			{
				ascii_new = ascii_new + 33;
			}
		}
		ascii_per_char[i] = ascii_new;
	}
}

