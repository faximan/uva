//
//  10701 - Pre, in and post.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

map<char, int>m;

string pre, in;
int indexet;

void print(int min, int max)
{
	if(min > max)
		return;
	char cur = pre[indexet];
	indexet++;
	print(min, m[cur]-1);
	print(m[cur]+1, max);
	cout << cur;
}

int main()
{
	int c;
	cin >> c;
	while(c--)
	{
		int n;
		cin >> n;
		cin >> pre >> in;
		m.clear();
		for(int i = 0; i < n; i++)
			m[in[i]] = i;
		indexet = 0;
		print(0,n-1);
		cout << endl;
	}		
	return 0;
}