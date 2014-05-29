//
//  10735 - Euler circuit.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <list>

#define MAX_VERTICES 800
#define MAX_EDGES 2000

using namespace std;

list<int>cycle;

struct vertex;
struct edge
{
	vertex *from, *to;
	int used, mi, ma; // min may be -max
	int first, other;

	vertex* opposite(vertex* p)
	{ return (p == from ? to : from); }
	int left(vertex* p) // Source vertex, capacity left from p
	{ return (p == from ? ma - used : used - mi); }
	void add(vertex* p, int flow) // Source vertex, add from p
	{ used += (p == from ? flow : -flow); }
};
struct vertex
{
	vector<edge*> e; // Edge index
	edge* in; // Incoming edge, used in the breath first search
};

vertex v[MAX_VERTICES];
int numv = 0;
int nume = 0;
edge e[MAX_EDGES];

int vv, ee;

bool AugPath(vertex* source, vertex* dest)
{
	// Breadth-first search
	for(int i = 0; i < numv; ++i)
		v[i].in = 0;
	source->in = (edge*)-1; // reinterpret_cast<edge*>(-1)

	queue<vertex*> q;
	q.push(source);
	while(!q.empty())
	{
		vertex* cur = q.front();
		q.pop();
		// Check edges
		for(vector<edge*>::iterator it = cur->e.begin();
			it != cur->e.end(); ++it)
		{
			if((*it)->left(cur) > 0)
			{
				vertex* recv = (*it)->opposite(cur);
				if(!recv->in)
				{
					recv->in = *it;
					if(recv == dest)
						return true; // Found a path
					q.push(recv);
				}
			}
		}
	}
	return false;
}

int MaxFlow(vertex* source, vertex* dest)
{
	int maxflow = 0;
	while(AugPath(source, dest))
	{
		// Find flow to add
		int flow = 0x7FFFFFFF;
		edge* e;
		vertex* sender = dest; // The sender (in the loop)
		while((e = sender->in) != (edge*)-1)
			flow=min(flow,e->left(sender=e->opposite(sender)));
		// Add the flow
		sender = dest;
		while((e = sender->in) != (edge*)-1)
			e->add(sender = e->opposite(sender), flow);
		maxflow += flow;
	}
	return maxflow;
}

int g[101][101];

void euler(list<int>::iterator i, int u)
{
	for( int w = 1; w <= vv; w++ )
		if( g[u][w] )
		{
			g[u][w]--;
			//g[w][u]--;
			euler(cycle.insert(i,u),w);
		}
}

int main()
{
	int t;
	cin >> t;

	for(int casenr = 0; casenr < t; casenr++)
	{
		if(casenr)
			cout << endl;

		cin >> vv >> ee;

		int deg[vv+2];
		memset(deg,0,sizeof(deg));
		memset(g,0,sizeof(g));

		for(int i = 0; i < MAX_VERTICES; i++)
			v[i].e.clear();

		nume = 0;

		for(int i = 1; i <= ee; i++)
		{
			int a, b;
			string c;
			cin >> a >> b >> c;
			deg[a]++;
			deg[b]++;

			edge e1,e2;
			e1.from = &v[i];
			e2.from = &v[i];
			e1.to = &v[ee+a];
			e1.first = b;
			e1.other = a;
			e2.to = &v[ee+b];
			e2.first = a;
			e2.other = b;
			e1.used = 0;
			e2.used = 0;

			if(c=="U")
			{
				e1.mi = 0;
				e2.mi = 0;
				e1.ma = 1;
				e2.ma = 1;
			}
			else
			{
				e1.mi = 0;
				e1.ma = 0;
				e2.mi = 1;
				e2.ma = 1;
			}
			e[nume] = e1;
			v[ee+a].e.push_back(&e[nume]);
			v[i].e.push_back(&e[nume++]);
			e[nume] = e2;
			v[ee+b].e.push_back(&e[nume]);
			v[i].e.push_back(&e[nume++]);

			edge se;
			se.from = &v[0];
			se.to = &v[i];
			se.used = 0;
			se.mi = 1;
			se.ma = 1;
			se.first = -1;
			e[nume] = se;
			v[i].e.push_back(&e[nume]);
			v[0].e.push_back(&e[nume++]);
		}
		bool ok = true;
		for(int i = 1; i <= vv; i++)
		{
			edge se;
			se.from = &v[ee+i];
			se.to = &v[ee+vv+1];
			se.used = 0;
			se.mi = 0;
			se.ma = deg[i]/2;
			se.first = -1;
			e[nume] = se;
			v[ee+vv+i].e.push_back(&e[nume]);
			v[ee+i].e.push_back(&e[nume++]);
			if(deg[i]%2!=0)
				ok = false;
		}

		numv = vv+ee+2;
		int maxf = MaxFlow(&v[0], &v[ee+vv+1]);

		if(!ok || maxf != ee)
		{
			cout << "No euler circuit exist" << endl;
			continue;
		}

		cycle.clear();

		for(int i = 0; i < nume; i++)
			if(e[i].used && e[i].first != -1)
				g[e[i].first][e[i].other]++;

		euler(cycle.begin(), 1);
		bool first = false;
		vector<int>v;
		for(list<int>::iterator it = cycle.begin(); it != cycle.end(); it++)
			v.insert(v.begin(),*it);

		v.push_back(1);

		for(int i = 0; i < v.size(); i++)
		{
			if(first)
				cout << " ";
			first = true;
			cout << v[i];
		}
		cout << endl;
	}
	return 0;
}
