#pragma once

#include <iostream>
#include <string>
#include "string.h"

class string_processor
{
public:
	
	char input_processor(std::string input, int index);


	//setter getter and all that jazz
	char get_char_array(int i) const;
	void set_char_array(int i, char setme);

private:

	static constexpr int dex = 41;
	char brokenstring[dex];
};