//
//  10310 - Dog and gopher.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-31.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int holes;
    while(cin >> holes)
    {
        double gx, gy, dx, dy;
        cin >> gx >> gy >> dx >> dy;
         
        bool finished = false;
        
        for (int i = 0; i < holes; i++) {
            double x, y;
            cin >> x >> y;
           
            if(!finished && sqrt(((x-dx)*(x-dx)+(y-dy)*(y-dy)))/2.0 +1e-10 > sqrt((x-gx)*(x-gx)+(y-gy)*(y-gy)))
            {
                finished = true;
                printf("The gopher can escape through the hole at (%.3f,%.3f).\n", x, y);
            }
        }
        
        if(!finished)
            printf("The gopher cannot escape.\n");
    }
    return 0;
}