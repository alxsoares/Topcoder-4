#include <iostream>
#include <utility>
#include <limits>

using namespace std;

int cd[20];

pair<int, int> rb(int N, int S, int n, int s, int p) {
  if (s == S or N == n)
    return make_pair(s, p);
  pair<int, int> r1(s, p);
  if (s+cd[n] <= S)
    r1 = rb(N, S, n+1, s+cd[n], p|(1<<n));
  pair<int, int> r2 = rb(N, S, n+1, s, p);
  if (S-r1.first > S-r2.first)
    return r2;
  return r1;
}


int main() {
  int N, T;
  while (cin >> N) {
    cin >> T;
    for (int t = 0; t < T; ++t) {
      cin >> cd[t];
    }
    pair<int, int> r = rb(T, N, 0, 0, 0);
    for (int i = 0; i < T; ++i)
      if (r.second & (1<<i))
	cout << cd[i] << " ";
    cout << "sum:" << r.first << endl;
  }
  
  return 0;
}
