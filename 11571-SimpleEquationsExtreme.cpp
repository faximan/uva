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

#define EPS 1e-12

long double a, b, c, A, B, C;

inline long double myabs(long double n) {
  return n < 0 ? -n : n;
}

inline bool isSolution() {
  c = A - a - b;
  return b > a && c > b && myabs(C - a*a - b*b - c*c) < EPS;
}

bool calculate_b(const long double& x, long double& kvot, long double& root) {
  kvot = (x - A) / 2.0;
  const long double sqkvot = kvot * kvot;
  const long double BbyX = B/x;
  if (BbyX > sqkvot) return false;
  root = sqrtl(sqkvot - BbyX);
  return true;
}

bool solve() {
  const long double cube_root = floor(min(sqrtl(C)/2, pow(B, 0.34))) + 2;
  long double kvot, root;

  for (long double i = -cube_root; i < cube_root; i += 1.0) {
    if (!calculate_b(i, kvot, root)) continue;

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
  scanf("%d", &m);
  while (m--) {
    scanf("%Lf %Lf %Lf", &A, &B, &C);
    if (solve()) {
      printf("%0.Lf %0.Lf %0.LF\n", a+EPS, b+EPS, c+EPS);
    } else
      printf("No solution.\n");
  }
  return 0;
}
