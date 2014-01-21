//
//  10816 - Travel in the desert.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-19.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>

#define MAX_VERTICES 101
#define INF 1e10
#define EPS 1e-5

using namespace std;

struct vertex;

struct edge {
	vertex* to;
	double temp;
    double weight;
};

struct vertex
{
    int index;
	vector<edge> out;
	double temp, weight; // Current cost
	vertex* prev; // Back tracing
};

vertex v[MAX_VERTICES];
int numv, nume, s, t;

typedef pair<double, vertex*> elem;

bool ShortestPath(double maxTemp, bool first)
{
    vertex* source = &v[s];
    vertex* dest = &v[t];
    
	for(int i = 0; i < numv; ++i)
	{
        v[i].index = i;
		if(first)
            v[i].temp = INF;
        else
            v[i].weight = INF;
		v[i].prev = 0; // 0 at end if not on the path to dest
    } 
	source->weight = 0.0;
    source->temp = 0.0;
    
	priority_queue<elem, vector<elem>, greater<elem> > pq;
	pq.push(elem(0.0, source));
	while(!pq.empty())
	{
		elem ce = pq.top();
		vertex* cur = ce.second;
		pq.pop();
	
        if((first && (ce.first - cur->temp > EPS || ce.first - cur->temp < -EPS) ) || (!first && (ce.first - cur->weight > EPS || ce.first - cur->weight < -EPS)))
			continue; // Already processed
		
        
        if(cur == dest)
			return true;
		for(vector<edge>::iterator it = cur->out.begin(); 
            it != cur->out.end(); ++it) // Go through the edges
		{
			double newCost;
            if(first)
                newCost = max(cur->temp, it->temp);
            else
            {
                newCost = cur->weight + it->weight;
                if(it->temp > maxTemp)
                    newCost = INF;
            }
                
                
			if((first && newCost < it->to->temp) || (!first && newCost < it->to->weight))
			{
                if(first)
                    it->to->temp = newCost;
                else
                    it->to->weight = newCost;
				it->to->prev = cur;
				pq.push(elem(newCost, it->to));
			}
		}
	}
	return false; // No way to reach the end
}

void print_road(int cur)
{
    if(cur == s)
    {
        printf("%d", s+1);
        return ;
    }
    
    print_road(v[cur].prev->index);
    printf(" %d", cur+1);
}

int main()
{
    while(cin >> numv >> nume)
    {
        for (int i = 0; i < MAX_VERTICES; i++) {
            v[i].out.clear();
            v[i].prev = 0;
        }
        
        cin >> s >> t;
        s--; t--;
        edge e;
        for (int i = 0; i < nume; i++) {
            int x, y;
            double r, d;
            cin >> x >> y >> r >> d;
            x--; y--;
            e.weight = d;
            e.temp = r;
            e.to = &v[y];
            v[x].out.push_back(e);
            e.to = &v[x];
            v[y].out.push_back(e);
        }
        ShortestPath(-1, true);
        ShortestPath(v[t].temp, false);
        
        print_road(t);
        printf("\n%0.1lf %0.1lf\n", v[t].weight, v[t].temp);        
    }
    
    
    return 0;
}*/
