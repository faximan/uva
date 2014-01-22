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
#include <sstream>

using namespace std;

#define MAX_N 600
#define EPS 1e-9
#define INF 0x7FFFFFFF

#define ii pair<int, int>
#define vi vector<int>

int n, k;
int t[6];

vector<ii> AdjList[MAX_N];
int stop[6][101];

vi SSSP() {
  vi dist(MAX_N, INF);
  dist[0] = 0;

  priority_queue< ii, vector<ii>, greater<ii> > pq;
  pq.push(ii(0, 0));
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

int main() {
  while (cin >> n >> k) {
    memset(stop, 0, sizeof stop);
    for (int i = 0; i < MAX_N; i++)
      AdjList[i].clear();

    for (int i = 0; i < n; i++) {
      cin >> t[i];
    }

    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
      getline(cin, s);
      stringstream ss;
      ss << s;

      int a;
      while (ss >> a) {
	stop[i][a] = 1;
      }
    }

    for (int i = 0; i < 101; i++) {
      for (int a = 0; a < n; a++) {
	for (int b = a+1; b < n; b++) {
	  if (stop[a][i] && stop[b][i]) {
	    int time = (i == 0) ? 0 : 60;
	    AdjList[100 * a + i].push_back( {100 * b + i, time} );
	    AdjList[100 * b + i].push_back( {100 * a + i, time} );
	  }
	}
      }
    }

    for (int i = 0; i < n; i++) {
      int prev = -1;
      for (int j = 0; j < 101; j++) {
	if (stop[i][j]) {
	  if (prev != -1) {
	    AdjList[100 * i + prev].push_back( {100 * i + j, t[i] * (j - prev)} );
	    AdjList[100 * i + j].push_back( {100 * i + prev, t[i] * (j - prev)} );
	  }
	  prev = j;
	}
      }
    }

    vi res = SSSP();
    int best = INF;
    for (int i = 0; i < n; i++) {
      best = min(best, res[i * 100 + k]);
    }

    if (best < INF) cout << best << endl;
    else cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
