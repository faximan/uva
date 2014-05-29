//
//  10229 - Modular Fibonacci.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-28.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <map>

using namespace std;

map<long long int, long long int>mymap;

long long int fib(long long int n, long long int m)
{
    if(mymap.count(n))
        return mymap[n];

    long long int res;
    if (n % 2 == 0)
    {
        long long int res1 = fib(n/2,m);
        long long int res2 = fib(n/2-1,m);
        res = (res1 * (res1 + 2*res2)) % m;
    }
    else
    {
        long long int res1 = fib((n+1)/2,m);
        long long int res2 = fib((n+1)/2-1,m);
        res = (res1*res1 + res2*res2) % m;
    }
    mymap[n] = res;
    return res;
}


int main()
{
    long long int n;
    int m;
    while(cin >> n >> m)
    {
        mymap.clear();
        mymap[0]=0;
        mymap[1]=1;
        cout << fib(n,(long long int)pow(2,m)) << endl;
    }
    return 0;
}
