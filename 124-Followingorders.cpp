//
//  124 - Following orders.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-28.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int match[30][30];
int occ[30];
int vars[30];

void dfs(string cur, int depth, int maxd)
{
	if (depth == maxd)
	{
		cout << cur << endl;
		return;
	}

	for (int i = 0; i < maxd; i++)
	{
		if(occ[i])
			continue;

		bool found = false;
		for (int j = 0; j < cur.length(); j++) {
			if(match[vars[i]][cur[j]-'a'])
				found = true;
		}
		if(found)
			continue;

		occ[i] = 1;
		char next = vars[i]+'a';
		dfs(cur+next, depth+1, maxd);
		occ[i] = 0;
	}
}

int main()
{
	bool first = false;
	string s;
	while(getline(cin, s))
	{
		if(first)
			cout << endl;
		first = true;
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				match[i][j] = 0;
			}
			occ[i] = 0;
		}

		int j = 0;
		for (int i = 0; i < s.length(); i++) {
			if(s[i] != ' ')
				vars[j++] = s[i]-'a';
		}

		getline(cin, s);
		for (int i = 0; i+2 < s.length(); i+=4) {
			char a, c;
			a = s[i];
			c = s[i+2];
			match[a-'a'][c-'a'] = 1;
		}
		sort(vars,vars+j);
		dfs("",0,j);
	}
}
