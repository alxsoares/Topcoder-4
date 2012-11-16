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


class PillarDivTwo {
public:
  double maximalLength(vector<int> height, int w);
};

double PillarDivTwo:: maximalLength(vector<int> height, int w) {
  int n = height.size();
  if (n == 1) return 0.0;
  double s = 0.0;
  int curr = 0.0, prev = (height[0] > height[1])?height[0]:1.0;
  for (int i = 1; i < n; i++) {
    curr = (height[i]+1.0 > prev*2.0)?height[i]:1.0;
    s += sqrt(pow(curr-prev, 2.0)+pow(w, 2.0));
    prev = curr;
  }
  return s;
}

int main() {
  PillarDivTwo p;
  //  int h[3] = {3, 3, 3};
  //  int h[5] = {100,2,100,2,100};
  int h[4] =  {2,1,1,2};
  vector<int> height(h, h+4);
  cout << p.maximalLength(height, 1.0) << endl;
  return 0;
}


