#include <iostream>

using namespace std;

long long dp[5][5][5][5][50][10];

const long long MOD = 1234567891;

class TheBrickTowerHardDivTwo {
public:
  int CC;
  int KK;
  int HH;
  int find(int C, int K, int H);
  void init();
  long long F(int a1, int a2, int a3, int a4, int H, int K);
};

void TheBrickTowerHardDivTwo::init() {
  for (size_t i1 = 0; i1 <= CC; ++i1)
    for (size_t i2 = 0; i2 <= CC; ++i2)
      for (size_t i3 = 0; i3 <= CC; ++i3)
	for (size_t i4 = 0; i4 <= CC; ++i4)
	  for (size_t h = 0; h <= HH; ++h)
	    for (size_t k = 0; k <= KK; ++k)
	      dp[i1][i2][i3][i4][h][k] = -1;

  
  for (size_t i1 = 1; i1 <= CC; ++i1)
    for (size_t i2 = 1; i2 <= CC; ++i2)
      for (size_t i3 = 1; i3 <= CC; ++i3)
	for (size_t i4 = 1; i4 <= CC; ++i4)
	  for (size_t k = 0; k <= KK; ++k) {
	    int n = 0;
	    if (i1 == i2) n++;
	    if (i2 == i3) n++;
	    if (i3 == i4) n++;
	    if (i4 == i1) n++;

	    if (n <= k)
	      dp[i1][i2][i3][i4][1][k] = 1;
	    else 
	      dp[i1][i2][i3][i4][1][k] = 0;
	  }
}

int calc(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
  int s = 0;
  if (a1 == a5) s++;
  if (a2 == a6) s++;
  if (a3 == a7) s++;
  if (a4 == a8) s++;
  return s;
}

long long TheBrickTowerHardDivTwo::F(int a1, int a2, int a3, int a4, int H, int K) {
  //  if (a1==0 or a2==0 or a3==0 or a4==0) cout << "ceros" << endl;
  //  else cout << "no ceros" << endl;
  if (dp[a1][a2][a3][a4][H][K] != -1) {
    /*    cout << " a1=" << a1
	 << " a2=" << a2
	 << " a3=" << a3
	 << " a4=" << a4
	 << " H=" << H
	 << " K=" << K
	 << " in dp = "
	 << dp[a1][a2][a3][a4][H][K]
	 << endl;*/
    return dp[a1][a2][a3][a4][H][K];
  }
  long long rmax = 0;
  for (size_t i1 = 1; i1 <= CC; ++i1)
    for (size_t i2 = 1; i2 <= CC; ++i2)
      for (size_t i3 = 1; i3 <= CC; ++i3)
	for (size_t i4 = 1; i4 <= CC; ++i4) {
	  int s = calc(a1,a2,a3,a4,i1,i2,i3,i4);
	  if (a1 == a2) ++s;
	  if (a2 == a3) ++s;
	  if (a3 == a4) ++s;
	  if (a4 == a1) ++s;

	  if (K >= s) {
	    rmax += F(i1,i2,i3,i4,H-1,K-s);
	    rmax %= MOD;
	  }
	}
  dp[a1][a2][a3][a4][H][K] = rmax;
  /*      cout << " a1=" << a1
	 << " a2=" << a2
	 << " a3=" << a3
	 << " a4=" << a4
	 << " H=" << H
	 << " K=" << K
	 << " calculated = "
	 << rmax
	 << endl;
  */  
  return rmax;
}


int TheBrickTowerHardDivTwo::find(int C, int K, int H) {
  CC = C;
  KK = K;
  HH = H;
  init();
  long long nmax = 0;
  for (size_t i1 = 1; i1 <= C; ++i1)
    for (size_t i2 = 1; i2 <= C; ++i2)
      for (size_t i3 = 1; i3 <= C; ++i3)
	for (size_t i4 = 1; i4 <= C; ++i4)
	  for (size_t h = 0; h <= H; ++h) {
	    nmax += F(i1,i2,i3,i4,h,K);
	    nmax %= MOD;
	  }
  
  return nmax%MOD;
}

int main() {
  TheBrickTowerHardDivTwo o;
  //int C=2, K=0, H=2;
  //int C=1, K=7, H=19;
  //  int C=2, K=3, H=1;
  int C=4, K=7, H=47; // mal
      cout << o.find(C, K, H) << endl;
  return 0;
}
