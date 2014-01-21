//
//  668 - Parliament.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int m;
	cin >> m;
	bool first = true;
	while(m--)
	{
		int n;
		cin >> n;
		
		if(!first)
			cout << endl;
		first = false;
		
		vector<int>v;
		
		for(int i = 2; i <= n; i++)
		{
			v.push_back(i);
			n -= i;
		}
		
		for(int i = v.size()-1; i >= 0 && n > 0; i--)
		{
			v[i]++;
			n--;
		}
		
		if(n > 0)
			v[v.size()-1] += n;
		
		for(int i = 0; i < v.size(); i++)
		{
			if(i)
				cout << " ";
			cout << v[i];
		}
		cout << endl;		
	}
}*/