#pragma once

#include <iostream>
#include <string>
#include "string.h"

class String_processor
{
public:
	
	void input_setup();
	void string_convert(std::string& u_input);
	void wsp_remover(std::string& u_input)const;
	char get_char_array(int i) const;
	void set_char_array(int i);
	std::string get_input()const;

	

private:
	std::string input;
	static constexpr int dex = 41;
	char brokenstring[dex];
};