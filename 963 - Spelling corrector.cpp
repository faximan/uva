//
//  963 - Spelling corrector.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-26.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

// OBS! DETTA PROBLEM ÄR TRASIGT OCH BÖR LÄSAS UTAN INDATA

/*

#include <iostream>
#include <algorithm>

#define INF 0x7FFFFFFF

using namespace std;

string dict[10000000];

int levD(string s, string t)
{
    int m = s.length();
    int n = t.length();
    
    int d[m+1][n+1];
    
    for (int i = 0; i <= m; i++)
        d[i][0] = i;
    for (int j = 0; j <= n; j++)
        d[0][j] = j;
            
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if(s[i-1] == t[j-1])
            {
                d[i][j] = d[i-1][j-1];
            }
            else
            {
                d[i][j] = min(d[i-1][j] + 3, min(d[i][j-1] + 3, d[i-1][j-1] + 5));
            }
        }
    }
    return d[m][n];
}


int main()
{
    int nbr_dict, nbr_words;
    cin >> nbr_dict;
    
    for (int i = 0; i < nbr_dict; i++) {
        cin >> dict[i];
    }
    
    sort(dict, dict + nbr_dict);
    
    cin >> nbr_words;
    int cnt = 0;
    string s;
    
    for (int i = 0; i < nbr_words; i++) {
        cin >> s;
        
        if(cnt == 10)
        {
            cout << endl;
            cnt = 0;
        }
        else if(cnt != 0)
            cout << " ";
        cnt++;
        
        int best_so_far = INF;
        int index = -1;
        
        for (int j = 0; j < nbr_dict; j++) {
            int res = levD(s, dict[j]);
            if(res < best_so_far)
            {
                best_so_far = res;
                index = j;
            }
        }
        cout << dict[index];
    }
    cout << endl;
    return 0;
}
*/