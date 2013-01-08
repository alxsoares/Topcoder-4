#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
 
vector<int> pv;

int dp[21][21][1001];

void init(int P, int S) {
  for (int p = 1; p <= P; ++p) {
    for (int i = 0; i <= P; ++i) {
      for (int s = 0; s <= S; ++s) {
	if (i == 0 and pv[p] >= s)
	  dp[p][i][s] = 1;
	else if (i == 0 and pv[p] < s)
	  dp[p][i][s] = 0;
	else
	  dp[p][i][s] = -1;
      }
    }
  }
}


int F(int p, int i, int s) {
  if (s <= 0) return 0;
  if (dp[p][i][s] != -1) {
    //    printf("p=%d i=%i s=%d dp=%d\n", p, i, s, dp[p][i][s]);
    return dp[p][i][s];
  }

  
  int r1 = 0;
  if (p != i)
    r1 = F(p, i-1, s-pv[i]);
  int r2 = F(p, i-1, s);

  int r = r1 + r2;
    
  dp[p][i][s] = r;
  //  printf("p=%d i=%i s=%d r=%d\n", p, i, s, r);
  return r;
}

int main() {
  int TC;
  cin >> TC;
  

  for (int tc = 1; tc <= TC; ++tc) {
    pv.clear();
    int P;
    cin >> P;
    pv.push_back(0);
    for (int p = 1; p <= P; ++p) {
      int pn;
      cin >> pn;
      pv.push_back(pn);
    }
    
    int s = accumulate(pv.begin(), pv.end(), 0);
    
    init(P, s);

    for (int p = 1; p <= P; ++p) {
        
      cout << "party " << p 
	   << " has power index " << F(p, P, floor(s/2.0)+1) << endl;

    }
    cout << endl;
  }
  return 0;
}
