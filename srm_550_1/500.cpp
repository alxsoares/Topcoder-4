#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
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

class CheckerExpansion {
public:
  vector<string> resultAfter(long long t, long long x0, 
			     long long y0, int w, int h);
};


vector <string> CheckerExpansion::resultAfter(long long t, long long x0, 
					      long long y0, int wi, int hi) {
  int xc = x0/128;
  int xr = x0%128;
  int yc = y0/64;
  int yr = y0%64;

  t = t - xc - yc;
  x0 = xr;
  y0 = yr;

  const int w = 130, h = 65;
  int grid[y0+h][x0+w];
  long long turn;
  memset(grid,-1,sizeof(grid));
  grid[1][2] = 0;
  
  FOR(k,1,t) {
    FOR(y,1,h) {
      FOR(x,2,w) {
	turn = k%2;
	if (grid[y-1][x-1] == 1-turn && grid[y][x-2] == -1)
	  grid[y][x] = turn;
	if (grid[y][x-2] == 1-turn && grid[y-1][x-1] == -1)
	  grid[y][x] = turn;
      }
    }
  }

  vector<string> result;
  FORI(y,y0+hi,y0+1) {
    string row = "";
    FOR(x,x0+2,x0+wi+2) {
      if (grid[y][x] == 0) row += "A";
      else if (grid[y][x] == 1) row += "B";
      else row += ".";
    }
    result.push_back(row);
  }
  return result;
}


/*


./a.out 1024 1525 512 20 2

./a.out 53 85 6 5 14

./a.out 1 0 0 4 4

./a.out 5 4 1 3 4



 */
