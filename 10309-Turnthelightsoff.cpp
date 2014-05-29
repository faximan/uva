//
//  10309 - Turn the lights off.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-19.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

bool grid[10][10];
bool secondgrid[10][10];

using namespace std;

void flip(int x, int y)
{
	grid[x][y] = !grid[x][y];
	if(x)
		grid[x-1][y] = !grid[x-1][y];
	if(x != 9)
		grid[x+1][y] = !grid[x+1][y];
	if(y)
		grid[x][y-1] = !grid[x][y-1];
	if(y != 9)
		grid[x][y+1] = !grid[x][y+1];
}

int main()
{
	string s;
	while(true)
	{
		cin >> s;
		if(s=="end")
			break;
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
			{
				char c;
				cin >> c;
				if(c=='#')
					grid[i][j] = false;
				else
					grid[i][j] = true;
				secondgrid[i][j] = grid[i][j];
			}

		int mi = 0x7FFFFFFF;
		vector<bool> v(10, false);
		for(int i = 0; i < 1024; ++i)
		{
			for(int i = 0; i < 10; i++)
				for(int j = 0; j < 10; j++)
					grid[i][j] = secondgrid[i][j];

			for(vector<bool>::iterator it = v.begin(); it != v.end(); ++it)
			{
				if(*it)
					*it = false;
				else{
					*it = true;
					break;
				}
			}

			int current = 0;
			for(int j = 0; j < 10; j++)
				if(v[j])
				{
					flip(0,j);
					current++;
				}
			for(int j = 1; j < 10; j++)
				for(int k = 0; k < 10; k++)
				{
					if(grid[j-1][k])
					{
						flip(j,k);
						current++;
					}
				}

				bool ok = true;
				for(int j = 0; j < 10; j++)
					if(grid[9][j])
						ok = false;
				if(ok)
					mi = min(mi, current);
			}

		cout << s << " ";
		if(mi <= 100)
			cout << mi << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}
