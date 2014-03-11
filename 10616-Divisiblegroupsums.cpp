//
//  10616 - Divisible group sums.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

long long dp[201][11][20];
int a[201];

int n;

int mod(int n,int m)
{
    if(n<0)
        n+=(ceil(-n*1.00/m)*m);
        return n%m;
}

int solve(int curn, int m, int cursum, int d)
{
    if(curn == 0 && m > 0)
        return 0;
    
    if(dp[curn][m][cursum] != -1)
        return dp[curn][m][cursum];
        
    if(m == 0)
        return cursum == 0;
    
    
    dp[curn][m][mod(cursum,d)] = solve(curn-1, m-1, mod(cursum-a[curn-1], d), d) + solve(curn-1, m, cursum, d);
    return dp[curn][m][mod(cursum,d)];    
}


int main()
{
    int q;
    int c = 0;
    while(true){
        c++;
        cin >> n >> q;
        if(!(n && q))
            break;
        
        cout << "SET " << c << ":" << endl;
        for (int i = 0;  i < n; i++) {
            cin >> a[i];
        }
        for (int qr = 1; qr <= q; qr++){
            cout << "QUERY " << qr << ": ";
            int d, m;
            cin >> d >> m;
            
            for (int i = 0; i <= n; i++) 
                for(int j = 0; j <= m; j++)
                    for(int k = 0; k <= d; k++)  
                        dp[i][j][k] = -1;
            
               cout << solve(n, m, d, d) << endl;
        }

    }        
        
    return 0;
}