//
//  11101 - Mall Mania.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-08.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <queue>

#define INF 0x7FFFFFFF

using namespace std;

struct point 
{
    int x,y,dist;
};

int g[2001][2001];

int main()
{
    int a, b;
    while(true)
    {
        queue<point>q;
        cin >> a;
        if( a==0) break;
        
        for (int i = 0; i < 2001; i++)
            for (int j = 0; j < 2001; j++)
                g[i][j] = -1;
        
        int x, y;
        for (int i = 0; i < a; i++) 
        {
            cin >> x >> y;
            point p;
            p.x = x; p.y = y; p.dist = 0;
            q.push(p);
        }
        
        cin >> b;
        for (int i = 0; i < b; i++) {
            cin >> x >> y;
            g[x][y] = 1;
        }

        while (true)
        {
            point p = q.front();
            q.pop();
            
            if(p.x < 0 || p.y < 0 || p.x > 2000 || p.y > 2000 || g[p.x][p.y] == 0)
                continue;
            
            if(g[p.x][p.y] == 1)
            {
                cout << p.dist << endl;
                break;
            }
            g[p.x][p.y] = 0;
            p.dist++;
            
            p.x--;
            q.push(p);
            
            p.x += 2;
            q.push(p);
            
            p.x--;
            p.y--;
            q.push(p);
            
            p.y += 2;
            q.push(p);
        }         
    }    
    return 0;
}
*/