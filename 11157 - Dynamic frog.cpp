//
//  11157 - Dynamic frog.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
long long d;

vector<long long>a;

int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> d;
        a.clear();
        a.push_back(0);
        a.push_back(0);
        for (int j = 0; j < n; j++) {
            char stone, temp;
            long long length;
            
            while(true)
            {
                cin >> stone;
                if(stone == 'B' || stone == 'S') break;
            }
            
            cin >> temp >> length;
            a.push_back(length);
            if(stone == 'B')
                a.push_back(length);
        }
        a.push_back(d);
        a.push_back(d);
        
        long long best = 0;
        for (int j = 0; j+2 < a.size(); j+=2) {
            best = max(best, a[j+2]-a[j]);
        }
        for (int j = 1; j+2 < a.size(); j+=2) {
            best = max(best, a[j+2]-a[j]);
        }
        cout << "Case " << i << ": " << best << endl;
    }
    return 0;
}*/