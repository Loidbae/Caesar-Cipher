
/*Guidelines for this project (not sure if those are good ones need feedback on them)

	- If possible find rememberable and short names for your functions;
	- Don't spam your main() with output loops;
	- Always try to keep main() clean;
	- Member Variables of another class should be named after the act of getting / using something from them;
	- Documentation should be simply worded and in short sentences. if possible (clean and simple);

*/
// Code written by Loidbae, Github:https://github.com/Loidbae

#include "pch.h"
#include <iostream>
#include <string>
#include "String_Processor.h"
#include "Coder.h"

using namespace std;

int main()
{
	//--Class Member Zone--//
	string input;
	string_processor call;
	Coder run;
	//----------- ---------//

	//--Assignment Zone--//
	int abcproxy;
	//-------------------//
	

	//user string input
	cout << "Enter text to encode (max 40 characters whitespaces included)" << endl;
	getline(cin, input);

	//Breaks string into char array;
	call.input_processor(input);

	//offset values input
	cout << "Offset every character" << endl;
	for (int i = 0; i < call.get_stringL(); i++)
	{
		cout << call.get_char_array(i) << " by ";
		cin >> abcproxy;
		run.set_abc(abcproxy, i);
	}

	system("cls");//read that I shouldn't be doing this, need clarification on why though.

	cout << "Your Text: " << endl;

	//this function actually does all the work, but gets zero attention for it :( poor guy
	run.encoder159(input, call);


	cout << "Your Decryption Key: ";
	run.keygen159();//decryption key gets generated
	cout << endl;

	
	
}

/*
Bug list
------------------

- too much input throws an exception in Code.cpp at line 51;

- the user can actually input whatever they want, where ever they want;

- Runtime check failure #2 stack around the variable 'call' was corrupted; I think I fixed it but lets keep it if it happens again;














*/
