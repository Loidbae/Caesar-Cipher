#include "pch.h"
#include "String_Processor.h"
#include <string>
#include "string.h"
#include <iostream>
#include <algorithm>

using namespace std;



void String_processor::input_setup()
{
	//In this method I get the users input ask if any whitespaces are present and remove them if so
	//then I save the rest (the characters without whitespaces) to an array so that I can edit them later
	getline(cin, input);


	//removing whitespaces
	char whtspc(' ');

	size_t found = input.find(whtspc);

	if (found != string::npos)
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
	}

	//pasing the rest into an array
	for (int i = 0; i < (int)input.length(); i++)
	{
		brokenstring[i] = input[i];
	}

}

void String_processor::string_convert(string & input)
{
	for(int i = 0; i < (int)input.length(); i++)
	{
		brokenstring[i] = input[i];
	}
}

void String_processor::wsp_remover(string& input)const
{
	char whitespace (' ');
	size_t found = input.find(whitespace);

	if (found != string::npos)
	{
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
	}

}

char String_processor::get_char_array(int i) const
{
	return brokenstring[i];
}

void String_processor::set_char_array(int i)
{
	brokenstring[i];
}

std::string String_processor::get_input() const
{
	return input;
}
