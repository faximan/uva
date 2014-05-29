//
//  11550 - Demanding dilemma.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-13.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;

int g[50][50];
int m, n;

bool ok(int x, int y)
{
    int check = 0;
    for(int j = 0; j < n; j++)
        if(g[x][j] && g[y][j]){
            if(check)
                return false;
            check = 1;
        }
    return true;
}

void solve()
{
    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            if(!ok(i, j)){
                cout << "No" << endl;
                return;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for(int i = 0; i < m; i++)
            if(g[i][j])
                cnt++;
        if(cnt != 2){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> g[i][j];

        solve();
    }
    return 0;
}
