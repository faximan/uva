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

char s[210000];
char buffer[110000];

int main() {
  while (scanf("%s", s) != EOF) {
    int l = strlen(s) - 1;
    int back = l;
    int runner = 0;

    int bp = 0;
    while (runner < back) {
      if (s[runner] == s[back]) {
        runner++;
        back--;
      } else {
        if (back == l) {
          buffer[bp] = s[bp];
          bp++;
          runner++;
        } else {
          for (; bp < runner; bp++) {
            buffer[bp] = s[bp];
          }
        }
        back = l;
      }
    }

    l++;
    for (int i = bp-1; i >= 0; i--) {
      s[l++] = buffer[i];
    }
    s[l] = '\0';
    printf("%s\n", s);
  }
  return 0;
}
