//
//  11122 - TriTri.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-15.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cmath>
#define EPS 1e-10

using namespace std;

long long x[6], y[6];


int pnpoly(double x1, double y1, double x2, double y2, double x3, double y3, double xp, double yp)
{
	double abc = fabs(x1*y2 + x2*y3 + x3*y1 - x1*y3 - x3*y2 - x2*y1) / 2.0;
	double pab = fabs(xp*y1 + x1*y2 + x2*yp - xp*y2 - x2*y1 - x1*yp) / 2.0;
	double pbc = fabs(xp*y2 + x2*y3 + x3*yp - xp*y3 - x3*y2 - x2*yp) / 2.0;
	double pac = fabs(xp*y1 + x1*y3 + x3*yp - xp*y3 - x3*y1 - x1*yp) / 2.0;

	if(pab < EPS || pbc < EPS || pac < EPS)
		return false;
	return fabs(abc - (pab+pbc+pac)) < EPS;
}

bool cross(int a, int b, int c, int d)
{
	long long ex = x[b]-x[a];
	long long ey = y[b]-y[a];
	long long fx = x[d]-x[c];
	long long fy = y[d]-y[c];
	long long px = -ey;
	long long py = ex;
	long long qx = -fy;
	long long qy = fx;

	long long dem1 = fx*px+fy*py;
	long long dem2 = ex*qx+ey*qy;
	if(dem1 == 0 || dem2 == 0)
		return false;

	double h = ((x[a]-x[c])*px+(y[a]-y[c])*py) / (double)dem1;
	double g = ((x[b]-x[d])*qx+(y[b]-y[d])*qy) / (double)dem2;
	if((h < EPS && h > - EPS) || (h < 1+EPS && h > 1-EPS) || (g < EPS && g > - EPS) || (g < 1+EPS && g > 1-EPS))
		return false;

	return (h > 0 && h < 1 && g > 0 && g < 1);
}

int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++)
	{
		for (int i = 0; i < 6; i++)
			cin >> x[i] >> y[i];

		bool ans = false;
		for (int i = 0; i < 3; i++)
			for (int j = i+1; j < 3; j++)
				for (int k = 3; k < 6; k++)
					for (int l = k+1; l < 6; l++)
						ans = ans || cross(i,j,k,l);

		if(ans == false)
		{
			ans = true;
			for (int i = 0; i < 3; i++)
				if(x[i]!=x[i+3] || y[i]!=y[i+3])
					ans = false;
		}

		if(ans == false)
		{
			for (int i = 0; i < 3; i++)
			{
				ans = ans || pnpoly(x[3], y[3], x[4], y[4], x[5], y[5], x[i], y[i]);
				ans = ans || pnpoly(x[3], y[3], x[4], y[4], x[5], y[5], (x[i]+x[(i+1)%3])/2.0, (y[i]+y[(i+1)%3])/2.0);
			}
			for (int i = 0; i < 3; i++)
			{
				ans = ans || pnpoly(x[0], y[0], x[1], y[1], x[2], y[2], x[i+3], y[i+3]);
				ans = ans || pnpoly(x[0], y[0], x[1], y[1], x[2], y[2], (x[i+3]+x[(i+1)%3+3])/2.0, (y[i+3]+y[(i+1)%3+3])/2.0);
			}
		}

		if(ans)
			cout << "pair " << tt << ": yes" << endl;
		else
			cout << "pair " << tt << ": no" << endl;

	}
	return 0;
}
