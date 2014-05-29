//
//  571 - Jugs.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-14.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visited[1000][1000];
int n;
int ca, cb;
vector<int>moves;
bool sol;

string s[] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};

void solve(int a, int b)
{
    if(visited[a][b])
        return;
    visited[a][b] = 1;

    if(b == n)
    {
        sol = true;
        return;
    }

    if(a != ca)
    {
        moves.push_back(1);
        solve(ca, b);
        if(sol)
            return;
        moves.pop_back();
    }
    if(b != cb)
    {
        moves.push_back(2);
        solve(a, cb);
        if(sol)
            return;
        moves.pop_back();
    }
    if(a != 0)
    {
        moves.push_back(3);
        solve(0, b);
        if(sol)
            return;
        moves.pop_back();
    }
    if(b != 0)
    {
        moves.push_back(4);
        solve(a, 0);
        if(sol)
            return;
        moves.pop_back();
    }
    if(a != 0 && b != cb)
    {
        moves.push_back(5);
        solve(a - min(a,cb-b), b + min(a, cb-b));
        if(sol)
            return;
        moves.pop_back();
    }
    if(b != 0 && a != ca)
    {
        moves.push_back(6);
        solve(a + min(b,ca-a), b - min(b, ca-a));
        if(sol)
            return;
        moves.pop_back();
    }

}

int main()
{
    while(cin >> ca >> cb >> n)
    {
        for (int i = 0; i <= ca; i++) {
            for (int j = 0; j <= cb; j++) {
                visited[i][j] = 0;
            }
        }
        moves.clear();
        sol = false;

        solve(0, 0);

        for (int i = 0; i < moves.size(); i++) {
            cout << s[moves[i]-1] << endl;
        }
        cout << "success" << endl;
    }
    return 0;
}
