//
//  10611 - The playboy chimp.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <stdio.h>

using namespace std;

int a[50001];
int n, q;
int b;


int lower_than()
{
    int mmin = 0;
    int mmax = n-1;
    
    while(true)
    {
        int mid = (mmin + mmax)/2;
        if(b > a[mid])
            mmin = mid + 1;
        else
            mmax = mid - 1;
        if(a[mid] == b || mmin > mmax)
            return mid;
    }
}

int main()
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++) {
        scanf("%d", &b);
        
        int lower = lower_than();
        int upper = lower;
        
        while(lower >= 0 && a[lower] >= b)
            lower--;

        while(upper < n && a[upper] <= b)
            upper++;
        
        if(lower == -1)
            printf("X ");
        else
            printf("%d ", a[lower]);
        if(upper >= n)
            printf("X\n");
        else
            printf("%d\n", a[upper]);        
        
    }   
    return 0;
}
*/