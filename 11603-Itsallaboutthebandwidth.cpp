//
//  11603 - Its all about the bandwidth.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-09.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;
#define MAX_VERTICES 201
#define MAX_EDGES 40001
#define INF 0x3FFFFFFF

struct vertex
{
	vertex* myp;
    int index;
    
	vertex* p()
	{
		// parent != this in most cases. Better to use
		//   parent->parent != this->parent than calling
		//   parent->GetParent() all the time
		//   call all the time!
		if(myp->myp != myp) // Is my parent the root?
			myp = myp->p();
		return myp;
	}
};

struct edge
{
	vertex *from,*to;
	int weight;
    int in_use;
    
	bool operator<(const edge& rhs) const
	{
		return (weight > rhs.weight);
	}
};

vertex v[MAX_VERTICES];
int numv;
edge e[MAX_EDGES];
int nume;
int cost[MAX_VERTICES][MAX_VERTICES];

int MinimumSpanningTree()
{
    int total = 0;
	for(int i = 0; i < numv; ++i)
    {
		v[i].myp = &v[i];
        v[i].index = i;
    }
    
	sort(&e[0], &e[nume]);
	for(int i = 0; i < nume; ++i)
	{
		if(e[i].from->p() != e[i].to->p())
        {
			e[i].to->p()->myp = e[i].from->p(); // Add the edge
            total++;
            cost[e[i].to->index][e[i].from->index] = e[i].weight;
            cost[e[i].from->index][e[i].to->index] = e[i].weight;
            e[i].in_use = 1;
        }
	} 
    return total;
}

void floyd()
{
    for(int k = 0; k < numv; ++k)
        for(int i = 0; i < numv; ++i)
            for(int j = 0; j < numv; ++j)
            {
                if(i==j || i==k || j==k)
                    continue;
                    
                if(cost[i][k] == INF || cost[k][j] == INF ||cost[i][j]<INF)
                    continue;
                cost[i][j] = min(cost[i][k],cost[k][j]);
            }
}

int main()
{
    int c;
    cin >> c;
    for (int cas=1; cas <=c; cas++)
    {
        cin >> numv;
        nume = 0;
        
        for (int i = 0; i < numv; i++) 
        {
            for (int j = 0; j < numv; j++) 
            {
                cost[i][j] = INF;
                int costen;
                cin >> costen;
                
                if (i == j) 
                    cost[i][j] = 0;
                
                e[nume].from = &v[i];
                e[nume].to = &v[j];
                e[nume].weight = costen; 
                e[nume].in_use = 0;
                nume++;
            }
        }
        
        int total = MinimumSpanningTree();
        floyd();
                
        bool pos = true;

        for (int i = 0; i < nume; i++) 
            if(e[i].weight != cost[e[i].from->index][e[i].to->index])
                pos = false;

        if(!pos)
            cout << "Case #" << cas <<": Impossible" << endl;
        else
        {
            int test = 0;
            cout << "Case #" << cas <<": " << total << endl;
            for (int i = 0; i < nume; i++) 
            {
                if(e[i].in_use)
                {
                    test++;
                    cout << e[i].from->index << " " << e[i].to->index << " " << e[i].weight << endl;
                }
            }
        }
    }
    
    
    return 0;
}*/
