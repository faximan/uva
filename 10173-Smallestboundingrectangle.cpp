//
//  10173 - Smallest bounding rectangle.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-19.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <vector>

#define PI acos(-1)
#define INF 1e10

using namespace std;

struct point {
	double x, y;
};


int main()
{
	int n;
	while(true)
	{
		cin >> n;
		if(!n)
			break;

		vector<point>unm;
		double b[1002];
		double z[1002];

		double xmin = INF;
		for(int i = 0; i < n; i++)
		{
			point p;
			cin >> p.x >> p.y;
			unm.push_back(p);
			xmin = min(xmin, p.x);
		}

		if(xmin<0.5)
			for(int i = 0; i < n; i++)
				unm[i].x += 0.5-xmin;


		for(int i = 0; i < n; i++)
		{
			point cur = unm[i];
			b[i] = atan(cur.y/cur.x);
			z[i] = sqrt(pow(cur.x,2)+pow(cur.y,2));
		}

		double res = INF;

		double diff = 5;
		double bestv = -5;

		for(int k = 0; k < 12; k++)
		{
			diff /= 15;
			double lower, upper;

			if(bestv < -3)
			{
				lower = 0;
				upper = PI/2;
			}
			else
			{
				lower = bestv - diff;
				upper = bestv + diff;
			}

			for(double alfa = lower; alfa <= upper; alfa += diff/50)
			{
				double xmin = INF;
				double xmax = -INF;
				double ymin = INF;
				double ymax = -INF;

				for(int i = 0; i < unm.size(); i++)
				{
					point cur = unm[i];
					cur.y = z[i]*sin(b[i]+alfa);
					cur.x = z[i]*cos(b[i]+alfa);

					xmin = min(xmin, cur.x);
					xmax = max(xmax, cur.x);
					ymin = min(ymin, cur.y);
					ymax = max(ymax, cur.y);
				}
				double newvalue = fabs(xmin-xmax)*fabs(ymin-ymax);
				if(newvalue < res)
				{
					res = newvalue;
					bestv = alfa;
				}
			}
		}

		printf("%.4f\n", res);
	}
	return 0;
}
