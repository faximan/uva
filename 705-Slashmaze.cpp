//
//  705 - Slash maze.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>

#define BLOCKED 1
#define UNEXPLORED 0

using namespace std;

int a[250][250];
int w, h;

int cycles;
int longest;
int depth;

void flood_fill(int x, int y)
{
    if(x < 0 || y < 0 || x >= h*3 || y >= w*3)
    {
        depth = -1;
        return;
    }

    if(a[x][y] != UNEXPLORED)
        return;
    a[x][y] = BLOCKED;

    if(depth != -1)
        depth++;

    flood_fill(x+1, y);
    flood_fill(x-1, y);
    flood_fill(x, y+1);
    flood_fill(x, y-1);
}

int main()
{
    int testcase = 0;
    while(true)
    {
        testcase++;
        cycles = 0;
        longest = 0;
        cin >> w >> h;
        if(w == 0) break;

        for (int i = 0; i < 250; i++)
            for (int j = 0; j < 250; j++)
                a[i][j] = UNEXPLORED;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c;
                cin >> c;
                if(c == '\\')
                {
                    a[i*3][j*3] = BLOCKED;
                    a[i*3+2][j*3+2] = BLOCKED;
                }
                else
                {
                    a[i*3][j*3+2] = BLOCKED;
                    a[i*3+2][j*3] = BLOCKED;
                }
                a[i*3+1][j*3+1] = BLOCKED;
            }
        }

        for (int i = 0; i < h*3; i++) {
            for (int j = 0; j < w*3; j++) {
                if(a[i][j] == UNEXPLORED)
                {
                    depth = 0;
                    flood_fill(i,j);

                    if(depth > 0)
                    {
                        cycles++;
                        longest = max(longest, depth);
                    }
                }
            }
        }

        cout << "Maze #" << testcase << ":" << endl;
        if(cycles)
            cout << cycles << " Cycles; the longest has length " << longest/3 << "." << endl << endl;
        else
            cout << "There are no cycles." << endl << endl;
    }
    return 0;
}
