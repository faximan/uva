//
//  10877 - Diceoids.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-18.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<int> found;
int cur[6];

const int dice[12][6] = {
    {0, 1, 2, 3, 4, 5},
    {0, 4, 1, 3, 5, 2},
    {0, 5, 4, 3, 2, 1},
    {0, 2, 5, 3, 1, 4},
    {4, 0, 5, 2, 1, 3},
    {4, 1, 0, 2, 3, 5},
    {4, 3, 1, 2, 5 ,0},
    {4, 5, 3, 2, 0, 1},
    {1, 4, 3, 5, 0, 2},
    {1, 0, 4, 5, 2, 3},
    {1, 2, 0, 5, 3, 4},
    {1, 3, 2, 5, 4, 0}
};

bool exist()
{
    for (int i = 0; i < 12; i++) {
        int my = cur[dice[i][0]];
        int my2 = cur[dice[i][3]];
        for (int j = 1; j < 6; j++) {
            my = my * 10 + cur[dice[i][j]];
            my2 = my2 * 10 + cur[dice[i][(j+3)%6]];
        }
        if(found.count(my) || found.count(my2))
            return true;
    }
    return false;
}

int get_cur()
{
    int my = cur[0];
    for (int i = 1; i < 6; i++) {
        my = my*10+cur[i];
    }
   // cout << my << endl;
    return  my;
}


int main()
{
    int n;
    while(true)
    {
        cin >> n;
        if( n== 0) break;
        found.clear();

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < 6; k++) {
                cin >> cur[k];
            }

            if(!exist())
            {
                found.insert(get_cur());
            }
        }
        cout << found.size() << endl;
    }
    return 0;
}
