#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iostram>
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
#define MSG(a) cout << #a << " = " << a << endl;
#define ITOA(a) char c[500]; sprintf(c,"%d",a); string s(c);
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())
#define tr(container, it) for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define CLOCK cout << "CLOCK " << (double)clock()/CLOCKS_PER_SEC << endl
#define DMSG(a) FOR(i,0,(a).size()) { FOR(j,0,(a)[i].size()) cout << (a)[i][j] << " "; cout << endl; }

class RotatingBot {
public:
  int minArea(vector<int>);
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int RotatingBot::minArea(vector<int> moves) {
  int maxx = 0;
  int minx = 0;
  int maxy = 0;
  int miny = 0;
  int x = 0, y = 0;
  FOR(i, 0, moves.end()) {
    x += dx[i%4] * moves[i];
    y += dy[i%4] * moves[i];
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
  }

  int ans = (maxx-minx+1)*(maxy-miny+1);

  x = 0, y = 0;
  if (minx < 0) maxx -= minx, x -= minx, minx = 0;
  if (miny < 0) maxy -= miny, y -= miny, miny = 0;

  int G[200][200];
  memset(G,0,sizeof G);
  G[x][y] = 1;

  FOR(i,0,moves.size()) {
    FOR(k,0,moves[i]) {
      x += dx[i%4];
      y += dy[i%4];
      if (G[x][y]) return -1;
      G[x][y] = 1;
    }
    if (i != moves.size()-1)
      if (x + dx[i%4] >= 0 && x + dx[i%4] <= maxx && y + dy[i%4] >= 0 && y + dy[i%4] <= maxy && G[x+dx[i%4]][y+dy[i%4]])
	return -1;
  }
  
  return ans;
}
