//
//  10064 - Number theory.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-19.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int prime[664579]; // TODO: numprimes (+2, säkerhetsmarginal)
int numprimes;


void calcprimes(int maxn)
{
	prime[0] = 2;
	numprimes = 1;
	prime[numprimes] = 46340; // 0xb504*0xb504 = 0x7FFEA810
	for(int n = 3; n < maxn; n += 2)
	{
		for(int i = 1; prime[i]*prime[i] <= n; ++i)
		{
			if(n % prime[i] == 0)
				goto not_prime;
		}
		prime[numprimes++] = n;
		prime[numprimes] = 46340; // 0xb504*0xb504 = 0x7FFEA810
	not_prime:
		;
	}
}
int main()
{
	int n;
	calcprimes((int)sqrt(pow(2,32)));

	while(cin>>n)
	{
		int div = 1;
		int cop = n;
		int cur = n;

		int i = 0;
		int cur_prime = prime[i];

		while(cur != 1 && cur_prime*cur_prime <= cur && cur_prime != 0)
		{
			int times = 0;
			if(cur%cur_prime==0)
				cop -= cop/cur_prime;
			while(cur%cur_prime==0)
			{
				cur /= cur_prime;
				times++;
			}
			div *= (times+1);
			i++;
			cur_prime = prime[i];
		}
		if(cur != 1)
		{
			cop -= cop/cur;
			div *= 2;
		}
		cout << n-div-cop+1 << endl;
	}
	return 0;
}
