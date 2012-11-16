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



const long long P = 1000000007LL;
const long long inf = 800000000000000000LL;

const int maxN = 78;

struct matrix {
  long long a[maxN][maxN];
};


matrix operator * (matrix A, matrix B) {
  matrix C;
  for (int i = 0; i < maxN; i++) {
    for (int j = 0; j < maxN; j++) {
      C.a[i][j] = 0;
      for (int k = 0; k < maxN; k++) {
	C.a[i][j] += A.a[i][k] * B.a[k][j];
	if (C.a[i][j] >= inf)
	  C.a[i][j] %= P;
      }
    }
  }
  for (int i = 0; i < maxN; i++) {
    for (int j = 0; j < maxN; j++) {
      C.a[i][j] %= P;
    }
  }
  return C;
}

matrix operator + (matrix A, matrix B) {
  matrix C;
  for (int i = 0; i < maxN; i++) {
    for (int j = 0; j < maxN; j++) {
      C.a[i][j] = A.a[i][j] + B.a[i][j];
      C.a[i][j] %= P;
    }
  }
  return C;
}

class ConversionMachine {
public:
  int countAll(string word1, string word2, vector <int> costs, int maxCost);
};

int n;
int d[maxN][maxN];

void arrange() {
  int m = 0; 
  for (int i = 0; i <= n; i++) {
    for (int j = 0; i+j <= n; j++) {
      d[i][j] = m;
      m++;
    }
  }
}

matrix A;

void generate() {
  memset(A.a,0,sizeof(A.a));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; i+j <= n; j++) {
      int k = n-i-j;
      if (i > 0)
	A.a[d[i][j]][d[i-1][j]] += i;
      if (j > 0)
	A.a[d[i][j]][d[i+1][j-1]] += j;
      if (k > 0)
	A.a[d[i][j]][d[i][j+1]] += k;
    }
  }
}

const int maxM = 31;
matrix powers[maxM], sums[maxM];

matrix init() {
  matrix res;
  for (int i = 0; i < maxN; i++) {
    for (int j = 0; j < maxN; j++) {
      res.a[i][j] = (i == j);
    }
  }
  return res;
}

matrix powmod(long long n) {
  matrix res = init();
  
  for (int i = 0; i < maxM; i++) {
    if (n & (1 << i)) {
      res = res * powers[i];
    }
  }
  return res;
}


matrix getGeom(long long n) {
  for (int i = maxM - 1; i >= 0; i--) {
    if (n & (1 << i)) {
      return sums[i];
    }
    if (n >= (1 << i)) {
      return sums[i] + powers[i] * getGeom(n-(1<<i));
    }
  }
}

void preCalc(matrix A) {
  powers[0] = A;
  for (int i = 1; i < maxM; i++) {
    powers[i] = powers[i-1] * powers[i-1];
  }
  sums[0] = init();
  for (int i = 1; i < maxM; i++) {
    sums[i] = sums[i-1] + powers[i-1] * sums[i-1];
  }
}


int ConversionMachine::countAll(string word1, string word2, 
				vector <int> costs, int maxCost) {
  long long need = 0;
  n = word1.size();
  arrange();
  
  int m1 = 0, m2 = 0;
  int total = 0;
  for (int i = 0; i < n; i++){
    if (word1[i] == 'a' && word2[i] == 'b') {
      need += costs[0];
      total += 1;
      m1++;
    }
    if (word1[i] == 'a' && word2[i] == 'c') {
      need += costs[0] + costs[1];
      total += 2;
      m2++;
    }
    if (word1[i] == 'b' && word2[i] == 'c') {
      need += costs[1];
      total += 1;
      m1++;
    }
    if (word1[i] == 'b' && word2[i] == 'a') {
      need += costs[1] + costs[2];
      total += 2;
      m2++;
    }
    if (word1[i] == 'c' && word2[i] == 'a') {
      need += costs[2];
      total += 1;
      m1++;
    }
    if (word1[i] == 'c' && word2[i] == 'b') {
      need += costs[0] + costs[2];
      total += 2;
      m2++;
    }
  }

  generate();
  preCalc(A);
  
  if (need > (long long)maxCost) {
    return 0;
  }
  long long c = (long long)costs[0] + (long long) costs[1] + (long long) costs[2];
  long long moves = ((long long)(maxCost - need)) / c;

  matrix start = powmod(total);
  matrix B = powmod(3);
  preCalc(B);
  matrix res = start * getGeom(moves + 1);
  
  return res.a[d[m1][m2]][0];
}


int main() {
  ConversionMachine cm;
  vector <int> costs;
  costs.push_back(1);
  costs.push_back(10);
  costs.push_back(100);
  cout << cm.countAll("aa", "cc", costs, 1787) << endl;
  return 0;
}
