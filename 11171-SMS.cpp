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
#define INF 0x7FFFFFFF

#define ii pair<int, int>
#define vi vector<int>

map<string, map<string, int> > m;

map<char, char> dict = {
  {'a','2'},
  {'b','2'},
  {'c','2'},
  {'d','3'},
  {'e','3'},
  {'f','3'},
  {'g','4'},
  {'h','4'},
  {'i','4'},
  {'j','5'},
  {'k','5'},
  {'l','5'},
  {'m','6'},
  {'n','6'},
  {'o','6'},
  {'p','7'},
  {'q','7'},
  {'r','7'},
  {'s','7'},
  {'t','8'},
  {'u','8'},
  {'v','8'},
  {'w','9'},
  {'x','9'},
  {'y','9'},
  {'x','9'}
};

map<string, pair<int, string> > dp;
map<string, string> cache_converted;

string convert(string s) {
  if (cache_converted.count(s)) return cache_converted[s];
  string tr = "";
  for (int j = 0; j < s.length(); j++) {
    tr += dict[s[j]];
  }
  return cache_converted[s] = tr;
}

string int_to_string(int i) {
  stringstream s;
  s << i;
  return s.str();
}

int dist(const string& s, string* converted) {
  if (dp.count(s)) {
    pair<int, string>& p = dp[s];
    *converted = p.second;
    return p.first;
  }

  *converted = convert(s);

  if (!m.count(*converted)) return -1;

  map<string, int>& v = m[*converted];
  if (!v.count(s)) return -1;

  int down = v[s];
  int up = v.size() - down;
  int best = min(down, up);

  if (best == 0) return s.length();

  *converted += (down <= up) ? 'U' : 'D' ;
  *converted += '(' + int_to_string(best) + ')';
  return s.length() + best;
}

int solve(string s, string* out) {
  if (!s.length()) return 0;

  if (dp.count(s)) {
    pair<int, string>& p = dp[s];
    *out = p.second;
    return p.first;
  }

  string converted;
  int best = INF;
  string best_string = "";

  for (int i = min(10, (int)s.length()); i > 0; i--) {
    string first = s.substr(0, i);
    int d = dist(first, &converted);
    if (d == -1 || d >= best) continue;
    
    if (i == s.length()) {
      if (d < best) {
	best = d;
	best_string = converted;
      }
    } else {
      string second = s.substr(i, s.length()-i);
      string sec_converted= "";
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
    for (int i = 0; i < ds; i++) {
      string s;
      cin >> s;
      map<string, int>& temp = m[convert(s)];
      temp.insert({s, temp.size()});
    }
    int q;
    cin >> q;
    for (int i = 0; i< q; i++) {
      string s;
      cin >> s;
      string out = "";
      solve(s, &out);
      cout << out << endl;
    }

  }


  return 0;
}
