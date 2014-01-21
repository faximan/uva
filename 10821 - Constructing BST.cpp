//
//  10821 - Constructing BST.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

void solve(int min, int max, int h)
{
	if(max < min)
		return;
	if(max == min)
	{
		printf(" %d", min+1);
		return;
	}
	int root = max - (pow(2,h-1)-1);
	if(root < min)
	{
		printf(" %d", min+1);
		solve(min+1,max,h-1);
		return;
	}
	printf(" %d", root+1);
	solve(min,root-1,h-1);
	solve(root+1,max,h-1);
}

int main()
{
	int n, h;
	int casenbr = 0;
	while(true)
	{
		casenbr++;
		scanf("%d %d", &n, &h);
		if(n==0 && h==0)
			break;
		printf("Case %d:", casenbr);
		if(pow(2,h)-1<n)
		{
			printf(" Impossible.\n");
			continue;
		}
		solve(0,n-1,h);			
		cout << endl;
	}
	return 0;
}*/