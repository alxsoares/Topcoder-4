#include <iostream>
#include <vector>

using namespace std;


const long long NMAX = 201;
const long long MMAX = 11;
const long long DMAX = 21;

long long dp[NMAX][MMAX][DMAX];


int main() {
  long long N=0, Q=0, S=0;

  while (true) {
    cin >> N >> Q;
    if (N == 0 and Q == 0) break;
    cout << "SET " << ++S << ":" << endl;
    vector<long long> numbers(N+1);
    for (long long i = 1; i <= N; ++i) {
      long long num=0;
      cin >> num;
      numbers[i] = num; 
    }
    for (long long q = 0; q < Q; ++q) {
      long long D=0, M=0;
      cin >> D >> M;

      for (long long i = 0; i <= N; ++i)
	  dp[i][0][0] = 1;


      for (long long j = 1; j <= M; ++j) {
	for (long long i = j; i <= N; ++i) {
	  for (long long k = 0; k < D; ++k) {
	    long long a = dp[i-1][j][k];
	    long long b = 0;
	    //	    cout << "A i=" << i-1 << " j=" << j << " k=" << k << " is " << a << endl;
	    if (k >= numbers[i]%D) {
	      b = dp[i-1][j-1][(k-numbers[i]%D)%D];
	      //	      cout << "B i=" << i-1 << " j=" << j-1 << " k=" << (k-numbers[i]%D)%D << " is " << b << endl;
	    } else { 
	      b = dp[i-1][j-1][D+(k-numbers[i]%D)];
	      //	      cout << "C i=" << i-1 << " j=" << j-1 << " k=" << D+(k-numbers[i]%D) << " is " << b << endl;
	    }
	    
	    dp[i][j][k] = a + b;

	    //	    cout << "D i=" << i << " j=" << j << " k=" << k << " is " << dp[i][j][k] << endl;
	  }
	}
      }
      

      cout << "QUERY " << q+1 << ": " << dp[N][M][0] << endl;
    }
  }

  return 0;
}
