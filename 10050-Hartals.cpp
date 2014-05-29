//
//  10050 - Hartals.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-09.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;

int h[101], d[101];
int N, cur, t, p;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> N;
        cin >> p;
        for (int i = 0; i < p; i++) {
            cin >> h[i];
            d[i] = 0;
        }

        int res = 0;
        cur = 5;
        for (int i = 0; i < N; i++) {
            cur = (cur+1)%7;
            bool hart = false;
            for (int j = 0; j < p; j++) {
                d[j] = (d[j]+1)%h[j];
                if(d[j] == 0)
                    hart = true;
            }
            if(hart && cur != 4 && cur != 5)
                res++;
        }
        cout << res << endl;
    }
    return 0;
}
