//
//  704 - Color Hash.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-23.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

char temp_1, temp_2;
map<string, string>m;

string sol;

string turn_1(string a)
{
    temp_1 = a[10];
    temp_2 = a[11];
    for (int i = 11; i >= 2; i--)
        a[i] = a[i-2];
    a[0] = temp_1;
    a[1] = temp_2;

    a[21] = a[9];
    a[22] = a[10];
    a[23] = a[11];
    return a;
}

string turn_2(string a)
{
    temp_1 = a[12];
    temp_2 = a[13];
    for (int i = 14; i <= 23; i++)
        a[i-2] = a[i];
    a[22] = temp_1;
    a[23] = temp_2;

    a[9] = a[21];
    a[10] = a[22];
    a[11] = a[23];
    return a;
}

string turn_3(string a)
{
    temp_1 = a[0];
    temp_2 = a[1];
    for (int i = 2; i <= 11; i++)
        a[i-2] = a[i];
    a[10] = temp_1;
    a[11] = temp_2;

    a[21] = a[9];
    a[22] = a[10];
    a[23] = a[11];
    return a;
}

string turn_4(string a)
{
    temp_1 = a[22];
    temp_2 = a[23];
    for (int i = 23; i >= 14; i--)
        a[i] = a[i-2];
    a[12] = temp_1;
    a[13] = temp_2;

    a[9] = a[21];
    a[10] = a[22];
    a[11] = a[23];
    return a;
}

void generate_first(int prev, int depth, string cur, string seq)
{
    if(depth == 9)
        return;

    if(!m.count(cur) || m[cur].size() > seq.size() || (m[cur].size() == seq.size() && m[cur] > seq))
        m[cur] = seq;

    if(prev != 1)
        generate_first(3, depth+1, turn_3(cur), '1'+seq);
    if(prev != 2)
        generate_first(4, depth+1, turn_4(cur), '2'+seq);
    if(prev != 3)
        generate_first(1, depth+1, turn_1(cur), '3'+seq);
    if(prev != 4)
        generate_first(2, depth+1, turn_2(cur), '4'+seq);
}

void solve(int prev, int depth, string cur, string seq)
{
    if(depth == 9)
        return;

    if(m.count(cur))
        if(sol == "0" || sol.size() > seq.size() + m[cur].size() || (m[cur].size() == seq.size()  + m[cur].size() && m[cur] > seq))
           sol = seq + m[cur];

    if(prev != 3)
        solve(1, depth+1, turn_1(cur), seq+'1');
    if(prev != 4)
        solve(2, depth+1, turn_2(cur), seq+'2');
    if(prev != 1)
        solve(3, depth+1, turn_3(cur), seq+'3');
    if(prev != 2)
        solve(4, depth+1, turn_4(cur), seq+'4');
}

int main()
{
    int c;
    cin >> c;

    generate_first(0, 0, "034305650121078709a90121", "");
    for (int i = 0; i < c; i++)
    {
        string s = "";
        for (int i = 0; i < 24; i++)
        {
            int a;
            cin >> a;
            if(a == 10)
                s += 'a';
            else
                s += '0' + a;
        }

        if(s == "034305650121078709a90121"){
            cout << "PUZZLE ALREADY SOLVED" << endl;
            continue;
        }
        else
        {
            sol = "0";
            solve(0, 0, s, "");
            if(sol != "0")
                cout << sol << endl;
            else
                cout << "NO SOLUTION WAS FOUND IN 16 STEPS" << endl;
        }

    }

    return 0;

}
