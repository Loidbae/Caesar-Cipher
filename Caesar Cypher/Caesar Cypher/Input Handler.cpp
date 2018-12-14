#include "pch.h"
#include "Input Handler.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void inputhandler::dispose_leftovers()
{
	input_size = 0;

	for (int i = 0; i < dex; i++)
	{
		remember32[i] = -858993460;
		offsets[i] = -858993460;
		onetwenty_c[i] = -858993460;
		thirty_c[i] = -858993460;
		keyholder159[i] = -858993460;
	}	
}

void inputhandler::prepare_encryption(std::string & userinput)
{ 
	/*searches whitespaces, remembers the position of them and overwrites them*/

	/*2 counters, one for brokeninput to overwrite whitespaces, second for remember32
	so that it starts at 0*/

	for (int i = 0; i < (int)userinput.length(); i++)
	{
		// in this case our index is a ruler
		brokeninput[use.rindex] = userinput[i];

		if (brokeninput[use.rindex] == 32)
		{
			remember32[rem_i] = i;
			rem_i++;
			use.rindex--;
		}

		use.rindex++;
		
	}

	// end value is the new size of brokeninput after removing whitespaces
	input_size = use.rindex;
}

void inputhandler::prepare_decryption()
{
	int keyL, l126, l33, offL, rem32L;

	keyL = keyholder_de[0];
	l126 = keyholder_de[1];
	offL = keyholder_de[2];
	l33 = keyholder_de[3];
	rem32L = keyholder_de[4];

	int i = 5;
	for (int ia = 0; ia < l126; i++, ia++)
	{
		onetwenty_c[ia] = keyholder_de[i];	
	}
	for (int ia = 0; ia < l126; i++, ia++)
	{
		offsets[ia] = keyholder_de[i];
	}
	for (int ia = 0; ia < l126; i++, ia++)
	{
		thirty_c[ia] = keyholder_de[i];
	}
	for (int ia = 0; ia < rem32L; i++, ia++)
	{
		remember32[ia] = keyholder_de[i];
	}
}

void inputhandler::encrypter159()
{
	/*By adding the offset value to the decimal number of the ascii tables character and subtracting or adding certain numbers,
	until its in the range of readable characters we automaticly 'encrypt' the text.*/

	int temp_broken;

	for (int i = 0; i < input_size; i++)
	{
		temp_broken = (int)brokeninput[i] + offsets[i];

		use.rE126 = 0;
		use.rE33 = 0;

		while (temp_broken > 126 || temp_broken < 33)
		{
			if (temp_broken > 126)
			{
				temp_broken -= 126;
				use.rE126++;
			}
			else if (temp_broken < 33)
			{
				temp_broken += 33;
				use.rE33++;
			}
		}

		brokeninput[i] = temp_broken;

		onetwenty_c[i] = use.rE126;
		use.r126++;

		thirty_c[i] = use.rE33;
		use.r33++;
	}
}

void inputhandler::keygen159()
{
	/*Okay, so I took the 5 variables that will allways only occupy one array space at a time
	and put them in front of everything else because that way my decrypter will instantly know
	what and where to pass.*/

	int contindex = 0;

	key_size = use.arraymax(use.r126, use.r33, use.rOffset, rem_i) + 5;

	keyholder159[contindex] = key_size;
	contindex++;
	keyholder159[contindex] = use.r126;
	contindex++;
	keyholder159[contindex] = use.rOffset;
	contindex++;
	keyholder159[contindex] = use.r33;
	contindex++;
	keyholder159[contindex] = rem_i;
	contindex++;

	
	for(int i = 0; i < use.r126; i++)
	{
		keyholder159[contindex] = onetwenty_c[i];
		contindex++;
	}
	for(int i = 0; i < use.rOffset; i++)
	{
		keyholder159[contindex] = offsets[i];
		contindex++;
	}
	for(int i = 0; i < use.r33; i++)
	{
		keyholder159[contindex] = thirty_c[i];
		contindex++;
	}
	for (int i = 0; i < rem_i; i++)
	{
		keyholder159[contindex] = remember32[i];
		contindex++;
	}
}

void inputhandler::decryption159()
{
	int temp_char;
	
	//reverse encrypter
	for (int i = 0; i < input_size; i++)
	{
		bool origin_found = false;

		temp_char = (int)entxt[i];

		while ((temp_char < 126 || temp_char > 33) && origin_found == false)
		{
			if (temp_char > 33)
			{
				for(;thirty_c[i];)
				{
					temp_char -= 33;
				}
			}
			else if (temp_char < 126)
			{
				for (;onetwenty_c[i];)
				{
					temp_char += 126;
				}
			}
			origin_found = true;
		}
		
		temp_char = (int)entxt[i] - offsets[i];
		entxt[i] = temp_char;
	}

	if (keyholder_de[4] != 0)
	{
		for (int i = 0; i < keyholder_de[4]; i++)
		{
			int temp_i = i;
			i = remember32[i];
			char temp_char = entxt[i];
			char temp_nchar = (int)entxt[i + 1];
			entxt[i] = 32;

			

			i++;
			bool t_c = false;
			bool t_nc = false;

			for (i; i < input_size; i++)
			{
				

				if (t_c == false)
				{
					entxt[i] = temp_char;
					temp_char = (int)entxt[i + 1];
					t_c = true;
				}
				else if (t_nc == false)
				{
					entxt[i] = temp_nchar;
					temp_nchar = (int)entxt[i + 1];
					t_nc = true;
				}

			}
			
			i = temp_i;
		}
	}
	
}

void inputhandler::set_offsets(int offsetproxy, int i)
{
	offsets[i] = offsetproxy;
	use.rOffset++;
}

void inputhandler::set_keyholder(int keyinput, int i)
{
	keyholder159[i] = keyinput;
	use.rKey++;
}

void inputhandler::set_entxt(std::string & txtinput, int i)
{
	entxt[i] = txtinput[i];
	input_size++;
}

void inputhandler::set_brokeninput(std::string & txtinput, int i)
{
	brokeninput[i] = txtinput[i];
}

void inputhandler::set_keyholder_de(int keyproxy,int i)
{
	keyholder_de[i] = keyproxy;
}

int inputhandler::get_input_size() const
{
	return input_size;
}

char inputhandler::get_brokeninput(int i) const
{
	return brokeninput[i];
}

int inputhandler::get_key(int i) const
{
	return keyholder159[i];
}

char inputhandler::get_entxt(int i) const
{
	return entxt[i];
}

int inputhandler::get_key_size() const
{
	return key_size;
}
