#include <iostream>
#include <cstdio>


using namespace std;

int a[1000];

int main() {
  int n = 0;
  while (cin >> n) {
    if (n == 0) break;
    int e = 0, as = 0, ac = 0;
    for (int k = 0; k < n; ++k) {
      cin >> e;
      if (e != 0) {
        as += e;
        a[ac] = e;
        ++ac;
      }
    }
    
    for (int i = 0; i < ac; ++i) {
      cout << a[i];
      if (i != ac-1) cout << " ";
    }
    if (ac == 0)
      cout << 0;
    
    cout << endl;
  }
  return 0;
}
