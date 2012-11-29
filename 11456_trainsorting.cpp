#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int dp_inc[2001];
int dp_dec[2001];

int main() {

  int tc = 0;
  cin >> tc;

  for (int c = 0; c < tc; ++c) {

    memset(dp_inc, 0, sizeof(dp_inc));
    memset(dp_dec, 0, sizeof(dp_dec));
    int n = 0;
    cin >> n;
    vector<int> cars;
    for (int i = 0; i < n; ++i) {
      int num;
      cin >> num;
      cars.push_back(num);
    }

    reverse(cars.begin(), cars.end());

    for (int i = 0; i < n; ++i) {
      int max_inc = 0;
      int idx_inc = 0;
      for (int j = 0; j <= i; ++j) {
	if (cars[i] > cars[j])
	  if (dp_inc[j] > max_inc) {
	    max_inc = dp_inc[j]; 
	    idx_inc = j;
	  }
      }
      dp_inc[i] = max_inc + 1;
    }
    for (int i = 0; i < n; ++i) {
      int max_dec = 0;
      int idx_dec = 0;
      for (int j = 0; j <= i ; ++j) {
	if (cars[i] < cars[j])
	  if (dp_dec[j] > max_dec) {
	    max_dec = dp_dec[j]; 
	    idx_dec = j;
	  }
      }  
      dp_dec[i] = max_dec + 1;
    }
    
    
    int max = 0;
    for (int i = 0; i < n; ++i) {
      if (dp_inc[i] + dp_dec[i] - 1 > max)
	max = dp_inc[i] + dp_dec[i] - 1;
    }

    cout << max << endl;
  }
  
  return 0;
}
