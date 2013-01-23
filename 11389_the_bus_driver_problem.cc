#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int N, D, R;

  while (true) {
    cin >> N >> D >> R;
    if (N == 0 && D == 0 && R == 0) break;
    vector<int> morning_routes;
    vector<int> evening_routes;
  
    for (int n = 0; n < N; ++n) {
      int mr; cin >> mr;
      morning_routes.push_back(mr);
    }
    for (int n = 0; n < N; ++n) {
      int er; cin >> er;
      evening_routes.push_back(er);
    }
    sort(morning_routes.begin(), morning_routes.end());
    sort(evening_routes.begin(), evening_routes.end());
    reverse(evening_routes.begin(), evening_routes.end());

    long long s = 0;
    for (int n = 0; n < N; ++n) {
      long long ss = morning_routes[n] + evening_routes[n];
      if (D < ss) s += ss - D;
    }
    cout << s * R<< endl;
  }
  
  return 0;
}
