//
//  255 - Correct Move.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-15.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;

int king[64];
int queen[64];

int main()
{
	int k, q, nq;
	while(cin >> k>> q >> nq)
	{
		if(k==q)
		{
			cout << "Illegal state" << endl;
			continue;
		}
		for (int i = 0; i < 64; i++)
		{
			king[i] = 0;
			queen[i] = 0;
		}
		king[k] = 1;
		if(k%8!=0 && k-1!=q)
			king[k-1]=1;
		if((k+1)%8!=0 && k+1!=q)
			king[k+1]=1;
		if(k>=8 && k-8!=q)
			king[k-8]=1;
		if(k<=55 && k+8!=q)
			king[k+8]=1;

		int i = q;
		while(true)
		{
			queen[i] = 1;
			i--;
			if(i==k || (i+1)%8==0)
				break;
		}
		i = q;
		while(true)
		{
			queen[i] = 1;
			i++;
			if(i==k || i%8==0)
				break;
		}
		i = q;
		while(true)
		{
			queen[i] = 1;
			i-=8;
			if(i==k || i<0)
				break;
		}
		i = q;
		while(true)
		{
			queen[i] = 1;
			i+=8;
			if(i==k || i>63)
				break;
		}
		queen[q] = 0;
		if(queen[nq] != 1)
		{
			cout << "Illegal move" << endl;
			continue;
		}
		if(king[nq] == 1)
		{
			cout << "Move not allowed" << endl;
			continue;
		}
		if((k==0&&nq==9) || (k==7&&nq==14) || (k==56&&nq==49) || (k==63&&nq==54))
		{
			cout << "Stop" << endl;
			continue;
		}
		cout << "Continue" << endl;
	}
	return 0;
}
