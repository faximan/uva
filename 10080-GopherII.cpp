//
//  10080 - Gopher II.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-19.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define MAX_SOURCES 100
#define MAX_DESTS 100

using namespace std;

struct vsrc;
struct vdest
{
	vsrc* conn; // Set to 0 or suggest connections, counted iff 0
	vsrc* sugg; // Suggestion to new connection
};
struct vsrc
{
	vector<vdest*> d;
	vdest* conn; // Set to 0 or suggest connections, counted iff 0
	vsrc* aug; // Sources: Augmenting path start (= 0 iff not queued)
};

struct point
{
    double x, y;
};

vsrc vs[MAX_SOURCES];
int nums;
vdest vd[MAX_DESTS];
int numd;

int s, v;

void FixAugPath(vdest* dest)
{
	for(;;)
	{
		vsrc* src = dest->sugg;
		// Add src->dest
		dest->conn = src;
		if(!src->conn)
		{
			src->conn = dest;
			break;
		}
		// src already used, fix the src's connection too
		vdest* other = src->conn;
		src->conn = dest;
		dest = other;
	}
}

int BipartiteMatching() {
	int flow = 0;
	bool foundPath;
	do
	{
		vsrc* q[MAX_SOURCES];
		int qs = 0, qe = 0;
		foundPath = false;
		// Find all potential beginnings of shortest augmenting paths
		for(int i = 0; i < nums; ++i)
		{
			if((vs[i].aug = (vs[i].conn ? 0 : &vs[i])))
				q[qe++] = &vs[i]; // Push to queue if no connection
		}
		for(int j = 0; j < numd; ++j)
			vd[j].sugg = 0;
		// Find all endings of shortest (all same lengths) aug-paths
		while(!foundPath && qs < qe)
		{
			// Let the BFS go through the next layer
			for(int qecl = qe;qs < qecl; ++qs) // End of current layer
			{
				vsrc* src = q[qs];
				if(src->aug->conn) // My augmenting path start is
					continue; // already used
				// Check edges
				for(int i = 0; i < src->d.size(); ++i)
				{
					vdest* dest = src->d[i];
					if(dest == src->conn) // Find a better one than
						continue; // the current connection
					if(dest->sugg) // Already in some other
						continue; // augmenting path
					dest->sugg = src;
					if(!dest->conn)
					{
						foundPath = true;
						FixAugPath(dest);
						++flow;
						break; // Found a path
					}
					vsrc* o = dest->conn;
					if(!o->aug)
					{ // Push to queue, next layer due to qe >= qecl
						q[qe++] = o;
						o->aug = src->aug;
					}
				}
			}
		}
	} while(foundPath);
	return flow;
}

int main()
{
    while(cin >> nums >> numd >> s >> v)
    {
        point coords[nums];
        for (int i = 0; i < nums; i++) {
            cin >> coords[i].x >> coords[i].y;
            vs[i].d.clear();
            vs[i].conn = 0;
        }
        for (int i = 0; i < numd; i++) {
            vd[i].conn = 0;
            double dx, dy;
            cin >> dx >> dy;
            for (int j = 0; j < nums; j++) {
                if(sqrt(pow(dx-coords[j].x,2) + pow(dy-coords[j].y,2)) / (double)v <= s + 1e-10){
                     vs[j].d.push_back(&vd[i]);
                }
            }
        }
        cout << nums - BipartiteMatching() << endl;
    }
    return 0;
}

