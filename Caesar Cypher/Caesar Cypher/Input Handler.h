
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

	void dispose_leftovers();

	void prepare_encryption(std::string& userinput);
	void prepare_decryption();
	void encrypter159();
	void keygen159();
	void decryption159();

	void set_offsets(int offsetproxy,int i);
	void set_keyholder(int keyinput,int i);
	void set_entxt(std::string& txtinput, int i);
	void set_brokeninput(std::string& txtinput,int i);
	void set_keyholder_de(int keyproxy,int i);

	int get_input_size()const;
	char get_brokeninput(int i)const;
	int get_key(int i)const;
	char get_entxt(int i)const;
	int get_key_size()const;
	
	void algo_sort(int array_a[],int array_a_length,int array_b[]);
	void algo_sort(int array_a[], int array_a_length, char array_b[]);
	

private:
	counterstruct use;

	int rem_i = 0;
	int input_size;
	int key_size;

	static constexpr int dex = 299;

	char entxt[dex];
	int keyholder_de[dex];

	char brokeninput[dex];
	int remember32[dex];
	int offsets[dex];
	int onetwenty_c[dex];
	int thirty_c[dex]; 
	int keyholder159[dex];

};
/*
	Rough concept of my cipher:
		
		- user inputs text
		- text gets broken up into chars and passed onto the char array (brokeninput)
		- each and every character gets set off by the user
		- then, every offset will get added onto the decimals of each character from the put in text respectively
		
		- to generate a key we want to count every 126 subtraction and every 33 addition for each character
		- with those subtraction and addition counters and the offsets we then want to generate a key with a pattern which is instantly recognisable for the decrypter

*/