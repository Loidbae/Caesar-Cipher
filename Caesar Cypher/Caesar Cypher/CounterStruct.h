#pragma once

/*Guidelines for this project (not sure if those are good ones need feedback on them)

	- If possible find rememberable and short names for your functions;
	- Create a good and readable structure if it works, keep it, if not change it.
	- Member Variables of another class should be named after the act of getting / using something from that class;
	- Documentation should be simply worded and in short sentences. if possible (clean and simple);

*/// Code written by Loidbae, Github:https://github.com/Loidbae


/*since there seems to be no way of reading the currently filled (int)array spaces accurately
(sizeof...) I decided to count every Input and use it as their max values for loops*/

struct counterstruct
{

	int arraymax(int a,int b, int c)
	{
		int arrayR = a + b + c;
		return arrayR;
	}
	int arraymax(int a, int b, int c, int d)
	{
		int arrayR = a + b + c + d;
		return arrayR;
	}

	void clear()
	{
		rE126 = 0;
		rE33 = 0;
		
		r126 = 0;
		r33 = 0;
		
		rKey = 0;
		rOffset = 0;
		rindex = 0;
	}

	int rE126;
	int rE33;

	int r126;
	int r33;

	int rKey;
	int rOffset;
	int rindex;
};