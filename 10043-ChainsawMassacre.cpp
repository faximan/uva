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

#define ii pair<int, int>
#define vi vector<int>

int l, w;

struct Point {
  int x, y;
  Point() {}
  Point(int xx, int yy) : x(xx), y(yy) {}
  bool operator<(const Point& rhs) const { return x < rhs.x; }
};

Point p[30000];

int main() {
  int cc;
  cin >> cc;
  while (cc--) {
    cin >> l >> w;
    int pos = 0;
    while(1) {
      int k;
      cin >> k;
      if (!k) break;
      int x, y, dx = 0, dy = 0;
      cin >> x >> y;
      if (k > 1) cin >> dx >> dy;
      for (int i = 0; i < k; i++) {
        p[pos++] = Point(x, y);
        p[pos++] = Point(0, y);
        p[pos++] = Point(x, 0);
        p[pos++] = Point(l, y);
        p[pos++] = Point(x, w);
        x += dx; y += dy;
      }
    }
    int best = pos == 0 ? (w * l) : 0;

    for (int k = 0; k < 4; k++) {
      sort(p, p+pos);

      for (int s = 0; s < pos; s++) {
        int low = 0;
        int high = w;
        for (int t = s+1; t < pos; t++) {
          best = max(best, (high - low) * (p[t].x - p[s].x));
          if (p[s].x == p[t].x) continue;
          if (p[s].y == p[t].y) break;
          if (p[t].y <= low || p[t].y >= high ) continue;
          if (p[t].y > p[s].y) high = p[t].y;
          if (p[t].y < p[s].y) low = p[t].y;
        }
      }

      for (int i = 0; i < pos; i++) {
        int newx = w - p[i].y;
        int newy = p[i].x;
        p[i].x = newx;
        p[i].y = newy;
      }
      swap(w,l);
    }
    cout << best << endl;
  }


  return 0;
}
