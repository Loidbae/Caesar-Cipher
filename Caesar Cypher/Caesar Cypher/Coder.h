#pragma once

#include "String_Processor.h"
#include <string>
#include "string.h"

class Coder
{

public:
	int get_abc()const;
	void set_abc(int abcproxy);
	int get_ascii(std::string& u_input);
	//Caesars_Encoder
	//Caesars_Decoder


private:
	String_processor borrow;
	static constexpr int dex = 41;
	int ascii_per_char[dex];
	int abc_offset; //should be array

};

