#pragma once

/*so it turns out that if you convert a character to an integer, it will actually convert to
the ascii table decimal number of that character. Yes this is pretty basic stuff and common
knowlage, but a step is a step.*/

/*So that means my encoder should look something like this:
new int array -then-> get [values of brokenstring array] which means very character will get
translated !@#? --> into their decimal assigned by the ascii table respectively.

After that we want to change each and every character by an offset put in by the user
so my idea would be to add the current character decimals and offsets together to get a new
decimal which then needs to be corrected to fit in the "useful" chracter range of the table.

To give you an example what I am talking about:

			char ex = 'a'
			// a is 97
			int offset = 1;
			int new_char;

			new_char=offset+(int)ex;

			cout << new_char;
			output would be 'b' because 97 + 1 = 98 = 'b' in the table
*/

/*Guidelines for this project (not sure if those are good ones need feedback on that)

	- If possible find rememberable and short names for your functions;
	- Don't spam your main() with output loops;
	- Always try to keep main() clean;
	- Documentation should be simply worded in short sentences, if possible;

*/
// Code written by Loidbae, Github:https://github.com/Loidbae

#include "String_Processor.h"
#include <string>
#include "string.h"
#include <iostream>

// 159 because my encryption range is ascii 33 to 126

class Coder
{

public:

	void encoder159(std::string input, string_processor borrow);
	void decoder159(std::string input, string_processor borrow);
	void keygen159();
	

	int get_abc(int i)const;
	void set_abc(int abcproxy, int i);

private:

	static constexpr int dex = 41;

	int ascii_per_char[dex];
	int abc_offset[dex];

	//counters *see gen_key in Coder.cpp for more infos.
	int thirty_c[dex];
	int onetwenty_c[dex];
};

