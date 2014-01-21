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

using namespace std;

bool solve(const string& s, int l) {
  string ss = s.substr(0, l);
  for (int i = 0; i < s.length(); i+=l) {
    if (s.find(ss, i) != i) return false;
  }
  return true;
}

int main() {
  string s;
  while (1) {
    cin >> s;
    if (s == ".") break;

    int n = 1+s.length();

    while (n--) {
      if (s.length() % n != 0)  continue;
      if (solve(s, s.length()/n)) {
	cout << n << endl;
	break;
      }
   }
  }

}
