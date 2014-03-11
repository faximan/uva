//
//  10136 - Chocolate chips cookies.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-31.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>

#define EPS 1e-10

using namespace std;

double xx[201], yy[201];
int n;

int count(int i, int j, double x, double y)
{
    int res = 0;
    for (int a = 0; a < n; a++) {
        if(a == i || a == j)
            continue;
        if(sqrt((x-xx[a])*(x-xx[a]) + (y-yy[a])*(y-yy[a])) < 2.5 + EPS)
            res++;
    }
    return res;
}

double abs(double a, double b)
{
    if(a > b)
        return a-b;
    else
        return b-a;
}

int main()
{
    int cases;
    cin >> cases;
    string s;
    getline(cin, s);
    getline(cin, s);
    
    for (int i = 0; i < cases; i++) {
        if(i)
            cout << endl;
        
        n = 0;
        
        while(getline(cin, s) && s != "")
        {
            double x,y;
            istringstream in(s);
            in >> x >> y;
            xx[n] = x;
            yy[n++] = y;
            
        }  
               
        if(n < 2)
        {
            cout << n << endl;
            continue;
        }

        int best = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n;j++) {
                
                double q = sqrt((xx[i]-xx[j])*(xx[i]-xx[j]) + (yy[i]-yy[j])*(yy[i]-yy[j]));
                if(q > 5.0 + EPS)
                    continue;
                
                double mx = (xx[i]+xx[j])/2.0;
                double my = (yy[i]+yy[j])/2.0;
                
                if(abs(q,5.0) < EPS)
                    best = max(best, 2+count(i, j, mx, my));
                else
                {
                    double square = sqrt(2.5*2.5 - (q/2.0)*(q/2.0));
                    double sx = square * (yy[i]-yy[j])/q;
                    double sy = square * (xx[j]-xx[i])/q;
                    
                    best = max(best, 2+count(i, j, mx+sx, my+sy));
                    best = max(best, 2+count(i, j, mx-sx, my-sy));
                }
            }
        }
        cout << best << endl;           
    }
        return 0;
}