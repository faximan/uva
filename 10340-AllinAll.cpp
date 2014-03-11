//
//  10340 - All in All.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-14.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int index = 0;
		for(int i = 0; i < t.length(); i++)
		{
			if(t[i]==s[index])
				index++;
		}
		if(index == s.length())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}