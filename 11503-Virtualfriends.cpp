//
//  11503 - Virtual friends.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-09.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int>v;
map<string, int>m;
map<int, int> mergemap;

int findind(int start)
{
    int cur = mergemap[start];
    if(cur == start)
        return start;
    else
        return findind(cur);
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        v.clear();
        mergemap.clear();
        m.clear();
        int p;
        cin >> p;
        string s1, s2;
        while(p--)
        {
            cin >> s1 >> s2;
            int i1 = -1;
            int i2 = -1;
            if(m.count(s1))
                i1 = findind(m[s1]);
            if(m.count(s2))
                i2 = findind(m[s2]);

            if(i1 == -1)
            {
                if(i2 == -1)
                {
                    int size = v.size();
                    m[s1] = size;
                    m[s2] = size;
                    mergemap[size] = size;
                    v.push_back(2);
                    cout << 2 << endl;
                }else{
                    v[i2]++;
                    m[s1] = i2;
                    cout << v[i2] << endl;
                }
            }
            else{
                if(i2 == -1)
                {
                    v[i1]++;
                    m[s2] = i1;
                    cout << v[i1] << endl;
                }else if(i1 != i2){
                    int mmin = min(i1,i2);
                    int mmax = max(i1,i2);
                    v[mmin] += v[mmax];
                    mergemap[mmax] = mmin;
                    cout << v[mmin] << endl;
                }else{
                    cout << v[i1] << endl;
                }
            }
        }
    }
    return 0;
}
