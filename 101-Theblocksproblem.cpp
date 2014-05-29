//
//  101 - The blocks problem.cpp
//  IMPA
//
//  Created by Alexander Faxå on 2011-12-02.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

vector<int>v[25];
int ar[25];

int n;

void reset(int i){
    vector<int> newv;
    bool found = false;
    for(int j = 0; j < v[ar[i]].size(); j++){
        if(v[ar[i]][j] == i){
            found = true;
            continue;
        }
        if(!found)
            newv.push_back(v[ar[i]][j]);
        else
        {
            ar[v[ar[i]][j]] = v[ar[i]][j];
            v[v[ar[i]][j]].push_back(v[ar[i]][j]);
        }
    }
    newv.push_back(i);
    v[ar[i]] = newv;
}

void pile(int a, int b){
    vector<int> newv;
    int olda = ar[a];
    bool found = false;
    for(int j = 0; j < v[olda].size(); j++){
        if(v[olda][j] == a){
            found = true;
        }
        if(!found)
            newv.push_back(v[olda][j]);
        else
        {
            ar[v[olda][j]] = ar[b];
            v[ar[b]].push_back(v[olda][j]);
        }
    }
    v[olda] = newv;
}


int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        ar[i] = i;
        v[i].push_back(i);
    }

    while(true)
    {
        string c1, c2;
        int a, b;
        cin >> c1;
        if(c1 == "quit") break;
        cin >> a >> c2 >> b;
        if(a==b || ar[a] == ar[b])
            continue;

        if(c1 == "move"){
            if(c2 == "onto"){
                reset(b);
            }
            reset(a);
            v[ar[a]].pop_back();
            v[ar[b]].push_back(a);
            ar[a] = ar[b];
        }else if(c1 == "pile"){
            if(c2 == "onto"){
                reset(b);
            }
            pile(a,b);
        }
    }

    for(int i = 0; i < n; i++){
        cout << i << ":";
        for(int j = 0; j < v[i].size(); j++){
            cout << " " << v[i][j];
        }
        cout << endl;
    }

    return 0;
}
