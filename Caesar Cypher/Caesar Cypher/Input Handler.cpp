#include "pch.h"
#include "Input Handler.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void inputhandler::prepare_brokeninput(std::string & userinput) 
{ 
	/*searches whitespaces, remembers the position of them and overwrites them*/

	/*2 counters, one for brokeninput to overwrite whitespaces, second for remember32
	so that it starts at 0*/

	int i_r = 0;

	for (int i = 0; i < (int)userinput.length(); i++)
	{
		// in this case our index is a ruler
		brokeninput[use.rindex] = userinput[i];

		if (brokeninput[use.rindex] == 32)
		{
			remember32[i_r] = i;
			i_r++;
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
	int c126 = 0;
	int c33 = 0;
	int offsetc = 0;
	bool fairplay = false;
	bool done126 = false;
	bool done33 = false;
	bool doneOffset = false;

	for (int i = 0; i < dex; i++)
	{
		bool even = false;
		bool three = false;
		bool fairactive = false;

		if (i % 2 == 0 && c126 < use.r126 && done126 == false || i == 0 || done33 == true || doneOffset == true)
		{
			keyholder159[i] = onetwenty_c[c126];
			c126++;
			even = true;

			if (c126 == use.r126)
			{
				done126 = true;
			}

			if (i % 2 == 0 && i % 3 == 0 || i == 0)
			{
				fair_c++;
				fairactive = true;
			}

			if (fair_c == 4)
			{
				fairplay = true;
			}
		}
		if (i % 3 == 0 && i != 0 && c33 < use.r33 && done33 == false || done126 == true || doneOffset == true )
		{
			if (fairactive == false)
			{
				keyholder159[i] = thirty_c[c33];
				c33++;
				three = true;

				if (fairplay == true)
				{
					i++;
					keyholder159[i] = thirty_c[c33];
					c33++;
				}
				if (c33 == use.r33)
				{
					done33 = true;
				}
			}
			
		}
		if (three == false && even == false && i != 0 && doneOffset == false || done126 == true || done33 == true )
		{
				keyholder159[i] = offsets[offsetc];
				offsetc++;

				if (offsetc == use.rOffset)
				{
					doneOffset = true;
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

