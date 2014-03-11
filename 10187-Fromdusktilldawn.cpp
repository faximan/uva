//
//  10187 - From dusk till dawn.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define MAX_VERTICES 100

using namespace std;

map<string, int>m;

struct vertex;
struct edge {
	vertex* to;
	int dept,arr;
};

struct vertex
{
	vector<edge> out;
	int cost; // Current cost
	vertex* prev; // Back tracing
    int time;
};

vertex v[MAX_VERTICES];
int numv = 0;
typedef pair<int, vertex*> elem;

bool ShortestPath(vertex* source, vertex* dest)
{
	for(int i = 0; i < numv; ++i)
	{
		v[i].cost = 0x3FFFFFFF;
		v[i].prev = 0; // 0 at end if not on the path to dest
        v[i].time = 0;
	}
	source->cost = 0;
    
	priority_queue<elem, vector<elem>, greater<elem> > pq;
	pq.push(elem(0, source));
	while(!pq.empty())
	{
		elem ce = pq.top();
		vertex* cur = ce.second;
		pq.pop();
		if(ce.first != cur->cost)
			continue; // Already processed
		if(cur == dest)
			return true;
		for(vector<edge>::iterator it = cur->out.begin(); 
            it != cur->out.end(); ++it) // Go through the edges
		{
			int newCost = cur->cost;
            if(cur->time > it->dept)
                newCost++;
            
			if(newCost < it->to->cost)
			{
				it->to->cost = newCost;
				it->to->prev = cur;
                it->to->time = it->arr;
				pq.push(elem(newCost, it->to));
			}
		}
	}
	return false; // No way to reach the end
}

int main()
{
    int cases;
    cin >> cases;
    for (int c = 1; c <= cases; c++) 
    {
        m.clear();
        int routes;
        cin >> routes;
        numv = 0;
        
        for (int i = 0; i < MAX_VERTICES; i++)
            v[i].out.clear();
        
        for (int i = 0; i < routes; i++) 
        {
            string a, b;
            int dept, length;
            cin >> a >> b >> dept >> length;
            if(!m.count(a))
                m[a] = numv++;
            if(!m.count(b))
                m[b] = numv++;
            if((dept >= 18 || dept <= 6) && ((dept+length)%24 <= 6 || (dept+length)%24 >= 18) && length<=12)
            {
                edge e;
                e.to = &v[m[b]];
                e.dept = (dept+12)%24;
                e.arr = e.dept + length;
                v[m[a]].out.push_back(e);
            }
        }
        
        string a, b;
        cin >> a >> b;
        
        cout << "Test Case " << c << "." << endl;
        
        if(!m.count(a) || !m.count(b) || !ShortestPath(&v[m[a]], &v[m[b]]))
        {
            cout << "There is no route Vladimir can take." << endl;
        }
        else
            cout << "Vladimir needs " << v[m[b]].cost << " litre(s) of blood." << endl;
    }
  
    return 0;
}


