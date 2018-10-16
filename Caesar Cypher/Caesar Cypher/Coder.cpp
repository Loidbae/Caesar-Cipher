#include "pch.h"
#include "Coder.h"
#include <string>
#include "string.h"

using namespace std;

int Coder::get_abc(int i) const
{
	return abc_offset[i];
}

void Coder::set_abc(int abcproxy, int i)
{
	abc_offset[i] = abcproxy;
}

void Coder::translate_to_ascii()
{

	//what I do here is reading the content of the "brokenstring" array from String_processor.h
	//into the int array so that every character gets translatet to a decimal number
	for (int i = 0; i < (int)borrow.get_input().length(); i++)
	{
		ascii_per_char[i] = borrow.get_char_array(i);
	}
	/*then I take those decimal values and add them with the offsets on the exact same
	array position as the abc offset array so that every character gets replaced by the
	number they where assignt to*/
	for (int i = 0; i < (int)borrow.get_input().length(); i++)
	{
		ascii_per_char[i] = ascii_per_char[i] + abc_offset[i];
	}
}


