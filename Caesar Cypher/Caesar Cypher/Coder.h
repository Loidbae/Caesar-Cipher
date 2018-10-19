#pragma once

#include "String_Processor.h"
#include <string>
#include "string.h"
#include <iostream>

// 159 because my encryption range is ascii 33 to 126

class Coder
{

public:

	char encoder159(std::string input, string_processor borrow, int index);
	void keygen159();
	void decoder159(std::string input, string_processor borrow);

	int get_abc(int i)const;
	void set_abc(int abcproxy, int i);

private:

	static constexpr int dex = 41;

	int ascii_per_char[dex];
	int abc_offset[dex];

	//counter *see gen_key in Coder.cpp for more infos.
	int thirty_c[dex];
	int onetwenty_c[dex];
};

