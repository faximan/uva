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
#include <sstream>

using namespace std;

#define MAX_N 101
#define EPS 1e-9
#define INF 0x7FFFFFFF

#define ii pair<int, int>
#define vi vector<int>

int main() {
  int t;
  cin >> t;
  bool first = true;
  while (t--) {
    if (!first) cout << endl;
    first = false;
    int c;
    cin >> c;
    vector<int> v(c);
    for (int i = 0; i < c; i++) v[i] = -1;
    int good = 0;
    int bad = 0;
    int nbr_sec = 0;
    string s;
    getline(cin, s);
    while (1) {
      getline(cin, s);
      if (s == "") break;
      char c;
      int a, b;
      stringstream ss(s);
      ss >> c >> a >> b;

      if (c== 'q') {
        if (v[a-1] == v[b-1]) good++;
        else bad++;
      } else {
        if (v[a-1] == -1 && v[b-1] != -1)
          v[a-1] = v[b-1];
        else if (v[a-1] != -1 && v[b-1] == -1)
          v[b-1] = v[a-1];
        if (v[a-1] == -1 && v[b-1] == -1) {
          v[a-1] = nbr_sec;
          v[b-1] = nbr_sec;
          nbr_sec++;
        } else {
          int temp = v[a-1];
          for (int i = 0; i < c; i++) {
            if (v[i] == temp) v[i] = v[b-1];
          }
        }
      }
    }
    cout << good << "," << bad << endl;
  }
  return 0;
}
