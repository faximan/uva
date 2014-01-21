//
//  11700 - Pipes.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>

using namespace std;

bool n[15][15][4];
bool o[15][15][4];

// 0 N, 1 E, 2 S, 3 W

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int r, c;

bool doit(int curx, int cury)
{
	if (r == cury)
		return true;
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			n[cury][curx][j] = o[cury][curx][(j+i)%4];
	
		bool ok = true;
		
		for(int j = 0; j < 4; j++)
		{
			int newx = curx + dx[j];
			int newy = cury + dy[j];
			
			if (newy < 0) //N
			{
				if (n[cury][curx][0])
				{
					ok = false;
					break;
				}
				continue;
			}
			
			if (newx >= c) //E
			{
				if (n[cury][curx][1])
				{
					ok = false;
					break;
				}
				continue;
			}
			
			if (newy >= r) //S
			{
				if (n[cury][curx][2])
				{
					ok = false;
					break;
				}
				continue;
			}
			
			if (newx < 0) //W
			{
				if (n[cury][curx][3])
				{
					ok = false;
					break;
				}
				continue;
			}

			if(newx > curx || newy > cury)
				continue;
			
			if (n[cury][curx][j] != n[newy][newx][(j+2)%4])
			{
				ok = false;
				break;
			}
		}
		
		if (!ok)
			continue;
		
		if((curx+1)%c==0)
		{
			if(doit(0,cury+1))
				return true;
		}
		else
		{
			if(doit(curx+1, cury))
				return true;
		}
		
		if ((o[cury][curx][0] == 0 && 
			 o[cury][curx][1] == 0 &&
			 o[cury][curx][2] == 0 &&
			 o[cury][curx][3] == 0)||
			(o[cury][curx][0] == 1 &&
			 o[cury][curx][1] == 1 &&
			 o[cury][curx][2] == 1 &&
			 o[cury][curx][3] == 1))
			return false;
	}
	return false;
}


int main()
{
	while(true)
	{
		cin >> r >> c;
		if(!r)
			break;
		
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
			{
				string s;
				cin >> s;
				
				for(int k = 0; k < 4; k++)
					o[i][j][k] = false;

				for(int k = 0; k < s.size(); k++)
				{
					if (s[k] == 'N')
						o[i][j][0] = true;
					if (s[k] == 'E')
						o[i][j][1] = true;
					if (s[k] == 'S')
						o[i][j][2] = true;
					if (s[k] == 'W')
						o[i][j][3] = true;
				}
			}
		
		if (doit(0,0))
			cout << "SOLVABLE" << endl;
		else 
			cout << "UNSOLVABLE" << endl;
	}
	
	return 0;
}*/