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

int n, m, e, p, b;

vector<ii> AdjList[MAX_N];
set<int> exits;
bool can_use[MAX_N];

bool visited[MAX_N];

vi ssp;
vi ssb;

vi SSSP(int s) {
  vi dist(n, INF);
  dist[s] = 0;

  priority_queue< ii, vector<ii>, greater<ii> > pq;
  pq.push(ii(0, s));
  while (!pq.empty()) {
    ii front = pq.top();
    pq.pop();
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];
      if (dist[u] + v.second < dist[v.first]) {
	dist[v.first] = dist[u] + v.second;
	pq.push(ii(dist[v.first], v.first));
      }
    }
  }
  return dist;
}

bool path_exits() {
  memset(visited, false, sizeof visited);
  queue<int> q;
  q.push(b);
  visited[b] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < AdjList[cur].size(); i++) {
      int next = AdjList[cur][i].first;
      if (can_use[next] && !visited[next]) {
	if (exits.count(next)) return true;
	visited[next] = true;
	q.push(next);
      }
    }
  }
  return false;
}

double solve() {
  if (exits.count(b)) return 0.0;
  if (e == 1 && exits.count(p)) return -1;

  double lower = 0.000001;
  double upper = INF;

  while (lower < upper && (upper - lower) >= EPS) {
    double speed = (lower + upper) / 2.0;
    memset(can_use, true, sizeof can_use);

    for (int i = 0; i < n; i++) {
      double time_p = (double)ssp[i] / 160.0;
      double time_b = (double)ssb[i] / speed;

      if ( time_p <= time_b ) {
	can_use[i] = false;
      }
    }

    if (path_exits()) {
      upper = speed;
    } else {
      lower = speed;
    }
  }
  return (lower < INF-1) ? lower : -1;
}

int main() {
  int cc;
  cin >> cc;
  while (cc--) {
    for (int i = 0; i < MAX_N; i++)
      AdjList[i].clear();
    exits.clear();

    cin >> n >> m >> e;
    for (int i = 0; i < m; i++) {
      int a, b, l;
      cin >> a >> b >> l;
      AdjList[a-1].push_back({b-1,l});
      AdjList[b-1].push_back({a-1,l});
    }

    for (int i = 0; i < e; i++) {
      int temp;
      cin >> temp;
      exits.insert(temp-1);
    }

    cin >> b >> p;
    b--; p--;
    ssp = SSSP(p);
    ssb = SSSP(b);

    double res = solve();
    if (res < 0.0) {
      printf("IMPOSSIBLE\n");
    }
    else
      printf("%.9f\n", res);

  }
  return 0;
}
