//
//  10047 - The monocycle.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-06.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <queue>
#include <algorithm>

#define INF 0x7FFFFFFF

using namespace std;

int dp[26][26][5][4];
int m, n;

int sr, sc, tr, tc;

char area[26][26];

struct state
{
    int row, col, color, dir, time;
};

int main()
{
    int c = 0;
    while(true)
    {
        c++;
        cin >> m >> n;
        if(m == 0) break;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> area[i][j];
                if(area[i][j] == 'S')
                {
                    sr = i;
                    sc = j;
                }else if(area[i][j] == 'T')
                {
                    tr = i;
                    tc = j;
                }
                
                for (int k = 0; k < 5; k++) {
                    for (int l = 0; l < 4; l++) {
                        dp[i][j][k][l] = INF;
                    }
                }
            }
        }
        
        queue<state>q;
        state s;
        s.row = sr;
        s.col = sc;
        s.color = 0;
        s.dir = 0;
        s.time = 0;
        q.push(s);
                
        while(!q.empty())
        {
            state cur = q.front();
            q.pop();
            
            if(cur.row < 1 || cur.row > m || cur.col < 1 || cur.col > n || area[cur.row][cur.col] == '#' || dp[cur.row][cur.col][cur.color][cur.dir] < cur.time)
                continue;
            
            dp[cur.row][cur.col][cur.color][cur.dir] = cur.time;
            
            state new_state = cur;
            new_state.time++;
            
            //turn left
            new_state.dir = (cur.dir+3)%4;
            q.push(new_state);
            
            //turn right
            new_state.dir = (cur.dir+1)%4;
            q.push(new_state);
            
            //go forward
            new_state.dir = cur.dir;
            new_state.color = (new_state.color + 1)%5;
            if(cur.dir == 0) //north
                new_state.row--;
            if(cur.dir == 1) //east
                new_state.col++;
            if(cur.dir == 2) //south
                new_state.row++;
            if(cur.dir == 3) //west
                new_state.col--;
            q.push(new_state);
        }
        
        int minimum = INF;
        for (int i = 0; i < 4; i++) 
            minimum = min(minimum, dp[tr][tc][0][i]);
        
        if(c != 1)
            cout << endl;
        if(minimum == INF)
            cout << "Case #" << c << endl << "destination not reachable" << endl;
        else
            cout << "Case #" << c << endl << "minimum time = " << minimum << " sec" << endl;
        
    }
    return 0;
}*/