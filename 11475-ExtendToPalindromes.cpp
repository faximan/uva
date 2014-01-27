#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <cstring>
#include <cassert>

using namespace std;

#define INF 0x7FFFFFFF

char T [210000];
char P [210000];
int b[110000], n, m;

void kmpP() {
  int i = 0, j = -1;
  b[0] = -1;
  while (i < m) {
    while (j >= 0 && P[i] != P[j]) j = b[j];
    i++;
    j++;
    b[i] = j;
  }
}

int kmpS() {
  int i = 0, j = 0;
  int best = 0;
  while (i < n) {
    while (j >= 0 && T[i] != P[j]) j = b[j];
    i++;
    j++;
    best = max(best, i-j);
    if (j == m) {
      j = b[j];
    }
  }
  return best;
}

int main() {
  while (scanf("%s", T) != EOF) {
    m = n = strlen(T);
    for (int i = 0; i < n; i++)
      P[n-i-1] = T[i];
    kmpP();
    int t = kmpS();
    for (int i = 0; i < t; i++)
      T[n++] = T[t-i-1];
    T[n] = '\0';
    printf("%s\n", T);
  }
  return 0;
}
