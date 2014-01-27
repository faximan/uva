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

char s[MAX_N];
int n, num_nodes;

char lazy[4 * MAX_N];
int size[4 * MAX_N];
int st[4 * MAX_N];

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
  int diff = 0;
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
  // const int pl = left(p);
  // const int pr = right(p);

  // if (pl <= num_nodes) {
  //   if (lazy[pl] != 'A') updateOne(lazy[pl], pl);
  //   lazy[pl] = ch;
  // }
  // if (pr <= num_nodes) {
  //   if (lazy[pr] != 'A') updateOne(lazy[pr], pr);
  //   lazy[pr] = ch;
  // }

  return diff;
}

char ppp(char old, char nnn) {
  if (nnn == 'E' ) return 'E';
  if (nnn == 'F' ) return 'F';
  if (nnn == 'I' ) {
    if (old == 'E') return 'F';
    if (old == 'F') return 'E';
    if (old == 'I') return 'A';
    if (old == 'A') return 'I';
  }
  assert(false);
return '?';

}

int update(char ch, int p, int L, int R, int a, int b, char over) {
  if (over != 'A') {
    updateOne(over, p);
    lazy[p] = ppp(lazy[p], over);
  }
  if (a > R || b < L) return 0;

  // if (lazy[p] != 'A') {
  //   updateOne(lazy[p], p);
  //   lazy[p] = 'A';
  // }

  if (L >= a && R <= b) {
    const int ans = updateOne(ch, p);
    lazy[p] = ppp(lazy[p], ch);
    return ans;
  }

  int diff = update(ch, left(p), L, (L+R)/2, a, b, lazy[p]);
  diff += update(ch, right(p), (L+R)/2 + 1, R, a, b, lazy[p]);
  st[p] += diff;
  lazy[p] = 'A';
  return diff;
}

int query(int p, int L, int R, int a, int b, char over) {
  if (over != 'A') {
    updateOne(over, p);
    lazy[p] = ppp(lazy[p], over);
  }
  if (a > R || b < L) return 0;

  // if (lazy[p] != 'A') {
  //   updateOne(lazy[p], p);
  //   lazy[p] = 'A';
  // }

  if (L >= a && R <= b)
    return st[p];

  const int res_l = query(left(p), L, (L+R)/2, a, b, lazy[p]);
  const int res_r = query(right(p), (L+R)/2 + 1, R, a, b, lazy[p]);
  lazy[p] = 'A';
  return res_l + res_r;
}

int main() {
  int cc, m, t, q, a, b;
  char temp[60];
  char ch;

  scanf("%d", &cc);
  for (int c = 1; c <= cc; c++) {
    printf("Case %d:\n", c);
    scanf("%d", &m);
    n = 0;
    num_nodes = 0;
    while (m--) {
      scanf("%d %s", &t, temp);
      const int len = strlen(temp);
      while (t--) {
        for (int i = 0; i < len; i++)
          s[n++] = temp[i];
      }
    }

    build(1, 0, n-1);

    for (int i = 0; i <= num_nodes; i++) {
      lazy[i] = 'A';
    }

    scanf("%d", &q);
    int num_s = 0;
    while (q--) {
      scanf(" %c %d %d", &ch, &a, &b);
      if (ch != 'S') {
        update(ch, 1, 0, n - 1, a, b, 'A');
      } else {
        printf("Q%d: %d\n", ++num_s, query(1, 0, n - 1, a, b, 'A'));
      }
    }
  }
  return 0;
}
