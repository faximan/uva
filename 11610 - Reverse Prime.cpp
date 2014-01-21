//
//  11610 - Reverse Prime.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-25.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int prime[78500]; // TODO: numprimes (+2, säkerhetsmarginal)
int reverse_prime[78500];
int nbr_factors[78500];
int numprimes;

map<int, int>m;

void calcprimes(int maxn)
{
	prime[0] = 2;
    m[2] = 1;
    reverse_prime[0] = 2000000;
	numprimes = 1;
    
    int to_reverse;
	prime[numprimes] = 46340; // 0xb504*0xb504 = 0x7FFEA810
	for(int n = 3; n < maxn; n += 2)
	{
		for(int i = 1; prime[i]*prime[i] <= n; ++i)
		{
			if(n % prime[i] == 0)
				goto not_prime;
		}       
		prime[numprimes] = n;
        m[n] = 1;
        
        to_reverse = n;
        reverse_prime[numprimes] = 0;
        for (int i = 0; i < 7; i++) {
            reverse_prime[numprimes] = reverse_prime[numprimes] * 10 + to_reverse % 10;
            to_reverse /= 10;
        }
        
        numprimes++;
		prime[numprimes] = 46340; // 0xb504*0xb504 = 0x7FFEA810
    not_prime:
		;
	}
}

int find_factors(int k)
{
    if(m.count(k))
        return m[k];
    
    int i = 0;
    while(k % prime[i] != 0)
    {
        i++;
    }
    
    m[k] = 1 + find_factors(k / prime[i]);;
    return m[k];    
}

int main()
{
    calcprimes(1000000);
    
    sort(reverse_prime, reverse_prime+numprimes);
        
    for (int i = 0; i < numprimes; i++)
        nbr_factors[i] = find_factors(reverse_prime[i]);
    
    char c;
    int nbr;
    
    while(cin >> c)
    {
        cin >> nbr;
        
        if(c == 'q')
        {
            int sum = 0;
            for(int i = 0; nbr >= 0; i++)
            {
                if(nbr_factors[i] != 0)
                    nbr--;
                sum += nbr_factors[i];
            }
            cout << sum << endl;
        }
        else
        {
            int index = 0;
            while(reverse_prime[index] != nbr)
            {
                index++;
            }
            nbr_factors[index] = 0;
        }       
    }   
    return 0;
}
*/