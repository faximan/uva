//
//  11181 - ProbabilityGiven.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

double prob[21];
double indu[21];

int main()
{
	int casenr = 0;
	while(true)
	{
		casenr++;
		int n, r;
		cin >> n >> r;
		if(n==0 && r==0) break;
		cout << "Case " << casenr << ":" << endl;

		for (int i = 0; i < n; i++) {
			cin >> prob[i];
			indu[i] = 0;
		}

		vector<bool> v(n, false);

		double total = 0;

		for(int i = 0; i < (int)pow(2,n); ++i)
		{
			for(vector<bool>::iterator it = v.begin(); it != v.end(); ++it)
			{
				if(*it)
					*it = false;
				else{
					*it = true;
					break;
				}
			}

			int nbr = 0;
			double cur = 1.0;
			for (int j = 0; j < n; j++)
			{
				if(v[j])
				{
					nbr++;
					cur *= prob[j];
				}
				else
					cur *= 1 - prob[j];
			}

			if(nbr != r)
				continue;

			for (int j = 0; j < n; j++)
			{
				if(v[j])
					indu[j] += cur;
			}

			total += cur;

		}

		for (int j = 0; j < n; j++)
			printf("%.6f\n", indu[j]/total);

	}
	return 0;
}
