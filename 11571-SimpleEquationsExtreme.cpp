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

long long a, b, c;
long double A, B, C, up, low;

bool solve() {



  return false;

}

int main() {
  int m;
  cin >> m;
  while (m--) {
    cin >> A >> B >> C;
    up = pow(B, 0.34) + 2;
    low = - min(sqrtl(B), sqrtl(C)) - 2;
    if (solve())
      cout << a << " " << b << " " << c << endl;
    else
      cout << "No solution." << endl;
  }
  return 0;
}
