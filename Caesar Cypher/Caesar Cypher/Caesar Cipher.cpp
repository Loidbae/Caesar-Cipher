
/*Guidelines for this project (not sure if those are good ones need feedback on them)

	- If possible find rememberable and short names for your functions;
	- Create a good and readable structure if it works, keep it, if not change it.
	- Member Variables of another class should be named after the act of getting / using something from that class;
	- Documentation should be simply worded and in short sentences. if possible (clean and simple);

*/// Code written by Loidbae, Github:https://github.com/Loidbae

#include "pch.h"
#include <iostream>
#include <string>
#include "Input Handler.h"

using namespace std;

int main()
{
	//--Class Member Zone--//
	string txtinput;
	inputhandler execute;
	//---------------------//

	//--Assignment Zone--//
	int abcproxy;
	//-------------------//
	
	//gets the users input as string
	cout << "Enter text to encode (max 15 characters whitespaces excluded)" << endl;
	getline(cin, txtinput);

	// removes whitespaces
	execute.prepare_brokeninput(txtinput);

	//gets offsets
	cout << "Offset every character" << endl;
	for (int i = 0; i < execute.get_inputsL(); i++)
	{
		cout << execute.get_brokeninput(i) << " by ";
		cin >> abcproxy;
		execute.set_offsets(abcproxy, i);
	}

	// bad don't know why
	system("cls");

	//encrypts users input
	execute.encrypter159();

	cout << "Your Text: " << endl;
	for (int i = 0; i < execute.get_inputsL(); i++)
	{
		cout << execute.get_brokeninput(i);
	}
	cout << endl;

	//generates key for decrypting later on, not happy with the lenght of the key (soon)
	execute.keygen159();

	cout << "Your Decryption Key: ";
	for (int i = 0; i <= execute.keysize ; i++)
	{
		cout << execute.get_key(i);
		if (i != execute.keysize)
		{
			cout<< "-";
		}
	}

}

/*
	_______[what I had to reuse and/or relearn]_______

	- Classes and class members and their  variables
	- Constructor
	- String
	- I/O
	- Const
	- Reference but only &
	- Struct
	- Getter setter
	- Arrays
	- Static constexpr
	- 

	_____________[What I want to do/learn]_____________

	- File reading / writing
	- Reference *
	- Classes inside classes (if necessary/possible)
	- 2D arrays
	- What function to use as a tool /formular functions I call these
	-

*/

/*
------------[To-Do's]------------

	- complete keygen and decrypter

*/

/*

Bug list
------------------

- too much txtinput throws an exception in Code.cpp at line 51;

- the user can actually txtinput whatever they want, where ever they want;

- Runtime check failure #2 stack around the variable 'call' was corrupted; I think I fixed it but lets keep it if it happens again;

- second getline won't work for some reason. The whole second Input phase seems to be broken; (fixed)












*/
