#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

int strToInt(string sm) {
  int m = 0;
  istringstream buffer(sm);
  buffer >> m;
  return m;
}

int main() {
  int TC = 0;
  cin >> TC;

  for (int tc = 0; tc < TC; ++tc) {
    int N = 0, D = 0;
    cin >> N >> D;

    int small_stone_num = 0;
    int going = 0, returning = 0;
    int max_going = 0, max_returning = 0;
    for (int n = 0; n < N; ++n) {
      string e; cin >> e;
      char s = e[0];
      string sm = e.substr(2, e.size()-2);
      int m = strToInt(sm);

      if (s == 'B') {
        max_going = max(max_going, m - going);
        max_returning = max(max_returning, m - returning);
        going = m;
        returning = m;
        //        printf("B going=%d returning=%d\n", going, returning);
      }
      if (s == 'S' &&
          small_stone_num % 2 == 0) {
        max_going = max(max_going, m - going);
        going = m;
        ++small_stone_num;
        //        printf("S going=%d returning=%d\n", going, returning);        
      } else if (s == 'S' &&
          small_stone_num % 2 == 1) {
        max_returning = max(max_returning, m - returning);
        returning = m;
        ++small_stone_num;
        //        printf("S going=%d returning=%d\n", going, returning);
      }

      /*      printf("max_going=%d max_returning=%d\n",
             max_going, max_returning);
      */
    }

    max_going = max(max_going, D - going);
    max_returning = max(max_returning, D - returning);
    /*    printf("D=%d\n", D);
    printf("max_going=%d max_returning=%d\n",
             max_going, max_returning);
    */
    printf("Case %d: %d\n", tc + 1, max(max_going, max_returning));
  }
  
  return 0;
}
