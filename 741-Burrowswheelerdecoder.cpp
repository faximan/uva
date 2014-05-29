//
//  741 - Burrows wheeler decoder.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-16.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int ok = false;
	while(true)
	{
		string p;
		int n;
		cin >> p >> n;
		if(!n)
			break;

		if(ok)
			cout << endl;
		ok = true;

		vector<string>s(p.length());

		for(int j = 0; j < p.length(); j++)
		{
			for(int i = 0; i < p.length(); i++)
			{
				string cur = s[i];
				cur = p[i] + cur;
				s[i] = cur;
			}
			sort(s.begin(), s.end());
		}
		cout << s[n-1] << endl;
	}
	return 0;
}
