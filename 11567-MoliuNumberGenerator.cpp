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

int low[5] = {1, 2, 3, 3, 4};

int main() {
  long long t;
  while (cin >> t) {
    long long cnt = 0;
    while (t > 0) {
      if (t < 6) {
        cnt += low[t-1];
        break;
      }

      if (t % 2 == 0)
        t /= 2;
      else if ( ( (t-1) / 2 ) % 2 == 0)
        t--;
      else
        t++;
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
