//
//  11278 - One handed typist.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-15.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>

using namespace std;

string qwerty = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:1ZXCVBNM<>?";
string dworak = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG1";

int main()
{
	char c;
	string s;
	while(getline(cin,s))
	{
		for (int j = 0; j < s.length(); j++) 
		{
			c = s[j];
			if(c==' ')
				cout << " ";
			else if(c=='"')
				cout << "_";
			else if(c=='?')
				cout << "\"";
			else 
			{
				for (int i = 0; i < qwerty.length(); i++) 
					if(qwerty[i]==c)
					{
						cout << dworak[i];
						break;
					}
			}
		}
		cout << endl;
	}
	return 0;
}
*/