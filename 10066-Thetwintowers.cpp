//
//  10066 - The twin towers.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-13.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>


using namespace std;

int n1, n2;
int a[102];
int b[102];

int LCS()
{
    int c[n1+1][n2+1];
    for(int i = 0; i <= n1; i++)
        c[i][0] = 0;
    for(int j = 0; j <= n2; j++)
        c[0][j] = 0;
    for(int i = 1; i <= n1; i++)
        for(int j = 1; j <= n2; j++){
            if(a[i] == b[j])
                c[i][j] = c[i-1][j-1]+1;
            else
                c[i][j] = max(c[i][j-1],c[i-1][j]);
        }
    return c[n1][n2];
}



int main(){
    int c = 0;
    while(true){
        cin >> n1 >> n2;
        if(n1 == 0 && n2 == 0)
            break;

        for(int i = 0; i < n1; i++)
            cin >> a[i+1];
        for(int i = 0; i < n2; i++)
            cin >> b[i+1];

        cout << "Twin Towers #" << ++c << endl;
        cout << "Number of Tiles : " << LCS() << endl << endl;
    }

    return 0;
}
