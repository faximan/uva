//
//  270 - Lining up.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-02.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include <stdio.h>

using namespace std;

struct point {
	long long x, y;
	bool operator<(const point& rhs) const
	{
		return (y < rhs.y || (y == rhs.y && x < rhs.x));
	}
};

#define CALC_DET(p1, p2, p3) \
long long x1 = p2.x - p1.x; \
long long y1 = p2.y - p1.y; \
long long x2 = p3.x - p1.x; \
long long y2 = p3.y - p1.y; \
long long det = x1*y2 - x2*y1;

struct angle_compare
{
	point p; // Leftmost lower point
	angle_compare(const point& p) : p(p) { }
	
	bool operator()(const point& lhs, const point& rhs)
	{
		CALC_DET(p, lhs, rhs)
		if(det == 0) // Furthest first if same direction will keep all
			return (x1*x1+y1*y1 > x2*x2+y2*y2); // points at the line
		return (det > 0); // Counterclockwise, compare with determinant...
	}
};

int main()
{
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	getline(cin, s);
	bool ok = false;
	while(n--)
	{
		if(ok)
			cout << endl;
		ok = true;
		vector<point>v;
		while(getline(cin, s) && cin.peek()!=EOF)
		{
			if(s=="")
				break;
			stringstream ss(s);
			point p;
			ss>>p.x >> p.y;
			v.push_back(p);
		}
		
		sort(v.begin(), v.end());
		int best = 0;
		for(int i = 0; i < v.size(); i++)
		{
			sort(v.begin()+i+1, v.end(), angle_compare( v[i]));
			int res = 0;
			for(int j = i+1; j < v.size(); j++)
			{
				int res2 = 2;
				while(j+1<v.size())
				{
					CALC_DET( v[i], v[j], v[j+1]);
					if(det!=0)
						break;
					j++;
					res2++;
				}
				res = max(res, res2);
			}
			best = max(best, res);
		}
		cout << best << endl;
	}
	return 0;
}
*/