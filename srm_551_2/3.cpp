#include <iostream>
#include <cstring>

using namespace std;

const long long MOD = 1000000007;

long long dp[3][3][50][50][50];

class ColorfulCupcakesDivTwo {
public:
  int countArrangements(string cupcakes);
};


int F(char _begin, char _end, int a, int b, int c) {
  int begin = _begin-65;
  int end = _end-65;


  if (dp[begin][end][a][b][c] > 0) {
    return dp[begin][end][a][b][c];
  }

  if (dp[end][begin][a][b][c] > 0) {
    return dp[end][begin][a][b][c];
  }

  if (a+b+c <= 1){ 
    return 0;
  }


  long long r = 0;
  if (_begin == 'A' and _end == 'A') {
    if (b >= 2)
      r += F('B', 'B', a, b-2, c);
    if (c >= 2)
      r += F('C', 'C', a, b, c-2);
    if (b >= 1 and c >= 1)
      r += F('B', 'C', a, b-1, c-1) * 2;
  }
  if (_begin == 'B' and _end == 'B') {
    if (a >= 2)
      r += F('A', 'A', a-2, b, c);
    if (c >= 2)
      r += F('C', 'C', a, b, c-2);
    if (a >= 1 and c >= 1)
      r += F('A', 'C', a-1, b, c-1) * 2;
  }
  if (_begin == 'C' and _end == 'C') {
    if (b >= 2)
      r += F('B', 'B', a, b-2, c);
    if (a >= 2)
      r += F('A', 'A', a-2, b, c);
    if (a >= 1 and b >= 1)
      r += F('A', 'B', a-1, b-1, c) * 2;
  }
  if ((_begin == 'A' and _end == 'B') 
      or (_begin == 'B' and _end == 'A')) {
    if (a >= 1 and b >= 1)
      r += F('B', 'A', a-1, b-1, c);
    if (c >= 1 and b >= 1)
      r += F('B', 'C', a, b-1, c-1);
    if (a >= 1 and c >= 1)
      r += F('C', 'A', a-1, b, c-1);
    if (c >= 2)
      r += F('C', 'C', a, b, c-2);
  }
  if ((_begin == 'A' and _end == 'C') 
      or (_begin == 'C' and _end == 'A')) {
    if (a >= 1 and c >= 1)
      r += F('C', 'A', a-1, b, c-1);
    if (c >= 1 and b >= 1)
      r += F('C', 'B', a, b-1, c-1);
    if (a >= 1 and b >= 1)
      r += F('B', 'A', a-1, b-1, c);
    if (b >= 2)
      r += F('B', 'B', a, b-2, c);
  }
  if ((_begin == 'C' and _end == 'B') 
      or (_begin == 'B' and _end == 'C')) {
    if (a >= 2)
      r += F('A', 'A', a-2, b, c);
    if (a >= 1 and c >= 1)
      r += F('A', 'C', a-1, b, c-1);
    if (b >= 1 and a >= 1)
      r += F('B', 'A', a-1, b-1, c);
    if (b >= 1 and c >= 1)
      r += F('B', 'C', a, b-1, c-1)%MOD;
  }
  dp[begin][end][a][b][c] = r;
  
  return r;
}


int ColorfulCupcakesDivTwo::countArrangements(string cupcakes) {
  int a = 0, b = 0, c = 0;
  memset(dp, 0, sizeof(dp));
  int n = cupcakes.size();

  // counting A's, B's and C's
  for (int i = 0; i < n; ++i) {
    if (cupcakes[i] == 'A') ++a;
    if (cupcakes[i] == 'B') ++b;
    if (cupcakes[i] == 'C') ++c;
  }


  // base cases
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i != j)
	dp[i][j][0][0][0] = 1;
    }
  }

  dp[0][0][0][1][0] = 1;
  dp[0][0][0][0][1] = 1;

  dp[1][1][1][0][0] = 1;
  dp[1][1][0][0][1] = 1;

  dp[2][2][1][0][0] = 1;
  dp[2][2][0][1][0] = 1;

  dp[0][1][0][0][1] = 1;
  dp[1][0][0][0][1] = 1;

  dp[0][2][0][1][0] = 1;
  dp[2][0][0][1][0] = 1;

  dp[2][1][1][0][0] = 1;
  dp[1][2][1][0][0] = 1;

  // recursive cases

  long long result = 0;
  if (a > 0 and b > 0)
    result += (F('A', 'B', a-1, b-1, c) * 2)%MOD;

  if (a > 0 and c > 0) {
    result += (F('A', 'C', a-1, b, c-1) * 2)%MOD;
    result %=MOD;
  }

  if (b > 0 and c > 0) {
    result += (F('B', 'C', a, b-1, c-1) * 2)%MOD;
    result %=MOD;
  }


  return result;
  
}



int main() {
  ColorfulCupcakesDivTwo cc;
  //string cupcakes = "AAABBBCCC";
  //string cupcakes = "ABABA";
  //    string cupcakes = "ABC";
  //  string cupcakes = "ABABABABABABABABABABABABABABABABABABABABABABABABAB";
      string cupcakes = "BCBABBACBABABCCCCCAABBAACBBBBCBCAAA";
  cout << cc.countArrangements(cupcakes) << endl;
  return 0;
};
