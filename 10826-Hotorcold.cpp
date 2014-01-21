//
//  10826 - Hot or cold.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-02.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <math.h>
#include <cassert>

#define INF 15

using namespace std;
int n;
int dp[402][402];

int solve(int a, int b, int c)
{
    if(a == b)
        return (c == a) ? 1 : 2;
    
    int d = c-a;
    if(d < 0)
        d = b - a - d;
    
    if(dp[b-a][d] < INF)
        return dp[b-a][d];
    
    for (int x = a; x <= b; x++) 
    {
        if(x == c)
            continue;
        
        int g1 = 0;
        int g2 = 0;       
        
        if(x < c)
        {       
            if((c+x+1)/2 <= b)
            {
                //colder
                g1 = solve(max(a,(x+c+1)/2), b, x);
            }
            
            //warmer
            g2 = solve(a, min(b,(x+c)/2), x); 
        }
        else if(x > c)
        {
            if((x+c)/2 >= a)
            {
                //colder
                g1 = solve(a, min((x+c)/2,b), x);
            }
            
            //warmer
            g2 = solve(max(a,(x+c+1)/2), b, x);
        }
        
        dp[b-a][d] = min(dp[b-a][d], max(g1,g2)+1);      
    }    
    return dp[b-a][d];
}

int main()
{
    for (int i = 0; i < 402; i++) 
        for(int j = 0; j < 402; j++)
                dp[i][j] = INF;
    
    while (true) 
    {
        cin >> n;
        if( n== 0) break;      
        
        int res = INF;
        for (int i = 1; i <= n; i++) 
        {
            res = min(res, solve(1, n, i));
        }
        cout << res << " guess(es) required." << endl;
    }
    
    return 0;
}
*/