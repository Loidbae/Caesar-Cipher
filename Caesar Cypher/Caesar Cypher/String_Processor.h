#pragma once

/*Guidelines for this project (not sure if those are good ones need feedback on them)

	- If possible find rememberable and short names for your functions;
	- Don't spam your main() with output loops;
	- Always try to keep main() clean;
	- Member Variables of another class should be named after the act of getting / using something from them;
	- Documentation should be simply worded and in short sentences. if possible (clean and simple);

*/
// Code written by Loidbae, Github:https://github.com/Loidbae

#include <iostream>
#include <string>
#include "string.h"
#include"ArrayRuler.h"

class string_processor
{
public:
	string_processor()
	{
		use.ruler1 = 0;
	}
	//see String_Processor.cpp for dokumentation;
	void input_processor(std::string input);


	//setter, getter and all that jazz;
	char get_char_array(int i) const;
	void set_char_array(int i, char setmeto);
	int get_stringL()const;

private:
	//Class-Members
	arrayruler use;

	//Variables
	int stringL; // string Length;

	//arrays
	static constexpr int dex = 41;
	char brokenstring[dex];
};