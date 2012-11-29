#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int tc = 0;
  cin >> tc;
  for (int k = 1; k <= tc; ++k) {
    int n = 0, v = 0;

    cin >> n;

    vector<int> h(n, 0);
    vector<int> rh(n, 0);
    vector<int> w(n, 0);
    vector<int> rw(n, 0);
    vector<int> inc(n, 0);
    vector<int> dec(n, 0);

    for (int j = 0; j < n; ++j) {
      cin >> v;
      h[j] = v;
    }
    for (int j = 0; j < n; ++j) {
      cin >> v;
      w[j] = v;
    }

    
    vector<int> sel_inc(n, 0);

    for (int i = 0; i < n; ++i) {
      int max = 0;
      for (int j = 0; j <= i; ++j) {
	if (h[i] > h[j]) 
	  if (max < inc[j]) {
	    max = inc[j];
	    sel_inc[i] = j;
	  }
      }
      inc[i] = max + w[i];
    }

    rh = h;
    reverse(rh.begin(), rh.end());
    rw = w;
    reverse(rw.begin(), rw.end());
    
    vector<int> sel_dec(n, 0);

    for (int i = 0; i < n; ++i) {
      int max = 0;
      for (int j = 0; j <= i; ++j) {
	if (rh[i] > rh[j]) 
	  if (max < dec[j]) {
	    max = dec[j];
	    sel_dec[i] = j;
	  }
      }
      dec[i] = max + rw[i];
    }

    int max_inc = 0;
    int sinc = 0;
    for (int i = 0; i < n; ++i) {
      if (inc[i] > max_inc) {
	max_inc = inc[i];
	sinc = i;
      }
    }
    int max_dec = 0;
    int sdec = 0;
    for (int i = 0; i < n; ++i) {
      if (dec[i] > max_dec) {
	max_dec = dec[i];
	sdec = i;
      }
    }

    if (max_inc >= max_dec)
      cout << "Case " << k << ". Increasing (" << max_inc << "). Decreasing (" << max_dec << ")." << endl;
    else
      cout << "Case " << k << ". Decreasing (" << max_dec << "). Increasing (" << max_inc << ")." << endl;
    
  }
  return 0;
}
