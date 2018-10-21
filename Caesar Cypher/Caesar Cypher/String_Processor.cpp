#include "pch.h"
#include <string>
#include <iostream>
#include <algorithm>
#include "string_Processor.h"

using namespace std;

void string_processor::input_processor(string input)
{
	/*This function processes the users input, by removing all whitespaces from the string
	and saving the rest to an seperate array*/


	//removing whitespaces;
	char whtspc(' ');

	size_t found = input.find(whtspc);

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
