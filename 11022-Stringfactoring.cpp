//
//  11022 - String factoring.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-19.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int>m;

bool same(int a, int b, string& s)
{
	if(s.length()-b < b-a)
		return false;
	
	for(int i = 0; i < b-a; i++)
		if(s[a+i] != s[b+i])
			return false;
	return true;
}

int solve(string s)
{
	if(m.count(s))
		return m[s];
	
	int ma = s.length();
	
	for(int i = 0; i < s.length(); i++)
		for(int j = i+1; j < s.length(); j++)
		{
			string newstring = s;
			while(same(i,j,newstring))
			{
				newstring = newstring.substr(0,i) + newstring.substr(j);
			}
			if(newstring != s)
			{
				int newvalue = solve(newstring.substr(0,i)) + 
								solve(newstring.substr(i, j-i)) +
								solve(newstring.substr(j));
				ma = min(ma, newvalue);
			}
		}
	m[s] = ma;
	return ma;	
}

int main()
{
	string s;
	while(true)
	{
		cin >> s;
		if(s=="*")
			break;
		
		cout << solve(s) << endl;
		
	}
	return 0;
}*/