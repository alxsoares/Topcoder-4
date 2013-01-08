#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

vector <pair<int, int> > mv;

bool rb(int Right, int N, int end, int p) {
  if (N == 0 and end != Right) {
    //        printf("right=%d n=%d end=%d p=%d false\n", Right, N, end, p);
    return false;
  }
  if (N == 0 and end == Right) {
    //  printf("right=%d n=%d end=%d p=%d true\n", Right, N, end, p);
    return true;
  }
  bool r = false;
  for (int i = 0; i < mv.size(); ++i) {
    if (not (p&(1<<i)) and end == mv[i].first) {
      r = r or rb(Right, N-1, mv[i].second, p|(1<<i));
    } else if (not (p&(1<<i)) and end == mv[i].second) {
      r = r or rb(Right, N-1, mv[i].first, p|(1<<i));
    }
  }
  //  printf("right=%d n=%d end=%d p=%d r=%s\n", Right, N, end, p, r?"True":"False");
  return r;
}

int main() {
  int N;
  while (cin >> N) {
    if (N == 0) break;
    int M, left, right, dummy;
    cin >> M;
    cin >> dummy;
    cin >> left;
    cin >> right;
    cin >> dummy;
    mv.clear();
    for (int m = 0; m < M; ++m) {
      int l, r;
      cin >> l;
      cin >> r;
      mv.push_back(make_pair(l, r));
    }
    bool r = rb(right, N, left, 0);
    if (r) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  
  return 0;
}
