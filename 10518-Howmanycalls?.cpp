//
//  10518 - How many calls?.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>

#define MAX 1000000

using namespace std;

int main()
{
	long long n, b;
	int casenbr = 0;
	while(true)
	{
		casenbr++;
		cin >> n >> b;
		if(!n && !b)
			break;
		
		cout << "Case " << casenbr << ": " << n << " " << b << " ";
		
		long long lastDigit[MAX];
		lastDigit[0] = 1;
		lastDigit[1] = 1;
		
		int i;
		for(i = 2; i< MAX; i++)
		{
			lastDigit[i] = (lastDigit[i-1]+lastDigit[i-2]+1) % b;
			if(lastDigit[i] == 1 && lastDigit[i-1] == 1)
				break;
		}
		
		i = i-1;
		cout << lastDigit[n % i] << endl;
	}
	return 0;
}*/