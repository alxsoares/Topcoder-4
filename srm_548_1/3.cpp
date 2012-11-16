#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <ctime>
#include <complex>

using namespace std;

const double EPS = 1e-10;
const double PI = 3.14159265358979323846264338328;

#define PB push_back
#define FOR(a,start,end) for(long long a = (start); a < (end); a++)
#define FORI(a,start,end) for(long long a = (start); a >= (end); a--)
#define MSG(a) cout << #a << " = " << a << endl;
#define ITOA(a) char c[500]; sprintf(c,"%d",a); string s(c);
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())
#define tr(container, it) for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define CLOCK cout << "CLOCK " << (double)clock()/CLOCKS_PER_SEC << endl
#define DMSG(a) FOR(i,0,(a).size()) { FOR(j,0,(a)[i].size()) cout << (a)[i][j] << " "; cout << endl; }

const long long MOD = 1000000007;

class KingdomAndCities {
public:
  int howMany(int N, int M, int K) {
    int choices[2500][2500] = {0};
    int dp[51][51] = {0};

    // some trivial cases
    
    if (K < N-1 || K > N*(N-1)/2) {
      return 0;
    }
    if (N <= 2) {
      return (M == 0)?1:0;
    }

    // calculating combinatorials
    
    for (int i = 0; i < 2500; ++i) {
      choices[i][0] = 1;
      choices[i][i] = 1;
      for (int j = 0; j < 2500; ++j){
	choices[i][j] = (choices[i-1][j-1] + choices[i-1][j]) % MOD;
      }
    }
    
  };
};
