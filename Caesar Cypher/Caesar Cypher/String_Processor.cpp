#include "pch.h"
#include "String_Processor.h"
#include <string>
#include "string.h"
#include <iostream>
#include <algorithm>

using namespace std;

void String_processor::string_convert(string & u_input)
{
	for(int i = 0; i < u_input.length(); i++)
	{
	
		brokenstring[i] = u_input[i];
	}

}

void String_processor::wsp_remover(string& u_input)const
{
	char whitespace (' ');
	size_t found = u_input.find(whitespace);

	if (found != string::npos)
	{
		u_input.erase(std::remove_if(u_input.begin(), u_input.end(), ::isspace), u_input.end());
	}

}

char String_processor::get_char_array(int index) const
{
	return brokenstring[index];
}

void String_processor::set_char_array(int i)
{
	brokenstring[i];
}
