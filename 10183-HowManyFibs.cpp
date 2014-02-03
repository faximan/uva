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

vector<string> fibs;

string add(string s1, string s2) {
  while (s1.length() < s2.length())
    s1 = '0' + s1;
  while (s2.length() < s1.length())
    s2 = '0' + s2;

  string res = "";
  int  carry = 0;
  for (int i = s1.length()-1; i >= 0; i--) {
    int sum = carry + (s1[i]-'0') + (s2[i]-'0');
    carry = sum / 10;
    sum = sum % 10;
    res = (char)(sum+'0') + res;
  }
  if (carry) res  = '1' + res;
  return res;
}

bool smaller(string s1, string s2) {
  while (s1.length() < s2.length())
    s1 = '0' + s1;
  while (s2.length() < s1.length())
    s2 = '0' + s2;

  for (int i = 0; i < s1.length(); i++) {
    if (s2[i] < s1[i]) return false;
    if (s2[i] > s1[i]) return true;
  }
  return true;
}

int main() {
  fibs.push_back("1");
  fibs.push_back("2");
  for (int i = 0; i < 500; i++) {
    fibs.push_back(add(fibs[fibs.size()-2], fibs[fibs.size()-1]));
  }

  string s1, s2;
  while (cin >> s1 >> s2) {
    if (s1 == "0" && s2 == "0") break;

    int count = 0;
    for (int i = 0; i < fibs.size(); i++) {
      if (smaller(s1, fibs[i]) && smaller(fibs[i], s2))
        count++;
    }
    cout << count << endl;
  }
  return 0;
}
