//
//  719 - Glass Beads.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-13.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        
        int length = s.length();
        s = s + s; // Duplikera för wrap-around
        
        int i = 0;
        int j = 1;
        int k = 0;
        
        while(i < length && j < length)
        {
            if (s[i+k] == s[j+k])
            { 
                k++;
                if (k == length) // Gått igenom hela urspr. strängen - räcker så
                    break;
            }
            if (s[i+k] > s[j+k])
            {
                i = i + k + 1;
                if (i <= j)
                    i = j + 1;
                k = 0;
            }
            if (s[i+k] < s[j+k])
            {
                j = j + k + 1;
                if (j <= i)
                    j = i + 1;
                k = 0;
            }
        }      
        cout << min(i, j)+1 << endl;
            
    }
    return 0;
}*/