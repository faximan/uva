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

using namespace std;

#define MAX_N 101
#define EPS 1e-9
#define INF 0x7FFFFFFF

#define ii pair<int, int>
#define vi vector<int>

int main() {
  long long t;
  while (cin >> t) {
    long long n1 = 1;
    long long n2 = 2;
    long long cnt = 1;

    while (n2 <= t) {
      n1 = n2;
      n2 *= 2;
      cnt++;
    }

    cout << cnt + min(t-n1, 1+n2-t) << endl;

  }


  return 0;
}
