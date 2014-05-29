//
//  10408 - Farey sequences.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-26.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define EPS 1e-13

using namespace std;

set<double>s;

struct factor
{
    int n, t;

    bool operator<(const factor& b) const
    {
        return t/(double)n < b.t/(double)b.n + EPS;
    }
};
vector<factor>v;

int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        v.clear();
        s.clear();

        factor f;

        for (int i = 1; i < n; i++) {
            for (int j = i; j <= n; j++) {
                f.t = i;
                f.n = j;

                if(!s.count(i/(double)j))
                {
                    v.push_back(f);
                    s.insert(i / (double)j);
                }
            }
        }

        sort(v.begin(), v.end());

        cout << v[k-1].t << "/" << v[k-1].n << endl;
    }
}
