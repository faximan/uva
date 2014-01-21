//
//  10892 - LCM Cardinality.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-13.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <vector>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	while(b != 0)
	{
		long long c = a % b;
		a = b;
		b = c;
	}
	return a; // 0 returneras om både a = 0 och b = 0
}

long long lcm(long long a, long long b)
{
	return (a / gcd(a, b)) * b; // Inte a*b/gcd() pga. overflow
}

int main()
{
    long long n;
    while (true) {
        cin >> n;
        if(n==0)break;
        cout << n << " ";
        vector<long long>v;
        for (long long i = 1; i*i <=n; i++) {
            if(n%i==0)
            {
                v.push_back(i);
                if(i*i!=n)
                    v.push_back(n/i);
            }
        }
       
        int ans = 1;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i+1; j < v.size(); j++) {
                if(lcm(v[i],v[j]) == n)
                    ans++;
            }
        }
        cout << ans << endl;
    }    
    return 0;
}*/