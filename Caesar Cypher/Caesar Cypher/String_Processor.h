#pragma once

#include <iostream>
#include <string>
#include "string.h"

class String_processor
{
public:

	void string_convert(std::string& u_input);
	void wsp_remover(std::string& u_input);
	char get_char_array(int index) const;

	

private:
	static constexpr int dex = 40;
	char brokenstring[dex];
};