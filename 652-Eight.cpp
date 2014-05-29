//
//  652 - Eight.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <map>

using namespace std;

string final = "12345678x";

struct state
{
	int location;
	string st;
	string seq;
};

int main()
{
	map<string,string>visited;
	queue<state>states;

	state newstate;
	newstate.st = final;
	newstate.seq = "";
	newstate.location = 8;

	states.push(newstate);
	visited[final]="";

	while(!states.empty())
	{
		state cur = states.front();
		states.pop();

		if(cur.location > 2)
		{
			newstate.location = cur.location - 3;
			newstate.seq = "d" + cur.seq;
			string news = cur.st;
			swap(news[cur.location],news[cur.location-3]);
			newstate.st = news;
			if(!visited.count(newstate.st))
			{
				states.push(newstate);
				visited[newstate.st] = newstate.seq;
			}
		}

		if(cur.location < 6)
		{
			newstate.location = cur.location + 3;
			newstate.seq = "u"+cur.seq;
			string news = cur.st;
			swap(news[cur.location],news[cur.location+3]);
			newstate.st = news;
			if(!visited.count(newstate.st))
			{
				states.push(newstate);
				visited[newstate.st] = newstate.seq;
			}
		}

		if((cur.location+1) % 3 != 0)
		{
			newstate.location = cur.location + 1;
			newstate.seq = "l"+cur.seq;
			string news = cur.st;
			swap(news[cur.location],news[cur.location+1]);
			newstate.st = news;
			if(!visited.count(newstate.st))
			{
				states.push(newstate);
				visited[newstate.st] = newstate.seq;
			}
		}

		if(cur.location % 3 != 0)
		{
			newstate.location = cur.location - 1;
			newstate.seq = "r"+cur.seq;
			string news = cur.st;
			swap(news[cur.location],news[cur.location-1]);
			newstate.st = news;
			if(!visited.count(newstate.st))
			{
				states.push(newstate);
				visited[newstate.st] = newstate.seq;
			}
		}
	}

	int n;
	cin >> n;
	for(int casenbr = 0; casenbr < n; casenbr++)
	{
		if(casenbr)
			cout << endl;
		string s = "";

		for(int i = 0; i < 9; i++)
		{
			string c;
			cin >> c;
			s += c;
		}

		if(visited.count(s))
			cout << visited[s] << endl;
		else
			cout << "unsolvable" << endl;
	}
	return 0;
}
