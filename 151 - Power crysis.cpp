//
//  151 - Power crysis.cpp
//  IMPA
//
//  Created by Alexander Faxå on 2011-12-03.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>

using namespace std;

int n;

bool solve(int m)
{
    int a[n];
    for(int i = 0; i < n; i++)
        a[i] = 0;
    
    int cnt = 1;
    int cur = 0;
    a[0] = 1;
    while(cur != 12){
        for(int s = 0;;){
            if(!a[cur]){
                s++;
                if(s == m)
                    break;
            }
            cur = (cur + 1) % n;
        }
        a[cur] = 1;
        cnt++;
    }
    return cnt == n;    
}

int main(){
    while(true){
        cin >> n;
        if(n == 0)
            break;
        
        int res = 1;
        while(!solve(res))
            res++;
        
        cout << res << endl;
       }
    
    return 0;
}*/