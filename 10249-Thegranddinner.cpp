//
//  10249 - The grand dinner.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-09.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct team
{
    int size;
    int index;
    vector<int>assigned;
};

team mem[100];
int table[100];
int num_team, num_table;

bool sort_by_size (team i, team j) { return (i.size > j.size); }
bool sort_by_index (team i, team j) { return (i.index < j.index); }

int main()
{
    while(true)
    {
        cin >> num_team >> num_table;
        if(num_team == 0) break;
        
        for (int i = 0; i < num_team; i++) {
            cin >> mem[i].size;
            mem[i].index = i;
            mem[i].assigned.clear();
        }
        
        for (int i = 0; i < num_table; i++) {
            cin >> table[i];
        }
        
        sort(mem, mem+num_team, sort_by_size);
        
        bool finished = false;
        bool still_going = true;
        
        while(still_going)
        {
            finished = true;
            still_going = false;
            for (int i = 0; i < num_team; i++) 
            {
                for (int j = 0; j < num_table && mem[i].size; j++)
                {
                    finished = false;
                    if(table[j] && (int)count(mem[i].assigned.begin(), mem[i].assigned.end(), j) == 0)
                    {
                        still_going = true;
                        table[j]--;
                        mem[i].size--;
                        mem[i].assigned.push_back(j);
                    }
                }
            }
        }
        
        if(finished)
        {
            cout << "1" << endl;
            sort(mem, mem+num_team, sort_by_index);
            for (int i = 0; i < num_team; i++)
            {
                for(int j = 0; j < mem[i].assigned.size(); j++)
                {
                    if(j) cout << " ";
                    cout << (mem[i].assigned[j] + 1);
                }
                cout << endl;
            }
        }
        else
        {
            cout << "0" << endl;
        }
    }
    return 0;
}