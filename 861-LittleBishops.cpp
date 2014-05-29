//
//  861 - Little Bishops.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-22.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int n, k;

int d1[16];
int d2[16];

unsigned long long dp[9][70];

unsigned long long res;

void solve(int posx, int posy, int nbr)
{
    if(posx == n)
    {
        solve(0, posy+1, nbr);
        return;
    }

    if(posy == n)
    {
        return;
    }

    if(d1[posx+posy] == 0 && d2[7-posx + posy] == 0)
    {
        d1[posx+posy] = 1;
        d2[7-posx+posy] = 1;

        if(nbr+1 == k)
            res++;
        else
            solve(posx+1, posy, nbr+1);

        d1[posx+posy] = 0;
        d2[7-posx+posy] = 0;
    }
    solve(posx+1, posy, nbr);
}

unsigned long long solve()
{
    if(dp[n][k])
        return dp[n][k];

    if(k > 14)
        return 0;
    else if(n == 8 && k>= 6)
    {
        if(k == 14) return 256;
        if(k == 13) return 20224;
        if(k == 12) return 489536;
        if(k == 11) return 3672448;
        if(k == 10) return 12448832;
        if(k == 9)  return 22057472;
        if(k == 8)  return 22522960;
        if(k == 7)  return 14082528;
        if(k == 6)  return 5599888;
    }
    else if(n == 7 && k >= 6)
    {
        if(k == 12) return 128;
        if(k == 11) return 5792;
        if(k == 10) return 81184;
        if(k == 9)  return 389312;
        if(k == 8)  return 867328;
        if(k == 7)  return 1022320;
        if(k == 6)  return 692320;
        if(k == 5)  return 282248;
        if(k == 4)  return 70792;
        if(k == 3)  return 10894;
        else
            return 0;
    }

    else if(k != 0)
    {
        res = 0;
        solve(0, 0, 0);
    }
    else
        return 1;
    return res;
}

int main()
{
    while(true)
    {
        scanf("%d %d", &n, &k);

       if(n == 0 && k == 0)
            break;

        unsigned long long res = solve();
        dp[n][k] = res;
        printf("%lld\n", res);
    }

    return 0;
}
