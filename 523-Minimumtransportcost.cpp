//
//  523 - Minimum transport cost.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-08.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <stdio.h>
#include <queue>

#define INF 0x3FFFFFFF
#define MAX_V 1000

using namespace std;

int from, to;

int tax[MAX_V];
int weight[MAX_V][MAX_V];
int cost[MAX_V], prev[MAX_V]; // prev for backtracking
int numv;

typedef pair<int, int> elem;

bool ShortestPath(int source, int dest)
{
	for(int i = 1; i <= numv; ++i)
	{
		cost[i] = 0x7FFFFFFF;
		prev[i] = -1; // -1 at end if not on the path to dest
	}
	cost[source] = 0;
    
	priority_queue<elem, vector<elem>, greater<elem> > pq;
	pq.push(elem(0, source));
	while(!pq.empty())
	{
		int curCost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if(curCost != cost[cur])
			continue; // Already processed
		if(cur == dest)
			return true;
		for(int i = 1; i <= numv; ++i) // Go through the edges
		{
			int newCost = cost[cur] + weight[cur][i] + tax[i];
			if(newCost < cost[i]) {
				cost[i] = newCost;
				prev[i] = cur;
				pq.push(elem(newCost, i));
			}
		}
	}
	return false; // No way to reach the end
}

void print_path(int cur)
{
    if(cur == from)
    {
        cout << from << "-->";
    }
    else
    {
        print_path(prev[cur]);
        cout << cur;
        if(cur != to)
            cout << "-->";
    }
}

int main()
{
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) 
    {
        numv = 0;
        char ch;
        
        while(true) // read first line to find n
        {
            scanf("%d%c", &weight[1][++numv], &ch);
            if(weight[1][numv] == -1)
                weight[1][numv] = INF;
            if(ch == '\n')
                break;
        }
        
        for(int i = 2; i <= numv; i++) //read rest of the lines
            for(int j = 1; j <= numv; j++)
            {
                scanf("%d",&weight[i][j]);
                if(weight[i][j] == -1)
                    weight[i][j] = INF;
            }
        
        for(int i = 1; i <= numv; i++)
            scanf("%d", &tax[i]);
        
        char line[1000]; 
        while (getchar() != '\n');
        while (fgets(line, 1000, stdin) && sscanf(line, "%d%d", &from, &to) == 2) 
        { 
            cout << "From " << from << " to " << to << " :" << endl;
            if(from == to)
                cout << "Path: " << from << endl << "Total cost : 0" << endl;   
            else
            {            
                ShortestPath(from, to);
                cout << "Path: ";
                print_path(to);
                cout << endl << "Total cost : " << cost[to] - tax[to] << endl;   
            }
        } 
    }
    return 0;
}*/