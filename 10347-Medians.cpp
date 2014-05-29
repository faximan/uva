//
//  10347 - Medians.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-19.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    double u, v, w;
    while(cin >> u >> v >> w)
    {
        double r = pow(u,4)+pow(v,4)+pow(w,4);
        double l = pow(u,2)*pow(v,2)+pow(v,2)*pow(w,2)+pow(u,2)*pow(w,2);

        double area = -1;

        if(2*l-r > 0)
            area = 1/(double)3*sqrt(2*l-r);

        printf("%0.3lf\n", area);
    }
    return 0;
}
