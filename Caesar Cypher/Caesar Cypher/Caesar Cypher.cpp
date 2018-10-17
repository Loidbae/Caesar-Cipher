
#include "pch.h"
#include <iostream>
#include <string>
#include "string.h"
#include "String_Processor.h"
#include "Coder.h"

using namespace std;

int main()
{
	//--Member variables call zone--//
	string input;
	string_processor call;
	Coder run;
	//------------------------------//

	//--Assign zone--//
	int abcproxy;

	//---------------//

	cout << "Enter text to encode (max 40 characters whitespaces included)"<< endl;

	getline(cin, input);


	cout << "Offset every character" << endl;

	
	for (int i = 0; i < (int)input.length(); i++)
	{
		cout << call.input_setup(input, i) << " by ";
		cin >> abcproxy;
		run.set_abc(abcproxy,i);
	}

	run.translate_to_ascii(input, call);

	for (int i = 0; i < (int)input.length(); i++)
	{
		cout << run.return_encode(i);
	}
	
	cout << endl;
	
	//test
	/*char a = 'a';
	cout << a << endl;
	a = 98;
	cout << a << endl;*/
	/*success as I thought giving the char 'a', a decimal number of another character in the ascii table
	changes the output of the char into that specific character.*/

	/*So that means my encoder should look something like this:
	new int array -then-> get [values of brokenstring array] which means very character will get
	translated !@#? --> into their decimal assigned by the ascii table respectively.

	After I did that we want to change each and every character by an offset put in by the user
	so my idea would be putting current character decimals and offsets together so that we have the new
	decimals after the offset
	
	for example:
	
				char ex = 'a'
				// a is 97
				int offset = 1;
				int new_char;
				
				new_char=offset+(int)ex;

				cout << new_char;
				output would be 'b' because 97 + 1 = 98 = 'b' in the table
	*/


	//String output but as char array
	
	
}

