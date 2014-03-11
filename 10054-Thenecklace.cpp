//
//  10054 - The necklace.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-28.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<int>v[1001];

int g[1001][1001];

int vis[1001];

list<pair<int, int> >cycle;

int maxd;

bool dfs(int cur)
{
	if(v[cur].size()%2 != 0)
		return false;
	vis[cur] = 1;
	for (int i = 0; i < v[cur].size(); i++) {
		if(vis[v[cur][i]])
			continue;
		if(!dfs(v[cur][i]))
			return false;
	}
	return true;
}

void euler(list<pair<int, int> >::iterator i, int u)
{
	for( int v = 0; v <= maxd; v++ ) 
		if( g[u][v] ) 
		{
			g[u][v]--;
			g[v][u]--;
			euler(cycle.insert(i,make_pair(v,u)),v); 
		}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) 
	{
		if(i!=1)
			printf("\n");
		printf("Case #%d\n", i);
		cycle.clear();
		int n;
		scanf("%d",&n);
		int a, b;
		maxd = 0;
		
		for(int j = 0; j < 1001; j++)
		{
			v[j].clear();	
			vis[j] = 0;
			for (int k = 0; k < 1001; k++)
				g[j][k] = 0;
		}
		
		for (int j = 0; j < n; j++) 
		{
			scanf("%d %d", &a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
			g[a][b]++;
			g[b][a]++;
			maxd = max(maxd, max(a,b));
		} 
		
		if(!dfs(a))
		{
			printf("some beads may be lost\n");
			continue;
		}
		bool ok = true;
		for (int j = 0; j <= maxd; j++) {
			if(v[j].size() && !vis[j])
				ok = false;
		}
		if(!ok)
		{
			printf("some beads may be lost\n");
			continue;
		}
		
		euler(cycle.begin(), a);

		for(list<pair<int, int> >::iterator it = cycle.begin(); it != cycle.end(); it++)
		{
			printf("%d %d\n", (*it).first, (*it).second);
		}
	}
	return 0;
}