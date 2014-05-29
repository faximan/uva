//
//  11168 - Airport.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-17.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <cassert>

#define INF 15000000;

using namespace std;

struct point {
	int x, y;
	bool operator<(const point& rhs) const
	{
		return (y < rhs.y || (y == rhs.y && x < rhs.x));
	}
    bool operator==(const point& rhs) const
	{
		return (y == rhs.y && x == rhs.x);
	}
};

vector<point>v;

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
		if(det == 0){
            long long l1 = x1*x1+y1*y1;
            long long l2 = x2*x2+y2*y2;
            return (l1 > l2); // points at the line
        }
		return (det > 0); // Counterclockwise, compare with determinant...
	}
};

int ConvexHull(vector<int>& res)
{ // Returns the number of points in the convex polygon
	// Find the first leftmost lower point

	res[0] = 0; res[1] = 1;
	int n = 2;
	for(int i = 2; i < v.size(); ++i)
	{
		// All consecutive points should be counter clockwise
		do {
			CALC_DET(v[res[n-2]], v[res[n-1]], v[i])
			if(det > 0) // Keep if det = 0, points on the same line
				break; // Set to det > 0 to remove points on the same line
		} while(--n > 1);
		res[n++] = i;
	}
	return n;
}

double my_abs(double a)
{
    if(a >= 0)
        return a;
    else
        return -a;
}

int main()
{
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        int n;
        cin >> n;

        long long tx = 0;
        long long ty = 0;
        point p;

        v.clear();

        for(int i = 0; i < n; i++){
            cin >> p.x >> p.y;
            tx += p.x;
            ty += p.y;
            v.push_back(p);
        }

        double ax = tx/(double)n;
        double ay = ty/(double)n;

        swap(*min_element(v.begin(), v.end()), v.front());
        sort(v.begin()+1, v.end(), angle_compare(v.front()));
        v.erase(unique(v.begin(), v.end()) ,v.end());

        vector<int> res(n);
        int nres = ConvexHull(res);

        if(v.size() < 3 || nres < 3)
        {
            printf("Case #%d: 0.000\n", cas);
            continue;
        }

        double mindist = INF;

        for (int i = 0; i < nres; i++) {
            int x1 = v[res[i]].x;
            int x2 = v[res[(i+1)%nres]].x;
            int y1 = v[res[i]].y;
            int y2 = v[res[(i+1)%nres]].y;

            mindist = min(mindist, my_abs((x2-x1)*(y1-ay)-(x1-ax)*(y2-y1))/(double)(sqrt(pow(x2-x1,2) + pow(y2-y1,2))));
        }
        printf("Case #%d: %0.3lf\n", cas, mindist);
    }

    return 0;
}
