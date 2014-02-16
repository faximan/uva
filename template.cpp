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

int n, m;
stirng s;

vector<string> v;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> s;
    int res = solve(s);
    cout << res << endl;
  }

  return 0;
}
