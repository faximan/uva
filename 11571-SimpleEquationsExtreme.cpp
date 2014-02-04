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
  if (IsInteger(b) && b > a && c > b) {
    if ( myabs(C - a*a - b*b - c*c) < EPS) return true;
  }
  return false;
}

bool calculate_b(long double& kvot, long double& root) {
  kvot = (a - A) / 2;
  const long double sqkvot = kvot * kvot;
  const long double Bbya = B/a;
  if (Bbya >= sqkvot) return false;
  root = sqrtl(sqkvot - Bbya);
  return true;
}

bool solve() {
  a = - min(floor(sqrtl(B)), floor(sqrtl(C))) - 2;
  long double up = pow(B, 0.34) + 2;
  long double kvot, root;

  for (; a < up; a += 1.0) {
    if (myabs(a) < EPS) continue;
    if (!calculate_b(kvot,root)) continue;

    b = -kvot + root;
    if (isSolution()) return true;
    b = -kvot - root;
    if (isSolution()) return true;
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
