//
//  491 - Tile topology.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cassert>

#define MAX 41
using namespace std;

int sol[]={0,1,1,2,7,18,60,196,704,2500,9189,33896,126759,476270,1802312,6849777};


int main()
{
	int n;
	while(cin >> n)
	{
		cout << sol[n] << endl;
	}
	return 0;
}
