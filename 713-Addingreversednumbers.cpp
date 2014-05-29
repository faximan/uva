//
//  713 - Adding reversed numbers.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-27.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{

    int n;
    char c;
    cin >>noskipws>> n;
    cin >> c;

    while(n--)
    {

        int a[201];
        int b[201];

        int i, j;

        for(i = 0;;i++)
        {
            cin >> noskipws >> c;
            if(c == ' ') break;
            a[i] = c - '0';
        }
        for(j = 0;;j++)
        {
            cin >> noskipws >> c;
            if(c == '\n' || c == '\0') break;
            b[j] = c - '0';
        }

        int res[202];
        int index = 0;
        int carry = 0;

        int ii = 0;
        int jj = 0;
        while(ii < i || jj < j)
        {
            int temp;
            if(ii >= i)
            {
                temp = b[jj++] + carry;
            }
            else if(jj >= j)
            {
                temp = a[ii++] + carry;

            }
            else
            {
                temp = a[ii++] + b[jj++] + carry;
            }
            carry = temp / 10;
            res[index++] = temp % 10;
        }
        if(carry)
            res[index++] = carry;

        int cur = 0;
        while(!res[cur])
            cur++;
        while(cur < index)
            cout << res[cur++];
        cout << endl;
    }
    return 0;
}
