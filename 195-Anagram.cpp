//
//  195 - Anagram.cpp
//  IMPA
//
//  Created by Alexander Faxå on 2011-12-05.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>

using namespace std;
vector<char> v;
vector<string> s;

bool mycomp(char i, char j)
{
    if(tolower(i) == tolower(j))
        return i < j;
    else
        return tolower(i) < tolower(j);
}

void solve()
{
    sort(v.begin(), v.end(), mycomp);
    string str = "";
    for(int i = 0; i < v.size(); i++)
        str += v[i];
    s.push_back(str);
    
    while(next_permutation(v.begin(), v.end(), mycomp))
    {
        str = "";
        for(int i = 0; i < v.size(); i++)
            str += v[i];
        if(s[s.size()-1] != str)
            s.push_back(str);
    }    
    for(int i = 0; i < s.size(); i++)
        cout << s[i] << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        v.clear();
        s.clear();
        string str;
        cin >> str;
        
        for(int i = 0; i < str.size(); i++)
            v.push_back(str[i]);
        
        solve();        
    }
    return 0;
}*/    