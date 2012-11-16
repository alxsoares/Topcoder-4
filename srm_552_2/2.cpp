#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class FoxPaintingBalls {
public:
  long long theMax(long long R, long long G, long long B, int N);
};

long long FoxPaintingBalls::theMax(long long R, long long G, long long B, int N) {
  int eq = 1;
  if (N%3 == 0 or N%3 == 2) eq = 0;
  vector<long long> v({R, G, B});
  sort(v.begin(), v.end());
  long long c = (N+1)*N/6;
  long long i = 0;
  if (c == 0) return R+G+B;
  while (v[2] >= c+eq and v[1] >= c and v[0] >= c) {
    long long t2 = v[2]/(c+eq);
    long long t1 = v[1]/(c);
    long long t0 = v[0]/(c);
    long long t = min(t2, min(t1, t0));

    v[2] -= t*(c+eq);
    v[1] -= t*c;
    v[0] -= t*c;
    i += t;
    sort(v.begin(), v.end());
  }
  return i;
}

int main() {
  FoxPaintingBalls o;
  cout << o.theMax(2, 2, 2, 3) << endl;
  //  cout << o.theMax(1, 2, 3, 3) << endl;
  //  cout << o.theMax(8, 6, 6, 4) << endl;
  //  cout << o.theMax(7, 6, 7, 4) << endl;
  //  cout << o.theMax(100, 100, 100, 4) << endl;
  //  cout << o.theMax(19330428391852493LL, 48815737582834113LL, 11451481019198930LL, 3456) << endl;
  //  cout << o.theMax(1, 1, 1, 1) << endl;
  return 0;
}
