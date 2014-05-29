//
//  707 - Robbery.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-06.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#define UNKNOWN 0
#define OCCUPIED 1
#define EMPTY 2

using namespace std;

int pos[101][101][101];
int W, H, t;


int solve(int x, int y, int time)
{
    if(x < 1 || y < 1 || x > W || y > H)
        return OCCUPIED;
    if(pos[x][y][time] != UNKNOWN)
        return pos[x][y][time];
    if(time == 1){
        pos[x][y][time] = EMPTY;
          return EMPTY;
    }

    int a = solve(x,y,time-1);
    int b = solve(x-1,y,time-1);
    int c = solve(x+1,y,time-1);
    int d = solve(x,y-1,time-1);
    int e = solve(x,y+1,time-1);

    if(a == EMPTY || b == EMPTY || c == EMPTY || d == EMPTY ||e == EMPTY)
        pos[x][y][time] = EMPTY;
    else
        pos[x][y][time] = OCCUPIED;
    return pos[x][y][time];
}

int main()
{

    int c = 0;
    while(true)
    {
        cin >> W >> H >> t;
        if(W == 0) break;

        c++;

        for (int i = 0; i <= W; i++)
            for (int j = 0; j <= H; j++)
                for (int k = 0; k <= t; k++)
                    pos[i][j][k] = UNKNOWN;

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int ti, left, top, right, bottom;
            cin >> ti >> left >> top >> right >> bottom;

            for (int a = left; a <= right; a++)
                for (int b = top; b <= bottom; b++)
                    pos[a][b][ti] = OCCUPIED;
        }

        int ok = 0;
        for (int i = 1; i <= W; i++)
            for (int j = 1; j <= H; j++)
                if(solve(i, j, t) == EMPTY)
                    ok = 1;

        cout << "Robbery #" << c << ":" << endl;

        if(!ok)
            cout << "The robber has escaped." << endl << endl;

        else
        {
            ok = 0;
            for (int i = 1; i <= t; i++) {
                int x = 0;
                int y = 0;
                for (int j = 1; j <= W; j++) {
                    for (int k = 1; k <= H; k++) {

                        if(pos[j][k][i] == EMPTY)
                        {
                            if(x == 0 && y == 0)
                            {
                                x = j;
                                y = k;
                            }
                            else
                            {
                                x = -1;
                                y = -1;
                            }
                        }
                    }
                }
                if(x > 0 && y > 0)
                {
                    ok = 1;
                    cout << "Time step " << i << ": The robber has been at " << x << "," << y << "." << endl;
                }
            }
            if(ok == 0)
                cout << "Nothing known." << endl;
            cout << endl;
        }
    }
    return 0;
}
