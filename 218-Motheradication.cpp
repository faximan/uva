//
//  218 - Moth eradication.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct point {
	double x, y;
	bool operator<(const point& rhs) const
	{
		return (y < rhs.y || (y == rhs.y && x < rhs.x));
	}
};
#define CALC_DET(p1, p2, p3) \
double x1 = p2.x - p1.x; \
double y1 = p2.y - p1.y; \
double x2 = p3.x - p1.x; \
double y2 = p3.y - p1.y; \
double det = x1*y2 - x2*y1;

struct angle_compare
{
	point p; // Leftmost lower point
	angle_compare(const point& p) : p(p) { }
	
	bool operator()(const point& lhs, const point& rhs)
	{
		CALC_DET(p, lhs, rhs)
		if(det == 0) // Furthest first if same direction will keep all
			return (x1*x1+y1*y1 > x2*x2+y2*y2); // points at the line
		return (det < 0); // Counterclockwise, compare with determinant...
	}
};

int ConvexHull(vector<point>& p, int* res)
{ // Returns the number of points in the convex polygon
  // Find the first leftmost lower point
	swap(*min_element(p.begin(), p.end()), p.front());
	sort(p.begin()+1, p.end(), angle_compare(p.front()));
	// p.erase(unique(p.begin(), p.end()) ,p.end());
	
	res[0] = 0; res[1] = 1;
	int n = 2;
	for(int i = 2; i < p.size(); ++i)
	{
		// All consecutive points should be counter clockwise
		do {
			CALC_DET(p[res[n-2]], p[res[n-1]], p[i])
			if(det <= 0) // Keep if det = 0, points on the same line
				break; // Set to det > 0 to remove points on the same line
		} while(--n > 1);
		res[n++] = i;
	}
	return n;
}
int main()
{
	int n;
	int casenr = 0;
	while(true)
	{
		casenr++;
		cin >> n;
		
		if(!n)
			break;
		
		if(casenr!=1)
			cout << endl;
		
		vector<point>p;
		for(int i = 0; i < n; i++)
		{
			point pp;
			cin >> pp.x >> pp.y;
			p.push_back(pp);
		}
		
		int res[10000];
		cout << "Region #" << casenr << ":" << endl;
		
		if(n==1)
		{
			cout << "(" << p[res[0]].x << "," << p[res[0]].y << ")" << endl << "Perimeter length = 0.00" << endl;
			continue;
		}
		
		int sol = ConvexHull(p,res);
		cout.precision(1);

		
		point curpoint = p[res[0]];
		double perm = 0;
		for(int i = 0; i < sol; i++)
		{
			if(i) cout << "-";
			cout << fixed << "(" << p[res[i]].x << "," << p[res[i]].y << ")";
			perm += sqrt(pow(curpoint.x-p[res[i]].x,2) + pow(curpoint.y-p[res[i]].y,2));
			curpoint = p[res[i]];
		}
		cout << fixed << "-(" << p[res[0]].x << "," << p[res[0]].y << ")";
		perm += sqrt(pow(curpoint.x-p[res[0]].x,2) + pow(curpoint.y-p[res[0]].y,2));
		cout.precision(2);
		cout << fixed << endl << "Perimeter length = " << perm << endl;
			
	}
	return 0;
}*/