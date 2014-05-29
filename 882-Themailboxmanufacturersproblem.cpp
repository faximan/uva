//
//  882 - The mailbox manufacturers problem.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-02.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define INF 0x7FFFFFFF

using namespace std;

int dp[105][105][11];

int solve(int l, int u, int left)
{
    if(dp[l][u][left] != -1)
        return dp[l][u][left];

    int res = INF;

    for (int i = l+1; i <= u; i++)
        res = min(res, i+max(solve(l, i-1, left-1), solve(i, u, left)));

    dp[l][u][left] = res;
    return dp[l][u][left];
}


int main()
{
    for (int i = 0; i < 105; i++)
    {
        for (int j = i+1; j < 105; j++)
        {
            for (int k = 2; k < 11; k++)
                dp[i][j][k] = -1;
            dp[i][j][1] = (j*(j+1))/2 - ((i+1)*i)/2;

        }
        for (int j = 0; j < 11; j++)
            dp[i][i][j] = 0;
    }

    int c;
    cin >> c;
    while(c--)
    {
        int k, m;
        cin >> k >> m;
        cout << solve(0, m, k) << endl;
    }

    return 0;
}
