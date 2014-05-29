//
//  112 - Tree Summing.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct vertex
{
	vertex* left, *right;
	int number;
	bool isLeaf;
};

vertex *root;
int destsum;

void readTree(vertex* v)
{
	char c;
	(*v).number = 0;
	int sign = 1;
	bool first = true;
	while(true)
	{
		cin >> c;
		if(isdigit(c))
		{
			if(first)
			{
				first = false;
				(*v).isLeaf = false;
				v->left = new vertex();
				(*(v->left)).isLeaf = true;
				v->right = new vertex();
				(*(v->right)).isLeaf = true;
			}
			(*v).number = (*v).number*10+(int)(c-'0');
		}
		else if(c == '-')
			sign *= -1;
		else if(c == '(')
		{
			readTree(v->left);
			do {
				cin >> c;
			} while (c != '(');
			readTree(v->right);
			do {
				cin >> c;
			} while (c != ')');
			(*v).number *= sign;
			break;
		}
		else if(c == ')')
		{
			break;
		}
	}
}

bool ok;

void calc(vertex* cur, int cursum)
{
	cursum += (*cur).number;
	if((*cur).isLeaf)
		return;
	if((*(cur->left)).isLeaf && (*(cur->right)).isLeaf)
	{
		if(cursum == destsum)
			ok = true;
		return;
	}
	if(!(*(cur->right)).isLeaf)
		calc(cur->right, cursum);
	if(!(*(cur->left)).isLeaf)
		calc(cur->left, cursum);
}

int main()
{
	while(cin >> destsum)
	{
		char c;
		do {
			cin >> c;
		} while (c != '(');
		root = new vertex();
		(*root).isLeaf = true;
		readTree(root);
		ok = false;
		calc(root, 0);
		if(ok)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
