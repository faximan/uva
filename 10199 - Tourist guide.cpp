//
//  10199 - Tourist guide.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

string names[101];
int numv, nume;

map<string, int>m;

vector<int>adj[101];

struct vertex
{
	int dfsnum, low, dfslevel, index, numChildren;
};

vertex allv[101];

vector<string>res;

int dfsCounter;

set<string>found;

void apdfs(vertex& v)
{
	v.dfsnum = ++dfsCounter;
	v.low = v.dfsnum;
	
	for (int i = 0; i < adj[v.index].size(); i++) 
	{
		if(allv[adj[v.index][i]].dfsnum == -1)
		{
			allv[adj[v.index][i]].dfslevel = 1+v.dfslevel;
			v.numChildren++;
			
			apdfs(allv[adj[v.index][i]]);
			
			v.low = min(v.low,allv[adj[v.index][i]].low); 
			if(v.dfsnum==1)
			{
				if(v.numChildren>=2 && !found.count(names[v.index]))
				{
					res.push_back(names[v.index]);
					found.insert(names[v.index]);
				}
			}
			
			else if(allv[adj[v.index][i]].low >= v.dfsnum&& !found.count(names[v.index]))
			{
					res.push_back(names[v.index]);
					found.insert(names[v.index]);
			}
			
		}else if(allv[adj[v.index][i]].dfslevel < v.dfslevel-1)
			v.low = min(v.low, allv[adj[v.index][i]].dfsnum);
	}
}	

int main()
{
	int casenr = 0;
	while (true) {
		found.clear();
		casenr++;
		cin >> numv;
		if(!numv)
			break;
		if(casenr!=1)
			cout << endl;
		res.clear();
		for (int i = 0; i < numv; i++) {
			cin >> names[i];
			m[names[i]] = i;
			adj[i].clear();
			allv[i].dfsnum = -1;
			allv[i].index = i;
			allv[i].numChildren = 0;
		}
		
		cin >> nume;
		
		for (int i = 0; i< nume; i++) {
			string a, b;
			cin >> a >> b;
			adj[m[a]].push_back(m[b]);
			adj[m[b]].push_back(m[a]);
		}
		
		for (int i = 0; i < numv; i++) {
			if(allv[i].dfsnum != -1)
				continue;
			dfsCounter = 0;
			apdfs(allv[i]);
		}
		sort(res.begin(), res.end());
		
		cout << "City map #" << casenr << ": " << res.size() <<" camera(s) found" << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << endl;
		}		
	}
	return 0;
}*/