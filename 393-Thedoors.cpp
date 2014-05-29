//
//  393 - The doors.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct door
{
	double x;
	double y[4];
};

struct point
{
	double x,y;
};

door d[20];
point p[100];

#define MAX_V 100
#define INF 0x7FFFFFFF
#define EPS 1e-8

double weight[MAX_V][MAX_V];
double cost[MAX_V];
int prev[MAX_V]; // prev for backtracking
int numv = 0;
typedef pair<double, int> elem;

bool ShortestPath(int source, int dest)
{
	for(int i = 0; i < numv; ++i)
	{
		cost[i] = INF;
		prev[i] = -1; // -1 at end if not on the path to dest
	}
	cost[source] = 0;

	priority_queue<elem, vector<elem>, greater<elem> > pq;
	pq.push(elem(0.0, source));
	while(!pq.empty())
	{
		double curCost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if(curCost != cost[cur])
			continue; // Already processed
		if(cur == dest)
			return true;
		for(int i = 0; i < numv; ++i) // Go through the edges
		{
			double newCost = cost[cur] + weight[cur][i];
			if(newCost < cost[i]) {
				cost[i] = newCost;
				prev[i] = cur;
				pq.push(elem(newCost, i));
			}
		}
	}
	return false; // No way to reach the end
}

int main()
{
	int n;
	while(true)
	{
		cin >> n;
		if(n == -1)
			break;

		numv = 1;
		p[0].x = 0;
		p[0].y = 5;

		for(int i = 0; i < n; i++)
		{
			cin >> d[i].x;
			for(int j = 0; j < 4; j++)
			{
				cin >> d[i].y[j];
				p[i*4+j+1].x = d[i].x;
				p[i*4+j+1].y = d[i].y[j];
			}
			numv += 4;
		}

		p[numv].x = 10;
		p[numv++].y = 5;

		memset(weight, INF, sizeof(weight));

		for(int i = 0; i < numv; i++)
			for(int j = i+1; j < numv; j++)
			{
				if(fabs(p[i].x - p[j].x) < EPS)
					continue;

				double k = (p[j].y-p[i].y) / (p[j].x - p[i].x);
				double m = p[j].y - k * p[j].x;

				bool ok = true;
				for(int l = 0; l < n; l++)
				{
					if(d[l].x > p[i].x && d[l].x < p[j].x)
					{
						double y = k * d[l].x + m;
						if((y > 0 && y < d[l].y[0] + EPS) ||
						   (y + EPS > d[l].y[1] && y < d[l].y[2] + EPS) ||
						   (y + EPS > d[l].y[3] && y < 10 + EPS))
							ok = false;
					}
				}
				if(ok)
					weight[i][j] = sqrt(pow(p[i].x-p[j].x,2) + pow(p[i].y-p[j].y,2));

			}
		ShortestPath(0, numv-1);
		printf("%.2f\n", cost[numv-1]);
	}
	return 0;
}
