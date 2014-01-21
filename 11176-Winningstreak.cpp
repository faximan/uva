//
//  11176 - Winning streak.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-19.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <math.h>

using namespace std;

int n;
double p;
double f[510][510];

double solve()
{	
    for(int i = 0; i <= n; i++)
        f[0][i] = 1;
	
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++)
        {
			f[i][j] = f[i-1][j];
            if(j + 1 == i)
                f[i][j] -= pow(p,j+1);
            else if(j + 1 < i)
                f[i][j] -= f[i-j-2][j] * (1-p) * pow(p,j+1);
        }
	
	double ans = 0;
    for(int i = 1; i <= n; i++)
        ans += i * (f[n][i] - f[n][i-1]);
	
    return ans;
}

int main()
{
    while(true)
    {
		cin >> n >> p;
        if(!n)
            break;
		cout.precision(7);
        cout << fixed << solve() << endl;
    }
    return 0;
}*/