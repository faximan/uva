//
//  799 - Safari holiday.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-02.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    long long n, kmax;
    while (cin >> n >> kmax) 
    {
        if(kmax >= n || n == 1)
        {
            cout << n << " persons/group, 1 day" << endl;
            continue;
        }
       
        bool sol = false;
        for (long long k = kmax; k >= 2; k--) {
            if(n % k == 0)
            {
                if((n-1) % (k-1) == 0)
                {
                    long long days = (n-1)/(k-1);
                    cout << k << " persons/group, " << days << " day";
                    if(days > 1)
                        cout << "s";
                    cout << endl;
                    sol = true;
                    break;
                }
            }
        }
        if(!sol)
            cout << "No solution" << endl;
        
    }
    return 0;
}
