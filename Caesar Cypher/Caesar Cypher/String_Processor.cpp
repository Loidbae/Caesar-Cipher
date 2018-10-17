#include "pch.h"
#include "string_Processor.h"
#include <string>
#include "string.h"
#include <iostream>
#include <algorithm>

using namespace std;



char string_processor::input_setup(string input,int index)
{
	//In this method I get the users input ask if any whitespaces are present and remove them if so
	//then I save the rest (the characters without whitespaces) to an array so that I can edit them later


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
