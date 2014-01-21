//
//  11534 - Say goodbye to
//  Uva
//
//  Created by Alexander Faxå on 2012-05-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <string.h>
#include <cassert>
#include <vector>
#include <algorithm>

#define POINT 0
#define CROSS 1
#define CIRCLE 2

using namespace std;

char a[101];

int dp[3][3][102];

int n;

int solve(int lower, int upper, int length)
{
	//	cout << lower << " " << upper<< " "  << length << endl;
	if(dp[lower][upper][length] != -1)
		return dp[lower][upper][length];
	
	if(length <= 1)
		return 0;
	
	if(length == 2)
	{
		assert(lower == POINT || upper == POINT);
		if(lower == POINT && upper == POINT)
			return 0;
		else
			return 1;
	}
	
	vector<int>v;
	v.push_back(0);
	for(int i = 0; i < length; i++)
	{
		if(i==0)
		{
			if(lower == POINT)
			{
				if(length != 3 || upper != CROSS) 
					v.push_back(solve(CROSS, upper, length));
				if(length != 3 || upper != CIRCLE)
					v.push_back(solve(CIRCLE, upper, length));
			}
			continue;
		}
		if(i == length-1)
		{
			if(upper == POINT)
			{
				if(length != 3 || lower != CROSS) 
					v.push_back(solve(lower, CROSS, length));
				if(length != 3 || lower != CIRCLE)
					v.push_back(solve(lower, CIRCLE, length));
			}
			continue;
		}
		
		if(length == 3)
		{
			if(lower == CROSS && upper == CROSS)
				v.push_back(1);
			if(lower == CIRCLE && upper == CIRCLE)
			   v.push_back(1);
			if(lower == POINT && upper == POINT)
				v.push_back(1);
			continue;
		}
		
		if(i == 1)
		{
			if(lower == POINT)
			{
				v.push_back(solve(POINT, CROSS, 2) ^ solve(CROSS, upper, length-1));
				v.push_back(solve(POINT, CIRCLE, 2) ^ solve(CIRCLE, upper, length-1));
			}
			else
			{
				if(lower == CIRCLE)
					v.push_back(solve(CROSS,upper,length-1));
				if(lower == CROSS)
					v.push_back(solve(CIRCLE,upper,length-1));
			}
			continue;
		}
		
		if(i == length - 2)
		{
			if(upper == POINT)
			{
				v.push_back(solve(CROSS,POINT, 2) ^ solve(lower, CROSS, length-1));
				v.push_back(solve(CIRCLE,POINT, 2) ^ solve(lower, CIRCLE, length-1));
			}
			else
			{
				if(upper == CIRCLE)
					v.push_back(solve(lower, CROSS,length-1));
				if(upper == CROSS)
					v.push_back(solve(lower, CIRCLE,length-1));
			}
			continue;
		}
		
		v.push_back(solve(lower,CROSS,length-i) ^ solve(CROSS, upper, length-i));
		v.push_back(solve(lower, CIRCLE, length-i) ^ solve(lower, CIRCLE, length-i));

	}
	int a[100];
	memset(a, 0, sizeof(a));
	for(int i = 0; i < v.size(); i++)
		a[v[i]] = 1;
	for(int i = 0; i < 100; i++)
	{
		if(!a[i])
		{
			dp[lower][upper][length] = i;
			return i;
		}
	}
	return -1; //error
}


int main()
{
	int t;
	cin >> t;
	string s;
	getline(cin,s);
	while(t--)
	{
		getline(cin,s);
		n = s.length();
		
		int turn = 0;
		for(int i=0; i<n; i++)
		{
			a[i]=s[i];
			if(a[i] != '.')
				turn++;
		}
		
		char lower = POINT;
		int i = 0;
		int myxor = 0;
		int length = 0;
		
		memset(dp,-1, sizeof(dp));
		
		for(; i < n; i++)
		{
			length++;
			if(a[i]=='X')
			{
				if(length > 1 && a[i-1]=='.')
					myxor ^= solve(lower, CROSS, length);
				length = 1;
				lower = CROSS;
			}
			if(a[i]=='O')
			{
				if(length > 1 && a[i-1]=='.')
					myxor ^= solve(lower, CIRCLE, length);
				length = 1;
				lower = CIRCLE;
			}
		}
		if(length > 1)
			myxor ^= solve(lower, POINT, length);
		
		bool res;
		if(turn%2==0)
			res = myxor != 0;
		else
			res = myxor == 0;
		if(n==1 || res)
			cout << "Possible." << endl;
		else
			cout << "Impossible." << endl;
		
	}	return 0;
}*/