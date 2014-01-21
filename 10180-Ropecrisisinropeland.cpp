//
//  10180 - Rope crisis in rope land.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <stdio.h>
#include <math.h>
#define eps 1e-8

using namespace std;

struct pt {
    double x, y;
};

double dist(pt p1, pt p2) 
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)); 
}

// calculate square distance from line segment between v0 and v1 to point c
double DistanceSquared(pt v0, pt v1, pt c)
{
    double vx = v0.x - c.x;
    double vy = v0.y - c.y;
    double ux = v1.x - v0.x;
    double uy = v1.y - v0.y;
    
    double length = ux * ux + uy * uy;
    
    double det = (-vx * ux) + (-vy * uy);
    
    if (det < eps)
        return (v0.x - c.x) * (v0.x - c.x) + (v0.y - c.y) * (v0.y - c.y);
    if (det + eps > length)
        return (v1.x - c.x) * (v1.x - c.x) + (v1.y - c.y) * (v1.y - c.y);
    
    det = ux * vy - uy * vx;
    return (det * det) / length;
}

int main() {
    pt p1, p2, o; 
    o.x = 0.0;
    o.y = 0.0;
    
    double r;
    
    int n;
    cin >> n;
    while(n--) 
    {
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> r;
        
        double d1 = dist(p1, p2);
        
        // if line segment does not intersect with circle (shortest distance longer than radius)
        if(sqrt(DistanceSquared(p1, p2, o)) + eps > r)
           printf("%.3lf\n", d1);
        else 
        {
            double d2 = dist(o, p1);
            double d3 = dist(o, p2);
            
            double tangents = sqrt(d2 * d2 - r * r) + sqrt(d3 * d3 - r * r); //length of two tangents
            
            // calculate arc length
            double arc_length = acos((d2 * d2 + d3 * d3 - d1 * d1) / (2 * d2 * d3));
            arc_length -= acos(r / d2) + acos(r / d3); 
            arc_length *= r;
            
            printf("%.3lf\n", tangents + arc_length);
        }
    }
    return 0;
}*/