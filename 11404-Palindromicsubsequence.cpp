//
//  11404 - Palindromic subsequence.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

string mys;
int c[1001][1001];
vector<vector<int> > has(26);

void LCS()
{    
    for(int i = 1; i <= mys.size(); i++)
        for(int j = 1; j <= mys.size(); j++){
            if(mys[i-1] == mys[mys.size()-j])
                c[i][j] = c[i-1][j-1]+1;
            else
                c[i][j] = max(c[i][j-1],c[i-1][j]);
        }
}

string solve(int a, int b)
{
    if (b - a < 0)
        return "";

    int best = 0;
    int bi = a;
    int bj = b;
    
    for (char myc = 'a'; myc <= 'z'; myc++) {
        if(has[myc-'a'].empty()) continue;
        
        int i = 0;
        int j = 0;
        
        for(int k = 0; k < has[myc-'a'].size(); k++)
            if (has[myc-'a'][k] >= a && has[myc-'a'][k] <= b){
                i = has[myc-'a'][k];
                break;
            }
        
        for(int k = has[myc-'a'].size() - 1; k >= 0; k--)
            if (has[myc-'a'][k] >= a && has[myc-'a'][k] <= b){
                j = has[myc-'a'][k];
                break;
            }
        
        if(i < a || j < a || i > b || j > b)
            continue;
        
        int res = 0;
        if(j - i > 1)
            res = c[j][mys.length()-1-i] - c[i+1][mys.length() - j];
        
        if(i == j)
            res++;
        else
            res += 2; 
        
        if(res > best)
        {
            best = res;
            bi = i;
            bj = j;
        }
    }
        
    if(bi == bj)
        return mys.substr(bi, 1);
    else
        return mys[bi] + solve(bi+1, bj-1) + mys[bj];
}

int main()
{
    for(int i = 0; i < 1001; i++){
        c[i][0] = 0;
        c[0][i] = 0;
    }
    
    while(cin >> mys)
    {        
        for (int i = 0; i < 26; i++) {
            has[i].clear();
        }
        for (int i = 0; i < mys.size(); i++) {
            has[mys[i]-'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            sort(has[i].begin(), has[i].end());
        }
        LCS();
        cout << solve(0,mys.length()-1) << endl;
    }        
    return 0;
}*/