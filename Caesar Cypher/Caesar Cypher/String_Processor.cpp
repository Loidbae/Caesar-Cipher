#include "pch.h"
#include "string_Processor.h"
#include <string>
#include "string.h"
#include <iostream>
#include <algorithm>

using namespace std;



char string_processor::input_processor(string input,int index)
{
	/*This method processes the users input, by removing all whitespaces from the string
	and saving the rest to an seperate array*/


	//removing whitespaces
	char whtspc(' ');

	size_t found = input.find(whtspc);

	if (found != string::npos)
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
	}

	//passing the rest onto the char-array
	for (int i = 0; i < (int)input.length(); i++)
	{
		brokenstring[i] = input[i];
	}

	return brokenstring[index];

}

char string_processor::get_char_array(int i) const
{
	return brokenstring[i];
}

void string_processor::set_char_array(int i, char setme)
{
	brokenstring[i];
}
