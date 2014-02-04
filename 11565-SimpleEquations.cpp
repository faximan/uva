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

#define SUPER_MAX 6000000000000000000

long long a,b,c, n;
long long A, B, C;

bool solve() {
  for (a = -min(sqrt(B), sqrt(C)); a < -1; a++) {
    if ( (B % -a) != 0) continue;
    const long long aa = a * a;

    for (b = -1; b > a; b--) {
      c = A - a - b;
      if (a * b > B / c) break;

      const long long bb = b * b;
      const long long cc = c * c;
      if (C - aa - bb < cc) break;
      if (B / a == b * c && C - aa - bb - cc == 0) return true;
    }
  }

  for (a = 1; a < n; a++) {
    const long long kvot = B / a;
    if (B != a * kvot) continue;
    const long long aa = a * a;
    if (2 * aa > C) break;

    for (b = a+1;; b++) {
      c = A - a - b;
      if (c <= b) break;
      if (b * c > kvot) break;

      const long long bb = b * b;
      if (aa + bb > C) break;
      const long long cc = c * c;
      if (C == aa + bb + cc && kvot == b * c) return true;
    }
  }
  return false;

}

int main() {
  int m;
  cin >> m;
  while (m--) {
    cin >> A >> B >> C;
    n = pow(B, 0.34) + 2;
    if (solve())
      cout << a << " " << b << " " << c << endl;
    else
      cout << "No solution." << endl;
  }
  return 0;
}
