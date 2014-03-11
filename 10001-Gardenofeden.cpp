//
//  10001 - Garden of eden.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-24.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int automata[2][2][2];
int f[40];

int graph[32*2*2][32*2*2];

void create_automata(int id)
{
    for (int i = 1; i >= 0; i--) {
        for (int j = 1; j >= 0; j--) {
            for (int k = 1; k >=0; k--) {
                if(pow(2,i*4+j*2+k) <= id)
                {
                    automata[i][j][k] = 1;
                    id -= pow(2,i*4+j*2+k);
                }
                else
                    automata[i][j][k] = 0;
            }
        }
    }
}

void create_graph(int n)
{
    for (int i = 0; i < n*2*2; i++) {
        for (int j = 0; j < n*2*2; j++) {
            graph[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    if(f[(i+1)%n] == automata[j][k][l])
                    {
                        graph[i*4+j*2+k][((i+1)%n)*4+k*2+l] = 1;
                    }
                }
            }
        }
    }
}

bool solve(int cur, int index, int start, int n)
{
    if (cur == n-1)
    {
        for (int i = 0; i < 4; i++) {
            if(graph[cur*4+index][i] && start == i)
                return true;
        }
        return false;
    }

    for (int i = 0; i < 4; i++) 
    {
        if(graph[cur*4+index][(cur+1)*4+i])
            if(solve(cur+1, i, start, n))
                return true;
    }
    return false;
}

int main()
{
    int id, n;
    while(cin >> id >> n)
    {
        char c;
        for (int i = 0; i < n; i++) 
        {
            cin >> c;
            f[i] = c - '0';
        }
        
        create_automata(id);
        create_graph(n);
        
        int sol = 0;
        for (int i = 0; i < 4; i++) 
        {
            if(sol || solve(0, i, i, n))
                sol = 1;
        }
        
        if(sol)
            cout << "REACHABLE" << endl;
        else
            cout << "GARDEN OF EDEN" << endl;
    }
        
    return 0;
}

