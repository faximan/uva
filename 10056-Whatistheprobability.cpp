//
//  10056 - What is the probability.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-16.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int s;
	cin >> s;
	while(s--)
	{
		int n, i;
		double p;
		cin >> n >> p >> i;
		double cur = 1;
		i--;
		int curp = 0;
		double res = 0;
		for (int j = 0; j < 10000; j++) 
		{
			if(curp==i)
				res += cur*p;
			cur *= 1-p;
			curp = (curp+1)%n;
		}
		printf("%.4f\n", res);
	}
	return 0;
}
*/