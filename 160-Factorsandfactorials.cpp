//
//  160 - Factors and factorials.cpp
//  IMPA
//
//  Created by Alexander Faxå on 2011-12-03.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int a[25];

int main(){
    
    int n;
    while(true){
        for(int i = 0; i < 25; i++)
            a[i] = 0;
        cin >> n;
        if( n== 0) break;
        
        int mmax = 0;
        for(int i = 2; i <= n; i++){
            int cur = i;
            int div = 0;
            while(cur != 1){
                while(cur % primes[div] == 0){
                    cur /= primes[div];
                    a[div]++;
                    mmax = max(div, mmax);;
                }
                div++;
            }
        }
        printf("%3d! =", n);
        int printed = 0;
        for(int i = 0; i <= mmax; i++){
            if(printed == 15){
                printf("\n      ");
                printed = 0;
            }
            printf("%3d", a[i]);
            printed++;
        }
        printf("\n");
    }
    return 0;
}*/