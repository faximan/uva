//
//  108 - Maximum Sum.cpp
//  IMPA
//
//  Created by Alexander Faxå on 2011-11-30.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int aa[100][100];
int bb[100];
int n;
int kadane(){
    int m = -0x5FFFFFFF;
    int cms = 0;
    int csi = 0;
    for(int cei = 0; cei < n; cei++){
        cms = cms + bb[cei];
        if(cms > m)
            m = cms;
        
        if(cms < 0){
            cms = 0;
            csi = cei + 1;
        }
    }
        
    return m;
}

int main(){
    
    int m = -0x5FFFFFFF;
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> aa[i][j];
    
    for (int i = 0; i < n; i++)
        for(int j = 1; j < n; j++)
            aa[i][j] = aa[i][j-1]+aa[i][j]; 
        
    for(int i = 0; i < n; i++)
        for(int j = -1; j < i; j++){
            if(j==-1)
                for(int k = 0; k < n; k++)
                    bb[k] = aa[k][i];
            else
                for(int k = 0; k < n; k++)
                    bb[k] = aa[k][i] - aa[k][j];
            
            m = max(m, kadane());
        }           
            
    cout << m << endl;   
    return 0;
}