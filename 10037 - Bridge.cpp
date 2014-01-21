//
//  10037 - Bridge.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-06.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>

using namespace std;

vector<int>a;
vector<string>str;

string convertInt(int number)
{
    stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}

int main()
{
    int cas;
    cin >> cas;
    for (int c = 0; c < cas; c++) {
        a.clear();
        str.clear();
        
        if(c != 0)
            cout << endl;
        
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int d;
            cin >> d;
            a.push_back(d);
        }
        
        sort(a.begin(), a.end());
        
        int time = 0;
        string s;
        while(a.size() > 3)
        {
            int d1 = 2*a[0] + a[a.size()-1] + a[a.size() - 2];
            int d2 = 2*a[1] + a[0] + a[a.size()-1];
            if(d1 < d2)
            {
                time += d1;
                s = convertInt(a[0]) + " " + convertInt(a[a.size()-1]);
                str.push_back(s);
                s = convertInt(a[0]);
                str.push_back(s);
                s = convertInt(a[0]) + " " + convertInt(a[a.size()-2]);
                str.push_back(s);
                s = convertInt(a[0]);
                str.push_back(s);
            }else{
                time += d2;
                s = convertInt(a[0]) + " " + convertInt(a[1]);
                str.push_back(s);
                s = convertInt(a[0]);
                str.push_back(s);
                s = convertInt(a[a.size()-2]) + " " + convertInt(a[a.size()-1]);
                str.push_back(s);
                s = convertInt(a[1]);
                str.push_back(s);
            }
            a.pop_back();
            a.pop_back();
        }

        if(a.size() == 1)
        {
            time += a[0];
            s = convertInt(a[0]);
            str.push_back(s);
        }
        if(a.size() == 2)
        {
            time += a[1];
            s = convertInt(a[0]) + " " + convertInt(a[1]);
            str.push_back(s);
        }
        if(a.size() == 3)
        {
            time += a[2] + a[0] + a[1];
            s = convertInt(a[0]) + " " + convertInt(a[2]);
            str.push_back(s);
            s = convertInt(a[0]);
            str.push_back(s);
            s = convertInt(a[0]) + " "  + convertInt(a[1]);
            str.push_back(s);
        }
        cout << time << endl;
        for (int i = 0; i < str.size(); i++) {
            cout << str[i] << endl;
        }        
    }    
    return 0;
}*/