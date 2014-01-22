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
pair<string, int> dp[250002];
string s;

string int_to_string(int i) {
  stringstream s;
  s << i;
  return s.str();
}

#define INF 0x3FFFFFFF

int solve(int idx, trie_node* cur, string& out, bool first) {
  if (cur == NULL) return INF;
  if (first && dp[idx].second != -1) return dp[idx].second;

  int best;
  string best_string;

  // If this is the last letter
  if (idx == s.length() - 1) {
    if (cur->order == -1) return INF;

    best = cur->order;
    best_string = cur->print;
  } else {
    // Keep on
    best = solve(idx + 1, cur->child[s[idx + 1] - 'a'], best_string, false);

    // Compare to stop here if ok
    if (cur->order != -1) {
      string sec_string;
      int stop_here = solve(idx + 1, root->child[s[idx + 1] - 'a'], sec_string, true);

      stop_here += 1 + cur->order;
      if(stop_here < best) {
	best = stop_here;
	best_string = cur->print + 'R' + sec_string;
      }
    }
  }

  if ( first ) dp[idx] = { best_string,  best };
  out = best_string;
  return best;
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
}

void delete_mem(trie_node* cur) {
  for (int i = 0; i < 30; i++) {
    if (cur->child[i]) delete_mem(cur->child[i]);
  }
  delete cur;
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
	dp[j] = {"",-1};
      }

      string res;
      solve(0, root->child[s[0] - 'a'], res, true);
      printf("%s\n", res.c_str());
    }
    delete_mem(root);

  }
  return 0;
}
