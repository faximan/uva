//
//  11084 - Anagram Division.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-06.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>

using namespace std;

int main()
{
	int t, d, res, length;
	char s[11];
	cin >> t;
	long long cur;
	while(t--)
	{
		scanf("%s %d", s, &d);
		res = 0;
		length = strlen(s);
		sort(s,s+length);
		do
		{
			cur = atoi(s);
			if(cur%d==0)
				res++;
		} while (next_permutation(s, s+length));
		printf("%d\n", res);
	}
	return 0;
}
