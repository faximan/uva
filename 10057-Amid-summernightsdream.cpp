//
//  10057 - A mid-summer nights dream.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-16.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		map<int,int>m;
		int numbers[1000001];
		for(int i = 0; i < n; i++)
		{
			cin >> numbers[i];
			m[numbers[i]]++;
		}
		sort(numbers,numbers+n);
		
		if(n%2==0)
		{
			int med1 = numbers[n/2-1];
			int med2 = numbers[n/2];
			if(med1==med2)
				cout << med1 << " " << m[med1];
			else
				cout << med1 << " " << m[med1]+m[med2];
			cout << " " << med2-med1+1 << endl;
		}
		else{
			cout << numbers[n/2] << " " << m[numbers[n/2]] << " 1\n";
		}
	}
	return 0;
}
*/