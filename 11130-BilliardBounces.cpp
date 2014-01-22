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
#define DEGREES_TO_RADIANS(angle) ((angle) / 180.0 * M_PI)

#define ii pair<int, int>
#define vi vector<int>

double a, b, A, v, s;

int main() {
  while (1) {
    cin >> a >> b >> v >> A >> s;
    if (!a) break;

    A = DEGREES_TO_RADIANS(A);
    v /= 2.0;

    double vy = sin(A) * v;
    double vx = cos(A) * v;

    double px = a / 2.0;
    double py = b / 2.0;

    int hx = 0;
    int hy = 0;

    while (1) {
      double tx = vx < EPS ? INF : px / vx;
      double ty = vy < EPS ? INF : py / vy;

      double mint = min(tx, ty);
      if (mint > s) break;
      s -= mint;

      if (tx < ty + EPS && ty < tx + EPS) {
	hx++;
	hy++;
	px = a;
	py = b;
      }
      else if (tx < ty) {
	hx++;
	px = a;
	py -= vy * tx;
      }
      else if (ty < tx) {
	hy++;
	py = b;
	px -= vx * ty;
      }
    }

    cout << hx << " " << hy << endl;
  }
  return 0;
}
