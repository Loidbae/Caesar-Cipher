#pragma once

/*Guidelines for this project (not sure if those are good ones need feedback on that)

	- If possible find rememberable and short names for your functions;
	- Don't spam your main() with output loops;
	- Always try to keep main() clean;
	- Documentation should be simply worded in short sentences, if possible;

*/
// Code written by Loidbae, Github:https://github.com/Loidbae

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