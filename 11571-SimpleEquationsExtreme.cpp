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

long long A, B, C;
long double a, b, c;

bool isSolution(const long double& aa, const long double& bb) {
  if (bb <= aa) return false;
  c = A - aa - bb;
  const bool res = c > bb && abs(C - aa*aa - bb*bb - c*c) < EPS;
  if (res) { b = bb; a = aa; }
  return res;
}

long double kvot, root;
bool calculate_b(const long long& x, long double& b1, long double& b2) {
  kvot = -(x - A) / 2.0;
  const long double sqkvot = kvot * kvot;
  const long double BbyX = B/x;
  if (BbyX > sqkvot) return false;
  root = sqrtl(sqkvot - BbyX);

  b1 = kvot - root;
  b2 = kvot + root;
  return true;
}

bool solve() {
  const long long cube_root = min(sqrtl( (long double)C )/2, pow( (long double)B, 0.34)) + 2;
  long double b1, b2;

  for (long long i = -cube_root; i < cube_root; i++) {
    if (i == 0 || (B % i != 0) || !calculate_b(i, b1, b2)) continue;

    if (i < 0) {
      if (isSolution(b1, i))  return true;
      if (isSolution(b2, i))  return true;
    } else {
      if (isSolution(i, b1)) return true;
      if (isSolution(i, b2)) return true;
    }
  }
  return false;
}

int main() {
  int m;
  scanf("%d", &m);
  while (m--) {
    scanf("%llu %llu %llu", &A, &B, &C);
    if (solve()) {
      printf("%0.Lf %0.Lf %0.Lf\n", a+EPS, b+EPS, c+EPS);
    } else
      printf("No solution.\n");
  }
  return 0;
}
