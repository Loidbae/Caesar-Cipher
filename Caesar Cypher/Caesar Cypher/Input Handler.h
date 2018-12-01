
/*Guidelines for this project (not sure if those are good ones need feedback on them)

	- If possible find rememberable and short names for your functions;
	- Create a good and readable structure if it works, keep it, if not change it.
	- Member Variables of another class should be named after the act of getting / using something from that class;
	- Documentation should be simply worded and in short sentences. if possible (clean and simple);

*/// Code written by Loidbae, Github:https://github.com/Loidbae

#pragma once

#include <iostream>
#include <string>
#include "CounterStruct.h" 

class inputhandler
{
public:

	inputhandler()
	{
		 use.rE126 = 0;
		 use.rE33 = 0;
		 use.r126 = 0;
		 use.r33 = 0;
		 use.rKey = 0;
		 use.rOffset = 0;
		 use.rindex = 0;
	}

	void clearArrays();

	void prepare_brokeninput(std::string& userinput, std::string& keyinput, bool decrypting);
	void encrypter159();
	void keygen159();
	void decryption159();

	void set_offsets(int offsetproxy,int i);
	void set_keyholder(int keyinput,int i);
	void set_brokeninput(std::string& txtinput,int i);
	void set_newkey(int keyproxy,int i);

	int get_inputsL()const;
	char get_brokeninput(int i)const;
	int get_key(int i)const;

	int keysize;

private:
	counterstruct use;

	int rem_i = 0;
	int inputsL;

	static constexpr int dex = 299;

	char newkey[dex];
	int keyholder_de[dex];

	char brokeninput[dex];
	int remember32[dex]; // 32 -> ascii decimal for whitespace
	int offsets[dex];
	int onetwenty_c[dex]; // 120 was as text shorter than 126 
	int thirty_c[dex]; // same as above ^ but with 33
	int keyholder159[dex];

};
/*
	Rough concept of my cipher:
		
		- user inputs text
		- text gets broken up into chars and passed on to the char array
		- each and every character gets set off by the user
		- then, every offset will get added onto the decimals of each character from the put in text respectively
		
		- to generate a key we want to count every 126 subtraction and every 33 addition for each character
		- with those subtraction and addition counters and the offsets we then want to generate a key with a pattern which is instantly recognisable for the decrypter
		-

*/

// ---VVV THIS IS LEFTOVER DOCUMENTATION VVV---

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
