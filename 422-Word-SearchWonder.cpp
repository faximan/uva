//
//  422 - Word-Search Wonder.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-13.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;
int l, length;
char c[101][101];
string s;

bool is_at(int x, int y, int i, int dx, int dy)
{
   // cout << sizeof(s) << endl;
    if (i == s.length())
        return true;
    if(x < 0 || y < 0 || x >= l || y >= l || c[x][y] != s[i])
        return false;
    else
        return is_at(x+dx,y+dy,i+1,dx,dy);

}

void find()
{
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            if(is_at(i, j, 0, 1, 0)){
                cout << i+1 << "," << j+1 << " " << i+length << "," << j+1 << endl;
                return;
            }
            if(is_at(i, j, 0, -1, 0)){
                cout << i+1 << "," << j+1 << " " << i+2-length << "," << j+1 << endl;
                return;
            }
            if(is_at(i, j, 0, 0, 1)){
                cout << i+1 << "," << j+1 << " " << i+1 << "," << j+length << endl;
                return;
            }
            if(is_at(i, j, 0, 0, -1)){
                cout << i+1 << "," << j+1 << " " << i+1 << "," << j+2-length << endl;
                return;
            }
            if(is_at(i, j, 0, 1, 1)){
                cout << i+1 << "," << j+1 << " " << i+length << "," << j+length << endl;
                return;
            }
            if(is_at(i, j, 0, 1, -1)){
                cout << i+1 << "," << j+1 << " " << i+length << "," << j+2-length << endl;
                return;
            }
            if(is_at(i, j, 0, -1, 1)){
                cout << i+1 << "," << j+1 << " " << i+2-length << "," << j+length << endl;
                return;
            }
            if(is_at(i, j, 0, -1, -1)){
                cout << i+1 << "," << j+1 << " " << i+2-length << "," << j+2-length << endl;
                return;
            }
        }
    }
    cout << "Not found" << endl;
}


int main()
{
    cin >> l;

    for(int i = 0; i < l; i++)
        for(int j = 0; j < l; j++)
            cin >> c[i][j];

    while(true)
    {
        cin >> s;
        length = s.length();
        if(s == "0") break;
        find();
    }
    return 0;
}
