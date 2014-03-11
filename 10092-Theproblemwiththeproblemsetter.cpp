//
//  10092 - The problem with the problem setter.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <queue>

#define MAX_VERTICES 2000
#define MAX_EDGES 300000

using namespace std;

struct vertex;
struct edge
{
	vertex *from, *to;
	int used, mi, ma; // min may be -max
	
	vertex* opposite(vertex* p)
	{ return (p == from ? to : from); }
	int left(vertex* p) // Source vertex, capacity left from p
	{ return (p == from ? ma - used : used - mi); }
	void add(vertex* p, int flow) // Source vertex, add from p
	{ used += (p == from ? flow : -flow); }
};
struct vertex
{
	int myindex;
	vector<edge*> e; // Edge index
	edge* in; // Incoming edge, used in the breath first search
};

vertex v[MAX_VERTICES];
int numv = 0;
edge e[MAX_EDGES];

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

int main()
{
	int nk, np;
	while(true)
	{
		cin >> nk >> np;
		if(!nk && !np)
			break;
		numv = 2 + nk + np;
		int sum = 0;
		int nume = 0;
		
		for(int i = 0; i < MAX_VERTICES; i++)
			v[i].e.clear();
		
		for(int i = 0; i < nk; i++)
		{
			int cap;
			cin >> cap;
			sum += cap;
			edge ee;
			ee.used = 0;
			ee.mi = 0;
			ee.ma = cap;
			ee.from = &v[0];
			ee.to = &v[i+1];
			e[nume] = ee;
			v[0].e.push_back(&e[nume]);
			v[i+1].e.push_back(&e[nume++]);			
		}
		
		for(int i = 0; i < np; i++)
		{
			int antal;
			cin >> antal;
			edge ee;
			ee.used = 0;
			ee.mi = 0;
			ee.ma = 1;
			ee.from = &v[nk+i+1];
			ee.to = &v[numv-1];
			e[nume] = ee;
			v[nk+i+1].e.push_back(&e[nume]);
			v[numv-1].e.push_back(&e[nume++]);	

			for(int j = 0; j < antal; j++)
			{
				int dest;
				cin >> dest;
				edge ee;
				ee.used = 0;
				ee.mi = 0;
				ee.ma = 1;
				ee.from = &v[dest];
				ee.to = &v[nk+i+1];
				e[nume] = ee;
				v[nk+i+1].e.push_back(&e[nume]);
				v[nk+i+1].myindex = i+1;
				v[dest].e.push_back(&e[nume++]);	
			}
		}
		
		int res = MaxFlow(&v[0], &v[numv-1]);
		if(res==sum)
		{
			cout << "1" << endl;
			for(int i = 1; i <= nk; i++)
			{
				bool first = false;
				for(int j = 0; j < v[i].e.size(); j++)
				{
					edge *ee = v[i].e[j];
					if(ee->used && ee->from != &v[0])
					{
						if(first)
							cout << " ";
						first = true;
						vertex *vv = ee->to;
						cout << vv->myindex;
					}
				}
				cout << endl;
			}
		}
		else
			cout << "0" << endl;
	}
	return 0;
}