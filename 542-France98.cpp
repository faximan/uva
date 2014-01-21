//
//  542 - France98.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-17.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <math.h>

using namespace std;

string name[16];
double prob[16][16];

double res[16][5];

int main()
{
	for (int i = 0; i < 16; i++) 
		cin >> name[i];
	
	for (int i = 0; i < 16; i++) 
	{
		for (int j = 0; j < 16; j++) 
		{
			cin >> prob[i][j];
			prob[i][j] /= 100.0;
		}
		res[i][0] = 1.0;
	}
	
	for (int i = 1; i <= 4; i++) 
	{
		for (int j = 0; j < 16; j++) 
		{
			double cur = 0;
			
			int now = (j/(int)pow(2,i))*pow(2,i) - 1;
			for (int k = 0; k < pow(2,i); k++)
			{
				if(++now == j || j/(int)pow(2,i-1)==now/(int)pow(2,i-1))
					continue;			
				cur += res[now][i-1] * prob[j][now];
			}
			res[j][i] = cur*res[j][i-1];
		}
	}
	
	cout.precision(2);
	for (int i = 0; i < 16; i++) {
		cout << name[i];
		for (int j = name[i].length(); j <= 10; j++)
			cout<< " ";
		cout << "p=" << fixed << res[i][4]*100 << "%" << endl;
	}
	return 0;
}*/