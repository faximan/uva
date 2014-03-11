//
//  10810 - Ultra-Quick sort.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-02-26.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>

#define INF 1e11

using namespace std;

long long a[500001];
long long swaps;

void merge(int l, int middle, int r)
{
    long long temp[(r-l)+1];
    
    int index1 = l;
    int index2 = middle +1;
    
    int curel = 0;
    while(true)
    {
        if(index1 > middle && index2 > r)
            break;
        if(index2 <= r && (index1 > middle || a[index2] < a[index1]))
        {
            temp[curel++] = a[index2];
            index2++;
            
            if(index1 <= middle)
                swaps += (middle-index1)+1;
        }
        else if(index2 > r || a[index1] < a[index2])
        {
            temp[curel++] = a[index1];
            index1++;
        }
    }
    
    for (int i = 0; i < (r-l)+1; i++) {
        a[l+i] = temp[i];
    }
}


void merge_sort(int l, int r)
{
    int middle = (l+r)/2;
    
    if(r-l > 1)
    {
        merge_sort(l, middle);
        merge_sort(middle+1,r);
    }
    merge(l, middle, r);  
}

int main()
{
    int n;
    while (true) 
    {
        cin >> n;
        if(n == 0) break;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
               
        swaps = 0;
        merge_sort(0, n-1);       

        cout << swaps << endl;
    }    
    return 0;
}