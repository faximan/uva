//
//  146 - ID codes.cpp
//  IMPA
//
//  Created by Alexander Faxå on 2011-12-04.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    char a[50];
    char c;
    int n = 0;

    while((c = fgetc(stdin)) != '#')
    {
        if(c == '\n'){
            if(next_permutation(a, a+n))
                for(int i = 0; i < n; i++)
                    cout << a[i];
            else
                cout << "No Successor";
            cout << endl;
            n = 0;
        }
        else
        {
            a[n++] = c;
        }
    }
}
