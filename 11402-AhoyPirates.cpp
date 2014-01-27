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

#define MAX_N 1024100
#define EPS 1e-9
#define INF 0x7FFFFFFF

#define ii pair<int, int>
#define vi vector<int>

char s[MAX_N];
int n, num_nodes;

char lazy[4 * MAX_N];
int size[4 * MAX_N];

vi st, A;

int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }

void build(int p, int L, int R) {
  num_nodes = max(num_nodes, p);
  if (L == R) {
    st[p] = (s[L] == '1');
    size[p] = 1;
  }
  else {
    const int pl = left(p);
    const int pr = right(p);
    build(pl, L, (L + R) / 2);
    build(pr, (L + R) / 2 + 1, R);
    st[p] = st[pl] + st[pr];
    size[p] = size[pl] + size[pr];
  }
}

int updateOne(char ch, int p) {
  int diff;
  if (ch == 'F') {
    diff = size[p] - st[p];
    st[p] = size[p];
  } else if (ch == 'E') {
    diff = -st[p];
    st[p] = 0;
  } else if (ch == 'I') {
    int now = size[p] - st[p];
    diff = now - st[p];
    st[p] = now;
  }
  const int pl = left(p);
  const int pr = right(p);

  if (pl <= num_nodes) {
    if (lazy[pl] != 'A') updateOne(lazy[pl], pl);
    lazy[pl] = ch;
  }
  if (pr <= num_nodes) {
    if (lazy[pr] != 'A') updateOne(lazy[pr], pr);
    lazy[pr] = ch;
  }

  return diff;
}

int update(char ch, int p, int L, int R, int a, int b) {
  if (p > num_nodes) return 0;
  if (a > R || b < L) return 0;

  if (lazy[p] != 'A') {
    updateOne(lazy[p], p);
    lazy[p] = 'A';
  }

  if (L >= a && R <= b) {
    return updateOne(ch, p);
  }

  int diff = 0;
  diff += update(ch, left(p), L, (L+R)/2, a, b);
  diff += update(ch, right(p), (L+R)/2 + 1, R, a, b);
  st[p] += diff;
  return diff;
}

int query(int p, int L, int R, int a, int b) {
  if (p > num_nodes) return 0;
  if (a > R || b < L) return 0;

  if (lazy[p] != 'A') {
    updateOne(lazy[p], p);
    lazy[p] = 'A';
  }

  if (L >= a && R <= b)
    return st[p];

  const int res_l = query(left(p), L, (L+R)/2, a, b);
  const int res_r = query(right(p), (L+R)/2 + 1, R, a, b);
  return res_l + res_r;
}

int main() {
  int cc, m, t, q, a, b;
  string temp;
  char ch;

  cin >> cc;
  for (int c = 1; c <= cc; c++) {
    printf("Case %d:\n", c);
    cin >> m;
    n = 0;
    num_nodes = 0;
    while (m--) {
      cin >> t >> temp;
      while (t--) {
        for (int i = 0; i < temp.length(); i++)
          s[n++] = temp[i];
      }
    }
    st.assign(4 * n, 0);
    for (int i = 0; i < 4 *n; i++) {
      lazy[i] = 'A';
      size[i] = 0;
    }

    build(1, 0, n-1);

    cin >> q;
    int num_s = 0;
    while (q--) {
      cin >> ch >> a >> b;
      if (ch != 'S') {
        update(ch, 1, 0, n - 1, a, b);
      } else {
        const int ans = query(1, 0, n - 1, a, b);
        printf("Q%d: %d\n", ++num_s, ans);
      }
    }
  }
  return 0;
}
