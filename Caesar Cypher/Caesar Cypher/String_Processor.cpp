#include "pch.h"
#include <string>
#include <iostream>
#include <algorithm>
#include "string_Processor.h"

using namespace std;

void string_processor::input_processor(string input)
{
	/*This function processes the users text input, by removing all whitespaces from the string
	and saving the rest to an seperate array*/


	/*but before removing the whitespaces, we want to remember where they are
	for later*/

	/*I would like to apologize in advance for my method and say that I have actually no idea how
	to do this fucking micky mouse job in any other way*/

	string stm = input; // stm = short term memory;

	for (int i = 0; i < (int)input.length(); i++)
	{
		brokenstring[i] = input[i];
	}

	int i_r = 0;  //this only exists so that remember32s array gets filled at 0 and not when the first whitespace hits

	for (int i = 0; i < (int)input.length(); i++)
	{

		if (brokenstring[i] == 32)
		{
			remember32[i_r] = input.find(' ');
			brokenstring[i] = 68;
			input = brokenstring;
			i_r++;
		}
		if (brokenstring[i] == 'Ì')//backdoor to get out of the infinite loop lol, Ì is the not assigned space;
		{
			input = stm;
			for (int i = 0; i < (int)input.length(); i++)
			{
				brokenstring[i] = 'Ì'; //getting rid of the mess left by this method
			}
		}
	}

	//removing whitespaces;

	size_t found = input.find(' ');

	if (found != string::npos)
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
	}

	//passing the rest onto the char-array as described earlier;
	for (int i = 0; i < (int)input.length(); i++)
	{
		brokenstring[i] = input[i];
		use.ruler1++;
	}

	stringL = use.ruler1;


}

char string_processor::get_char_array(int i) const
{
	return brokenstring[i];
}

void string_processor::set_char_array(int i, char setmeto)
{
	brokenstring[i];
}

int string_processor::get_stringL() const
{
	return stringL;
}
