//
//  103 - Stacking boxes.cpp
//  IMPA
//
//  Created by Alexander Faxå on 2011-12-02.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int best;
vector<int> bestsq;

bool fits[30][30];
int dim[30][10];

int k, n;

int p[30];

bool isfit(int i, int j){
    for(int a = 0; a < n; a++){
        if(dim[i][a] >= dim[j][a])
            return false;
    }
    return true;
}

void solve(int cur, int depth)
{
    bool found = false;
    for(int i = 0; i < k; i++){
        if(fits[cur][i]){
            found = true;
            assert(p[i] == -1);
            p[i] = cur;
            solve(i, depth +1);
            p[i] = -1;
        }
    }
    
    if(!found && depth > best){
        best = depth;
        bestsq.clear();
        int a = cur;
        while (true) {
            bestsq.push_back(a);
            if(p[a] == -1)
                break;
            a = p[a];
        }
    }
}

int main()
{
    while(cin >> k >> n){
        for(int i = 0; i < k; i++){
            for(int j = 0; j < n; j++){
                int in;
                cin >> in;
                dim[i][j] = in;
            }
            sort(&dim[i][0], &dim[i][n]);
            p[i] = -1;
        }
                
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                fits[i][j] = isfit(i,j);
            }
        }
        
        best = 0;
        for(int i = 0; i < k; i++)
            solve(i, 1);
        
        cout << best << " " << endl;
        for(int i = bestsq.size()-1; i >= 0; i--){
            if(i != bestsq.size()-1)
                cout << " ";
            cout << (bestsq[i] + 1);
        }
        cout << endl;
        
    }
    return 0;
}