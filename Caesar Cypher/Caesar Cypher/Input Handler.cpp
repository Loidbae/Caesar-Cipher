#include "pch.h"
#include "Input Handler.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void inputhandler::clearArrays()
{
	for (int i = 0; i < dex; i++)
	{
		remember32[i] = -858993460;
		offsets[i] = -858993460;
		onetwenty_c[i] = -858993460;
		thirty_c[i] = -858993460;
		keyholder159[i] = -858993460;
	}
	for (int i = 0; i < dex; i++)
	{
		brokeninput[i];

	}
	
}

void inputhandler::prepare_brokeninput(std::string & userinput,std::string& keyinput, bool decrypting)
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
			use.rindex--; // <--
		}

		use.rindex++;
	}

	// end value is the new size of brokeninput after removing whitespaces
	inputsL = use.rindex;
}

void inputhandler::encrypter159()
{
	int temp_broken;

	for (int i = 0; i < inputsL; i++)
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
	/*Okay so I took the 5 variables that will allways only occupy one array space at a time
	and put them in front of everything else because that way my decrypter will instantly know
	what, where to pass.*/

	int contindex = 0;

	keysize = use.arraymax(use.r126, use.r33, use.rOffset, rem_i);

	keyholder159[contindex] = keysize;
	contindex++;
	keyholder159[contindex] = use.r126;
	contindex++;
	keyholder159[contindex] = use.rOffset;
	contindex++;
	keyholder159[contindex] = use.r33;
	contindex++;
	keyholder159[contindex] = rem_i;
	contindex++;

	for (int i = 0; i < rem_i; i++)
	{
		keyholder159[contindex] = remember32[i];
		contindex++;
	}
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
	
}

void inputhandler::decryption159()
{
	use.clear();

	int keyL, l126, l33, offL, rem32L;

	keyL = newkey[0];
	newkey[0] = 'Q';
	l126 = newkey[1];
	newkey[1] = 'Q';
	offL = newkey[2];
	newkey[2] = 'Q';
	l33 = newkey[3];
	newkey[3] = 'Q';
	rem32L = newkey[4];
	newkey[4] = 'Q';

	for (int i = 0; i < keyL; i++)
	{
		if (newkey[i] == 'Q')
		{
			i++;
		}
		else
		{
			keyholder_de[i] = newkey[i];
		}
	}

	for (int i = 5, ia = 0; ia < rem32L; i++, ia++)
	{
		remember32[ia] = keyholder_de[i];
	}
	for (int i = 5, ia = 0; i < l126; i++, ia++)
	{
		onetwenty_c[ia] = keyholder_de[i];
	}
	for (int i = 5, ia = 0; i < offL; i++, ia++)
	{
		offsets[ia] = keyholder_de[i];
	}
	for (int i = 5, ia = 0; i < l33; i++,ia++)
	{
		thirty_c[ia] = keyholder_de[i];
	}

	for (int i = 0; i < ; i++)
	{
		temp_key = (int)newkey[i] - offsets[i];


		while (temp_key > 126 || temp_key < 33)
		{
			if (temp_key > 126)
			{
				temp_key += 126;
			}
			else if (temp_key < 33)
			{
				temp_key -= 33;
			}
		}

		newkey[i] = temp_key;
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

void inputhandler::set_brokeninput(std::string & txtinput, int i)
{
	brokeninput[i] = txtinput[i];
}

void inputhandler::set_newkey(int keyproxy,int i)
{
	newkey[i] = keyproxy;
}

int inputhandler::get_inputsL() const
{
	return inputsL;
}

char inputhandler::get_brokeninput(int i) const
{
	return brokeninput[i];
}

int inputhandler::get_key(int i) const
{
	return keyholder159[i];
}