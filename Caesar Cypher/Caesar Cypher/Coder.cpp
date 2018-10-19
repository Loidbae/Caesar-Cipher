#include "pch.h"
#include "Coder.h"
#include <string>
#include "string.h"
#include <iostream>
#include <math.h>

using namespace std;

int Coder::get_abc(int i) const
{
	return abc_offset[i];
}

void Coder::set_abc(int abcproxy, int i)
{
	abc_offset[i] = abcproxy;
}

char Coder::encoder159(string input, string_processor borrow, int index)
{
	/*this function converts every character into their decimal counterpart and "corrects" them
	into the ascii range after that it gets converted to char and output as text*/

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
	
		return ascii_per_char[index];
}

void Coder::keygen159()
{
	/*The Idea behind this function is to take the offset values and translate them into ascii by
	correcting their values into the ascii range, so that I can return them as a character to finally
	generate the "key" this key will then be read by the decoder who will then know by the format of 
	the key how to decrypt the encrypted message*/

	int save_original[dex];
	int temp_offset;
	
	int temp_c126 = 0;
	int temp_c33 = 0;

	for (int i = 0; i < sizeof(abc_offset[dex]); i++)
	{
		save_original[i] = abc_offset[i]; //to save the original offsets for later.

		temp_offset = abc_offset[i];

		while (temp_offset > 126 || temp_offset < 33)
		{
			//minus 126 and increase counter.
			if (temp_offset > 126)
			{
				temp_offset = temp_offset - 126;
				temp_c126 = temp_c126 +1;

			}//plus 33 and increase counter.
			else if (temp_offset < 33)
			{
				temp_offset = temp_offset + 33;
				temp_c33 ++;
			}
		}
		onetwenty_c[i] = temp_c126;
		thirty_c[i] = temp_c33;
		abc_offset[i] = temp_offset;
	}
	for (int i = 0; i < sizeof(abc_offset[dex]); i++)
	{
		cout << abc_offset[i];

		if (i / 3)
		{
			cout << onetwenty_c[i];
		}
		else if (i / 5)
		{
			cout << thirty_c[i];
		}
	}
}

void Coder::decoder159(std::string input, string_processor borrow)
{
	for (int i = 0; i < (int)input.length(); i++)
	{

	}

	for (int i = 0; i < (int)input.length(); i++)
	{

	}
}

