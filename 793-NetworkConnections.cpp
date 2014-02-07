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

vector<int> v(100000);

int main() {
  int t;
  cin >> t;
  bool first = true;
  while (t--) {
    if (!first) cout << endl;
    first = false;
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) v[i] = i;
    int good = 0;
    int bad = 0;
    string s;
    getline(cin, s);
    while (1) {
      getline(cin, s);
      if (s == "") break;
      char d;
      int a, b;
      stringstream ss(s);
      ss >> d >> a >> b;

      if (d == 'q') {
        if (v[a-1] == v[b-1]) good++;
        else bad++;
      } else {
        int temp = v[a-1];
        for (int i = 0; i < c; i++) {
          if (v[i] == temp) v[i] = v[b-1];
        }
      }
    }

    cout << good << "," << bad << endl;
  }
  return 0;
}
