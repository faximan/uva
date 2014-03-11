//
//  10078 - Art gallery.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x, y;
	bool operator<(const point& rhs) const
	{
		return (y < rhs.y || (y == rhs.y && x < rhs.x));
	}
};
#define CALC_DET(p1, p2, p3) \
int x1 = p2.x - p1.x; \
int y1 = p2.y - p1.y; \
int x2 = p3.x - p1.x; \
int y2 = p3.y - p1.y; \
int det = x1*y2 - x2*y1;

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
			if(det >= 0) // Keep if det = 0, points on the same line
				break; // Set to det > 0 to remove points on the same line
		} while(--n > 1);
		res[n++] = i;
	}
	return n;
}

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if(n==0)break;
		
		vector<point>v;
		
		for (int i = 0; i < n; i++) {
			point p;
			cin >> p.x >> p.y;
			v.push_back(p);
		}
		
		int res[51];
		int solve = ConvexHull(v, res);
		
		if(solve!=n)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
