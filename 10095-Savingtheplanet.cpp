//
//  10095 - Saving the planet.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-17.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>

#define PI 3.14159265359

using namespace std;

struct pp
{
	double x, y,z;
};

pp p[10002];

int main()
{
	
	int n;
	while(true)
	{
		cin >> n;
		if(!n)
			break;
		
		double minx = 1e10;
		double maxx = -1e10;
		double miny = 1e10;
		double maxy = -1e10;
		double minz = 1e10;
		double maxz = -1e10;
		
		for(int i = 0; i < n; i++)
		{
			cin >> p[i].x >> p[i].y >> p[i].z;
			minx = min(minx, p[i].x);
			miny = min(miny, p[i].y);
			minz = min(minz, p[i].z);
			maxx = max(maxx, p[i].x);
			maxy = max(maxy, p[i].y);
			maxz = max(maxz, p[i].z);
			
		}
		pp x1 = p[0];
		if(n==1)
		{
			printf("%.4f %.4f %.4f %.4f\n", 0.0, x1.x, x1.y, x1.z);
			continue;
		}
		
		

		
		
		//printf("%.4f %.4f %.4f %.4f\n", maximum/2.0, (x1.x+x2.x)/2.0, (x1.y+x2.y)/2.0, (x1.z+x2.z)/2.0);
	}
	return 0;
}*/