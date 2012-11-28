#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100;
const int MAXK = 100;
const int MOD = 1000000;

int dp[MAXN+1][MAXK+1];


int F(int N, int K) {
  int n = 0;

  if (dp[N][K] != -1)
    return dp[N][K];
  
  for (size_t i = 0; i <= N; ++i) {
    n += F(i, K-1);
    n %= MOD;
  }
  //  cout << "N=" << N << " K=" << K << " n=" << n << endl;
  dp[N][K] = n;
  return n;
}

void init(int N, int K) {
  for (size_t i = 0; i <= N; ++i)
    for (size_t j = 1; j <= K; ++j) {
      if (j == 1)
	dp[i][j] = j;
      else
	dp[i][j] = -1;
    }
}

int main() {
  init(100, 100);
  F(100, 100);
  while (true) {
    int N, K;
    cin >> N;
    cin >> K;
    if (N == 0 and K == 0) break;
    cout << F(N, K) << endl;
  }
  return 0;
}
