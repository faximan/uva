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

#define MAX_N 101
#define EPS 1e-9
#define INF 0x3FFFFFFF

#define ii pair<int, int>
#define vi vector<int>

map<string, map<string, int> > m;

const vector<char> dict = {
  '2',
  '2',
  '2',
  '3',
  '3',
  '3',
  '4',
  '4',
  '4',
  '5',
  '5',
  '5',
  '6',
  '6',
  '6',
  '7',
  '7',
  '7',
  '7',
  '8',
  '8',
  '8',
  '9',
  '9',
  '9',
  '9'
};

map<string, pair<int, string> > dp;
map<string, string> translate;

string convert(const string& s) {
  string tr = "";
  for (int j = 0; j < s.length(); j++) {
    tr += dict[s[j]-'a'];
  }
  return translate[s] = tr;
}

string int_to_string(int i) {
  stringstream s;
  s << i;
  return s.str();
}

int dist(const string& s, string* converted) {
  *converted = translate[s];
  map<string, int>& v = m[*converted];

  int down = v[s];
  int up = v.size() - down;
  int best = min(down, up);

  if (best == 0) return s.length();

  *converted += (down <= up) ? 'U' : 'D' ;
  *converted += '(' + int_to_string(best) + ')';
  return s.length() + best;
}

int solve(const string& s, string* out) {
  if (dp.count(s)) {
    pair<int, string>& p = dp[s];
    *out = p.second;
    return p.first;
  }

  string converted;
  int best = INF;
  string best_string;
  
  for (int i = min(10, (int)s.length()); i > 0; i--) {
    const string first = s.substr(0, i);
    if (!translate.count(first))
      continue;

    int d = dist(first, &converted);
    if (d + 1 + (s.length()-i) >= best) continue;
    
    if (i == s.length()) {
      best = d;
      best_string = converted;
    } else {
      string second = s.substr(i, s.length()-i);
      string sec_converted;
      int rec = solve(second, &sec_converted);

      if (rec + 1 + d < best) {
	best = rec + 1 + d;
	best_string = converted + 'R' + sec_converted;
      }
    }
  }
  
  dp[s] = {best, best_string};
  *out = best_string;
  return best;
}

int main() {
  int ds;
  while (cin >> ds) {
    if (!ds) break;
    m.clear();
    dp.clear();
    for (int i = 0; i < ds; i++) {
      string s;
      cin >> s;
      map<string, int>& temp = m[convert(s)];
      temp.insert( {s, temp.size()} );
    }
    int q;
    cin >> q;
    for (int i = 0; i< q; i++) {
      string s;
      cin >> s;
      string out;
      solve(s, &out);
      cout << out << endl;
    }
  }
  return 0;
}
