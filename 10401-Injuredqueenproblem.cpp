//
//  10401 - Injured queen problem.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char board[16];
long long result[16][16];

int main()
{
    while(cin >> board)
	{
		int n = strlen(board);
		
		for (int i = 0; i < 16; i++)
			for(int j = 0; j < 16; j++)
				result[i][j] = 0;
		
		if(board[0] == '?')
		{
			for(int i = 0; i < n; i++)
				result[0][i] = 1;
		}
		else
		{
			int j;
			if(isdigit(board[0]))
				j = board[0] - '1';
			else
				j = board[0] - 'F' + 14;
			result[0][j] = 1;
		}
		for(int i = 1; i < n; i++)
		{
			if(board[i] == '?')
			{
				for(int j = 0; j < n; j ++)
				{
					for(int k = 0; k < j - 1; k++)
						result[i][j] += result[i - 1][k];
					for(int k = j + 2; k < n; k++)
						result[i][j] += result[i - 1][k];
				}
			}
			else
			{
				int j;
				if(isdigit(board[i]))
					j = board[i] - '1';
				else
					j = board[i] - 'F' + 14;
				for(int k = 0; k < j - 1; k++)
					result[i][j] += result[i - 1][k];
				for(int k = j + 2; k < n; k ++)
					result[i][j] += result[i - 1][k];
			}
		}
		long long res = 0;
		for(int i = 0; i < n; i++)
			res += result[n - 1][i];
		printf("%lld\n", res);
	}
    return 0;
}