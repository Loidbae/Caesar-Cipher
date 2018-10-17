#pragma once

#include "String_Processor.h"
#include <string>
#include "string.h"
#include <iostream>

class Coder
{

public:
	int get_abc(int i)const;
	void set_abc(int abcproxy, int i);
	char return_encode(int i)const;
	void encode(std::string input, string_processor borrow);

	//Caesars_Decoder


private:
	string_processor borrow;
	static constexpr int dex = 41;
	int ascii_per_char[dex];
	int abc_offset[dex];

};

