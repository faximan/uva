//
//  10029 - Edit step ladder.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-03-21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define MAX_WORDS 25001

using namespace std;
char word[MAX_WORDS][20];

void add(char *source,char *dest, char letter, int pos)
{
    int i;
    for(i = 0; i < pos; i++)
        dest[i] = source[i];
    
    dest[pos]=letter;
    
    for(; source[i] ;i++)
        dest[i + 1] = source[i];
    
    dest[i + 1]='\0';
}

void del(char *source, char *dest, int pos)
{
    int i;
    for(i = 0; i < pos; i++) 
        dest[i] = source[i];
    
    i++;
    for(; source[i]; i++)
        dest[i - 1] = source[i];
    
    dest[i - 1] = '\0';
}
void change(char *source, char *dest, char letter, int pos)
{
    int i;
    for(i = 0; source[i]; i++)
        dest[i] = source[i];
    
    dest[pos] = letter;
    dest[i] = '\0';
}

int binary_search(char *s,int n)
{
    int lower = 0;
    int upper = n - 1;
    int mid;
    
    while(lower <= upper)
    {
        mid = (lower + upper) / 2;
        
        int res = strcmp(word[mid],s);
        if(res == 0) 
            return mid;
        if(res < 0) 
            lower = mid+1;
        else 
            upper = mid-1;
    }
    return -1;
}

int main()
{
    int max_ladder = 1;
    int n = 0;
    char s[20];
    int f[MAX_WORDS];
    int res;
    
    while(cin>>word[n++]);
    
    f[0] = 1;
    
    for(int i=1 ; i < n; i++)
    {
        f[i] = 1;
        
        for(int j = 0; word[i][j]; j++)
        {
            del(word[i], s, j);
            res = binary_search(s,i);
            if(res >= 0)
                f[i] = max(f[i], f[res]+1);
            
            for(int letter = 0; letter < 26; letter++)
            {
                add(word[i], s, letter + 'a', j);             
                res = binary_search(s,i);
                if(res >= 0)
                    f[i] = max(f[i], f[res]+1);
                
                change(word[i], s, letter + 'a', j);       
                res = binary_search(s,i);
                if(res >= 0)
                    f[i] = max(f[i], f[res] + 1);
            }
        }
        
        max_ladder = max(max_ladder, f[i]);
    }
    
    cout << max_ladder << endl;
    return 0;
}