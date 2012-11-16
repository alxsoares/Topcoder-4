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

class KleofasTail {

public:
  long long countGoodSecuences(long long K, long long A, long long B);
};


string decToBin(long long n) {
  if (n == 0) return "0";
  if (n == 1) return "1";
  if (n % 2 == 0) return decToBin(n/2) + "0";
  if (n % 2 == 1) return decToBin(n/2) + "1";
  return "";
}

long long firstOdd(long long n) {
  if (n == 0) return 0;
  while (n % 2 == 0) n >>= 1;
  return n;
}

int calcSlice(int k, int a, int b) {
  if (a >= k) return a-k;
  if (b >= k) return b-k;
  return -1;
}

long long calcInter(long long A, long long B, long long first, long long end) {
  long long nmax = max(A, first);
  long long nmin = min(B, end);
  return nmin-nmax+1;
}

long long calcFirst(long long k, long long A, long long B) {
  int slice = 0;
  while ((k<<slice)+pow(2.0, (int)slice)-1<A) {slice++;}
  if ((k<<slice) <= B) return slice;
  else return -1;
}


long long KleofasTail::countGoodSecuences(long long K, long long A, 
					  long long B) {
  if (A > B) return 0LL;
  long long k_odd = firstOdd(K);
  int slice = calcFirst(k_odd, A, B);
  if (slice == -1) return 0LL;
  long long first = k_odd << slice;
  long long last =  first + (long long)pow(2.0, slice) - 1;
  long long inter = min(last, B)-max(first, A)+1;
  return inter + countGoodSecuences(K, max(first, A)+inter, B); 
}
 
