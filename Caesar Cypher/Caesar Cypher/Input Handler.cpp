#include "pch.h"
#include "Input Handler.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void inputhandler::prepare_brokeninput(std::string & userinput) 
{ 
	/*this is a special setter it searches whitespaces reports them and
	removes them*/

	/*first we want two indipendent counters for remember32 and brokeninput
	this is so that brokeninput can overwrite the whitespace the next interation
	and the second one is for remember32 so that it begins at 0*/

	int i_r = 0;

	for (int i = 0; i < (int)userinput.length(); i++)
	{
		// ruler as index for overwriting whitespaces*
		brokeninput[use.rindex] = userinput[i];

		if (brokeninput[use.rindex] == 32)
		{
			remember32[i_r] = i;
			i_r++;
			use.rindex--; //*
		}

		use.rindex++;
	}

	inputsL = use.rindex; // end value is the new size of brokeninput after removing whitespaces 
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
				temp_broken =- 126;
				use.rE126++;
			}
			else if (temp_broken < 33)
			{
				temp_broken =+ 33;
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
	int fair_c = 0;
	bool fairplay = false;

	for (int i = 0; i < dex; i++)
	{
		
		if (i % 2 == 0 || i == 0 && i != use.r126)
		{
			keyholder159[i] = onetwenty_c[i];
			
			if (i % 2 == 0 && i % 3 == 0)
			{
				fair_c++;
			}

			if (fair_c == 4)
			{
				fairplay = true;
			}
		}
		if (i % 3 == 0 && i != use.r33)
		{
			if (fairplay == true)
			{
				keyholder159[i] = thirty_c[i];
			}
		}
		if (i != 0 && i != use.rOffset)
		{
			if (i % i == 0 && i != i % 2 == 0 && i != i % 3 == 0 && i != 0)
			{
				keyholder159[i] = offsets[i];
			}
		}
		
	}
}

void inputhandler::set_offsets(int offsetproxy, int i)
{
	offsets[i] = offsetproxy;
	use.rOffset++;
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

