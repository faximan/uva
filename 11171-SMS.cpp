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

map<string, int> key_to_num;

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

struct trie_node {
  trie_node() {
    for (int i = 0; i < 30; i++) {
      child[i] = NULL;
    }
    print = "";
    order = -1;
  }
  int order;
  string print;
  trie_node* child[30];
};

trie_node* root;
pair<pair<trie_node*, int>, int> dp[250002];
string s;

string int_to_string(int i) {
  stringstream s;
  s << i;
  return s.str();
}

#define INF 0x3FFFFFFF

void solve() {
  int best, pos;

  trie_node* next_t;
  int next_d;

  for (int idx = s.length() - 1; idx >= 0; idx--) {
    best = INF;
    pos = idx;
    trie_node* cur = root;
    while (1) {
      cur = cur->child[s[pos] - 'a'];
      if (cur == NULL) break;

      if (cur->order != -1) {
	int sec = cur->order;
	if (pos != s.length() - 1) {
	  sec += 1 + dp[pos + 1].second;
	}

	if (sec < best) {
	  best = sec;

	  next_t = cur;
	  next_d = pos+1;
	}
      }
      pos++;
      if (pos == s.length()) break;
    }
    if (best < INF) {
      dp[idx] = { {next_t, next_d}, best};
    }
  }
}

void appendUD(trie_node* cur) {
  if (cur->order != 0) {
    int up = cur->order;
    int down = key_to_num[cur->print] - up;
    int best = min(up, down);
    cur->print += down < up ? 'D' : 'U';
    cur->print += '(' + int_to_string(best) + ')';
    cur->order = best;
  }
  cur->order += cur->print.length();
}

int main() {
  int ds;
  while (cin >> ds) {
    if (!ds) break;

    root = new trie_node();
    key_to_num.clear();

    vector<trie_node*> nodes;
    for (int i = 0; i < ds; i++) {
      cin >> s;
      trie_node* cur = root;
      string key = "";
      for (int j = 0; j < s.length(); j++) {
	const int idx = s[j] - 'a';
	key += dict[idx];
	if (cur->child[idx] == NULL) cur->child[idx] = new trie_node();
	cur = cur->child[idx];
      }
      if (key_to_num.count(key)) {
	cur->order = key_to_num[key]++;
      } else {
	cur->order = 0;
	key_to_num[key] = 1;
      }
      cur->print = key;
      nodes.push_back(cur);
    }

    for (trie_node *tn : nodes) {
      appendUD(tn);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
      cin >> s;
      for (int j = 0; j < s.length()+1; j++) {
	dp[j] = {{NULL, INF}, INF};
      }

      solve();
      string res = "";
      pair<trie_node *, int>& cur = dp[0].first;

      while (1) {
	if (cur.first == NULL) break;
      	res += cur.first->print + 'R';
	cur = dp[cur.second].first;
      }

      printf("%s\n", res.substr(0, res.length()-1).c_str());
    }
  }
  return 0;
}
