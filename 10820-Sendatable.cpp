//
//  10820 - Send a table.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-28.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;

int phi(int x) 
{
    int ret = 1;
    int pow;
    
    for (int i = 2; x != 1; i++) {
        pow = 1;
        while (!(x%i)) {
            x /= i;
            pow *= i;
        }
        ret *= (pow - (pow/i));
    }
    return ret;
}

int main()
{
    int n;
    
    long long gcder[50001];
        
    gcder[1] = 1;
    
    for (int i = 2; i <= 50000; i++)
        gcder[i] = gcder[i-1]+2*phi(i);

    while(true)
    {
        cin >> n;
        if(n==0) break;
        
        cout << gcder[n] << endl;
    }

    return 0;
}