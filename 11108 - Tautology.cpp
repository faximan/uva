//
//  11108 - Tautology.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>

using namespace std;

int ind;
string perm[32] = {"00000", "00001","00010","00011","00100","00101","00110","00111","01001","01010","01011","01100","01101","01110","01111","10000","10001","10010","10011","10100","10101","10110","10111","11000","11001","11010","11011","11100","11101","111110","11111"};
string s;

bool solve(int cur)
{
    if(s[ind] == 'p')
        return perm[cur][0] == '1';
    if(s[ind] == 'q')
        return perm[cur][1] == '1';
    if(s[ind] == 'r')
        return perm[cur][2] == '1';
    if(s[ind] == 's')
        return perm[cur][3] == '1';
    if(s[ind] == 't')
        return perm[cur][4] == '1';
    
    bool a;
    bool b;
    
    if(s[ind] == 'K')
    {
        ind++;
        a = solve(cur);
        ind++;
        b = solve(cur);
        return a && b;
    }
    if(s[ind] == 'A')
    {
        ind++;
        a = solve(cur);
        ind++;
        b = solve(cur);
        return a || b;
    }
    if(s[ind] == 'N')
    {
        ind++;
        return !solve(cur);
    }
    if(s[ind] == 'C')
    {
        ind++;
        a = solve(cur);
        ind++;
        b = solve(cur);
        return !(a && !b);
    }
    if(s[ind] == 'E')
    {
        ind++;
        a = solve(cur);
        ind++;
        b = solve(cur);
        return (a && b) || (!a && !b);
    }
    return false; // error
}

int main()
{
    while(true)
    {
        cin >> s;
        if(s == "0") break;
            
        bool taut = true;
        for(int i = 0; i< 32; i++)
        {
            ind= 0;
            taut = taut && solve(i);
        }
        if(taut)
            cout << "tautology" << endl;
        else
            cout << "not" << endl;
    }
    return 0;
}*/