//
//  10271 - Chopsticks.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, k, t, i, j;
    int bad[5001];
    int dp[5001];
    cin >> t;
    while(t--)
    {
        cin >> k >> n;
        int temp = 0, temp2 = 0;
        dp[0]=0;
        for (i = 1; i <= n; i++) {
            cin >> temp2;
            bad[i] = (temp2-temp)*(temp2-temp);
            temp = temp2;
            dp[i] = 0;
        }
        k += 8;
        
        for (i = 1; i <= k; i++) {
            
            for (j = n-3*(k-i)-1; j >= 2*i; j--)
                dp[j] = dp[j-2]+bad[j];
            
            for(j+=2; j <= n-3*(k-i)-1; j++)
                dp[j] = min(dp[j],dp[j-1]);
            
            dp[n-3*(k-i)] = dp[n-3*(k-i)-1];
        }       
        cout << dp[n] << endl;
    }   
    return 0;
}
