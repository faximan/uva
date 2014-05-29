//
//  10872 - How many triangles.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-14.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int c = 0;
	while(true)
	{
		c++;
		unsigned long long in;
		cin >> in;
		if(in == 0) break;
		cout << "Case " << c << ": ";
		unsigned long long ans;
		if(in%2==0)
		{
			ans = in*in/48;
			unsigned long long rem = (in*in)%48;
			if(rem >= 24)
				ans++;
		}else{
			ans = (in+3)*(in+3)/48;
			unsigned long long rem = ((in+3)*(in+3))%48;
			if(rem >= 24)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
