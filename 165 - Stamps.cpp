//
//  165 - Stamps.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-19.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/**
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int h, k;

vector<int>v;
vector<int>bestv;

int best;

int r[500];

string precalc[100] = {"dummy","dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"  1 ->  1", 
	"  1  2 ->  2", 
	"  1  2  3 ->  3", 
	"  1  2  3  4 ->  4", 
	"  1  2  3  4  5 ->  5", 
	"  1  2  3  4  5  6 ->  6", 
	"  1  2  3  4  5  6  7 ->  7", 
	"  1  2  3  4  5  6  7  8 ->  8", 
	"dummy",
	"dummy",
	"  1 ->  2", 
	"  1  2 ->  4", 
	"  1  3  4 ->  8", 
	"  1  3  5  6 -> 12", 
	"  1  3  5  7  8 -> 16", 
	"  1  2  5  8  9 10 -> 20", 
	"  1  2  5  8 11 12 13 -> 26", 
	"dummy",
	"dummy",
	"dummy",
	"  1 ->  3", 
	"  1  3 ->  7", 
	"  1  4  5 -> 15", 
	"  1  4  7  8 -> 24", 
	"  1  4  6 14 15 -> 36", 
	"  1  3  7  9 19 24 -> 52", 
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"  1 ->  4", 
	"  1  3 -> 10", 
	"  1  5  8 -> 26", 
	"  1  3 11 18 -> 44", 
	"  1  3 11 15 32 -> 70", 
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"  1 ->  5", 
	"  1  4 -> 14", 
	"  1  6  7 -> 35", 
	"  1  4 12 21 -> 71", 
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"  1 ->  6", 
	"  1  4 -> 18", 
	"  1  7 12 -> 52", 
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"  1 ->  7", 
	"  1  5 -> 23", 
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"  1 ->  8", 
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy",
	"dummy"};


void res(int mi, int left, int cur)
{
	if(mi == v.size() || !left)
	{
		r[cur] = 1;
		return;
	}
	
	for(int i = 0; i <= left; i++)
	{
		res(mi+1,left-i, cur+i*v[mi]);
	}	
}

void gen(int mi, int left)
{
	if(!left)
	{
		memset(r,0,sizeof(r));
		res(0, h, 0);	
		
		int cur = 1;
		while(r[cur]==1)
		{
			cur++;
		}
		if(cur-1 > best)
		{
			best = cur-1;
			bestv = v;
		}
		return;
	}
	
	for(int i = mi; i <= 60; i++)
	{
		v.push_back(i);
		gen(i+1,left-1);
		v.pop_back();
	}
}

void solve()
{
	v.clear();
	v.push_back(1);
	best = 0;
	gen(2,k-1);
}

int main()
{
	while(true)
	{
		cin >> h >> k;
		if(!h && !k)
			break;
		
		cout << precalc[h*10+k] << endl;
		
 // DO NOT RUN BELOW!
		if(h==0 || k==0 || h+k > 9)
		{
			cout << "\"dummy\",\n";
			continue;
		}
		
		solve();
		printf("\"");
		for(int i = 0; i < bestv.size(); i++)
			printf("%3d", bestv[i]);
		printf(" ->%3d\", \n", best);
	}
}*/