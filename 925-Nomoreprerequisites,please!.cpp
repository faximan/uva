//
//  925 - No more prerequisites, please!.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string,int>names;
map<int,string>numbers;

int g[121][121];
int n;

void solve(int parent, int cur)
{
	for(int i = 0; i < n; i++)
	{
		if(!g[cur][i])
			continue;
		solve(parent,i);
		if(parent != cur && g[parent][i])
			g[parent][i] = 0;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			names[s] = i;
			numbers[i] = s;

			for(int j = 0; j < n; j++)
				g[i][j] = 0;
		}

		int p;
		cin >> p;
		for(int i = 0; i < p; i++)
		{
			string c1;
			cin >> c1;
			int pre;
			cin >> pre;
			for(int j = 0; j < pre; j++)
			{
				string c2;
				cin >> c2;
				g[names[c1]][names[c2]] = 1;
			}
		}

		for(int i = 0; i < n; i++)
			solve(i,i);

		vector<pair<string, vector<string> > >v;

		for(int i = 0; i < n; i++)
		{
			string cur = numbers[i];
			vector<string>pre;
			for(int j = 0; j < n; j++)
				if(g[i][j])
					pre.push_back(numbers[j]);
			sort(pre.begin(), pre.end());
			if(!pre.empty())
				v.push_back(make_pair(cur, pre));
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < v.size(); i++)
		{
			cout << v[i].first << " " << v[i].second.size();
			for(int j = 0; j < v[i].second.size(); j++)
			{
				cout << " " << v[i].second[j];
			}
			cout << endl;
		}
	}
	return 0;
}
