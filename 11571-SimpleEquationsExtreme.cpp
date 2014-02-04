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
#include <cmath>
#include <ctgmath>

using namespace std;

#define SUPER_MAX 6000000000000000000

#define EPS 1e-12

long double a, b, c;
long double A, B, C;

inline long double myabs(long double n) {
  return n < 0 ? -n : n;
}

inline bool IsInteger(long double n)
{
  n = (n < 0) ? -n : n;
  return n - floor(n) < EPS;
}

inline bool isSolution() {
  c = A - a - b;
  if (b > a && c > b && IsInteger(b)) {
    if ( myabs(C - a*a - b*b - c*c) < EPS) return true;
  }
  return false;
}

bool calculate_b(const long double& x, long double& kvot, long double& root) {
  kvot = (x - A) / 2.0;
  const long double sqkvot = kvot * kvot;
  const long double BbyX = B/x;
  if (BbyX >= sqkvot) return false;
  root = sqrtl(sqkvot - BbyX);
  return true;
}

bool solve() {
  const long double cube_root = min((long double)floor(sqrtl(C)), (long double)floor((long double)pow(B, (long double)0.34))) + 2;
  long double kvot, root;

  for (long double i = -cube_root; i < cube_root; i += 1.0) {
    if (myabs(i) < EPS) continue;
    if(!calculate_b(i, kvot, root)) continue;

    if (i < 0) {
      b = i;
      a = -kvot + root;
      if (isSolution()) return true;
      a = -kvot - root;
      if (isSolution()) return true;
    } else if (i > 0) {
       a = i;
       b = -kvot + root;
       if (isSolution()) return true;
       b = -kvot - root;
       if (isSolution()) return true;
    }
  }
  return false;
}

int main() {
  int m;
  cin >> m;
  while (m--) {
    cin >> A >> B >> C;

    if (solve()) {
      cout.precision(0);
      cout << fixed << (a+EPS) << " " << (b+EPS) << " " << (c+EPS) << endl;
    } else
      cout << "No solution." << endl;
  }
  return 0;
}
