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

class KingdomAndTrees {
public:
  int minLevel(vector <int> h) {
    int size = h.size();
    int max = 0; 
    for (int i = 1; i < size; i++) {
      if (h[i-1] >= h[i]) {
	double diff = h[i-1]-h[i];
	double lps = (i-2>=0)?h[i-1]-h[i-2]-1:h[i-1]-1;
	double pei = diff-min(lps, diff/2)+1;
	h[i] += pei;
	h[i-1] -= (diff-pei)+1;
	if (pei > max) max = pei;
      }
    }
    return max;
  };
};

int main() {
  KingdomAndTrees k;
  //  int a[] = {1,1,1,1,1};
  //  int a[] = {548, 47, 58, 250, 2012};
  int a[] = {5, 8};
  vector<int> v(a, a+2);
  cout << k.minLevel(v) << endl;
  return 0;
}
