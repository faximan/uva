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

int test[10];
vector<pair<int, int> >p;

int solve() {
  int n = 1 << p.size();
  const int length = p.size();

  int best = 0;
  while (n--) {
    memset(test, 0, sizeof test);
    int cur = 0;
    for (int j = 0; j < length; j++) {
      if (!(n & (1 << j))) continue;

      int num_c = 0;
      int a = p[j].first;
      for (; a < p[j].second; a++) {
        if (test[a]) {
          for (int i = 0; i < num_c; i++) test[i + p[j].first] = 0;
          break;
        }
        test[a] = 1;
        num_c++;
      }
      if (a == p[j].second) cur++;
    }
    best = max(best, cur);
  }
  return best;
}

int main() {
  int c;
  cin >> c;
  while (c--) {
    p.clear();
    while (1) {
      int a, b;
      cin >> a >> b;
      if (!b) break;
      p.push_back({a,b});
    }
    cout << solve() << endl;
  }
  return 0;
}
