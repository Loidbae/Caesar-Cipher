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

void Coder::translate_to_ascii(string input, string_processor borrow)
{
	int ascii_new;

	for (int i = 0; i < (int)input.length(); i++)
	{
		ascii_per_char[i] = borrow.input_setup(input, i);
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

//void Coder::test()
//{
//	int ascii_new;
//	//what I do here is reading the content of the "brokenstring" array from String_processor.h
//	//into the int array so that every character gets translatet to a decimal number
//	for (int i = 0; i < (int)input.length(); i++)
//	{
//		ascii_per_char[i] = borrow.get_char_array(i);
//	}
//	/*then I take those decimal values and add them with the offsets on the exact same
//	array position as the abc offset array so that every character gets replaced by the
//	number they where assignt to*/
//
//	/*If the offset exeeds 126 (which is the end of the ascii table) then */
//
//	for (int i = 0; i < (int)input.length(); i++)
//	{
//		ascii_new = ascii_per_char[i] + abc_offset[i]; // new ascii symbol = offset + current ascii
//
//		if (ascii_new < 127 && ascii_new > 32)
//		{
//			ascii_per_char[i] = ascii_new;
//		}
//		else if (ascii_new > 126)
//		{
//			while (ascii_new > 126)
//			{
//				ascii_new = ascii_new - 126;
//			}
//
//			if (ascii_new < 33)
//			{
//				while (ascii_new < 33)
//				{
//					ascii_new = ascii_new + 33;
//				}
//
//			}
//			ascii_per_char[i] = ascii_new;
//		}
//
//
//	}
//
//}


