//
//  10311 - Goldbach and Euler.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAXN 100000000

char prime[100000000];

// Calc primes up to MAXN, store in prime
void calcprimes()
{
	memset(prime,255,sizeof(prime));

	prime[0] = 0xFE;

	for(int i = 1; i < 5000; i++)
	{
		if (prime[i>>3]&(1<<(i&7)))
		{
			for(int j = i + i + i + 1; j < MAXN/2; j += i + i + 1)
			{
				prime[j>>3]&=~(1<<(j&7));
			}
		}
	}
}

bool isprime(long long n)
{
	return prime[(n) >> 4] & ( 1<< (((n) >> 1) & 7));
}

int main()
{
	calcprimes();

	int n;
	while (cin >> n)
	{
		if (n < 3)
		{
			cout << n << " is not the sum of two primes!" << endl;
			continue;
		}

		if (n%2 == 1)
		{
			if (isprime(n-2))
				cout << n << " is the sum of 2 and " << n-2 << "." << endl;
			else
				cout << n << " is not the sum of two primes!" << endl;
			continue;
		}
		else
		{
			bool ok = false;

			int i = n/2;
			if(i%2==0)
				i++;
			for (; i >= 3; i-=2)
			{
				if (isprime(i) && isprime(n-i))
				{
					int p1 = min(i, n-i);
					int p2 = max(i, n-i);
					if(p1!=p2 && p1>1 && p2 > 1)
					{
						cout << n << " is the sum of " << p1 << " and " << p2 << "." << endl;
						ok = true;
						break;
					}
				}
			}
			if (!ok)
				cout << n << " is not the sum of two primes!" << endl;
		}
	}
	return 0;
}
