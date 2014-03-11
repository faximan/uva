//
//  10763 - Foreign exchange.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-14.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main()
{
	while(true)
	{
		int n;
		cin >> n;
		if(!n)
			break;
		map<pair<int, int>, int >s;
		for(int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			s[make_pair(a,b)]++;
		}
		
		bool ok = true;
		map<pair<int, int>, int>::iterator it;
		for(it = s.begin(); it!=s.end(); it++)
		{
			pair<int,int>cur = it->first;
			pair<int,int>next = make_pair(cur.second, cur.first);
			if(s[next] != s[cur])
				ok = false;
		}
		
		if(ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}