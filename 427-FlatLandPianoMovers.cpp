//
//  427 - FlatLand Piano Movers.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-26.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define EPS 1e-10
#define pi acos(-1)

using namespace std;

//piano width, piano length, corridor a, corridor b
int nbrs[4];

int cur, cur_index;

void solve()
{
    if(cur != 0) // some number is read
    {
        nbrs[cur_index++] = cur;
        cur = 0;

        if(cur_index == 4) // a new corridor config is ready
        {
            cur_index = 2;

            if(nbrs[0] > nbrs[1]) // piano width > piano length
                swap(nbrs[0], nbrs[1]);

            for (double a = 0.00001; a < pi/2; a += pi/256)
            {
                double cur_max_length = (nbrs[2] * sin(a) + nbrs[3] * cos(a) - nbrs[0]) / (sin(a) * cos(a));
                if(cur_max_length < (double)nbrs[1]+ EPS)
                {
                    cout << "N";
                    return;
                }
            }
            cout << "Y";
            return;
        }
    }
}

int main()
{
    string line;
    while(getline(cin, line))
    {
        cur_index = 0;
        cur = 0;

        for(int i=0;;i++)
        {
            if(line[i] == '\n' || line[i] == '\0')
            {
                solve();
                break;
            }

            else if(line[i] == ' ' || line[i] == ',')
            {
                solve();
                continue;
            }
            else
            {
                cur = cur * 10 + (line[i] - '0');
            }
        }
        cout << endl;
    }
   return 0;
}
