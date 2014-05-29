//
//  10035 - Primary arithmetic.cpp
//  IMPA
//
//  Created by Alexander Faxå on 2011-11-29.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    long long a, b;
    while(true){
        cin >> a >> b;
        if(a == 0 && b == 0)
            break;

        int res = 0;
        int carry = 0;

        while(a > 0 || b > 0){
            int aa = a % 10;
            int bb = b % 10;

            if(aa + bb + carry > 9){
                carry = 1;
                res++;
            }else
                carry = 0;

            a /= 10;
            b /= 10;
        }

        if(res == 0)
            cout << "No carry operation." << endl;
        else if (res == 1)
            cout << "1 carry operation." << endl;
        else
            cout <<res << " carry operations." << endl;
    }
    return 0;
}
