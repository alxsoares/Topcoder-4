#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <bitset>

using namespace std;

const int MAX = 12;
const int DMAX = 1000;

typedef pair<int, int> xy;

int dp[10][1024];

int m[MAX][MAX];

void calcDistances(vector<xy> &nodes_coord) {
  for (int i = 0; i < nodes_coord.size(); i++) {
    for (int j = 0; j < nodes_coord.size(); j++) {
      m[i+1][j+1] = fabs(nodes_coord[i].first-nodes_coord[j].first) 
	+ fabs(nodes_coord[i].second-nodes_coord[j].second);
      /*
                    cout << " i=" << i+1
	   << " j=" << j+1
	   << " m=" << m[i+1][j+1] 
	   << endl;
      */
    }
  }
}

void init(int nn) {
  for (int i = 0; i < nn; ++i) {
    for (int j = 0; j <= pow(2, nn)-1; ++j) {
      if (j == (1<<i))
	dp[i][j] = m[1][i+2];
      else
	dp[i][j] = -1;
    }
  }
}


int F(int i, int nodes, int nn) {
  if (dp[i][nodes] != -1)
    return dp[i][nodes];
  int nnodes = nodes&~(1<<i);
  int rmin = DMAX;
  for (int j = 0; j < nn; ++j) {
    if (nnodes&(1<<j)) {
      int r = F(j, nnodes, nn) + m[j+2][i+2];
      if (r < rmin) rmin = r;
    }
  }
  dp[i][nodes] = rmin;
  return rmin;
}

int main() {
  int tc = 0;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    int xsize, ysize, x0, y0, nn;
    vector<xy> nodes_coord;
    cin >> xsize;
    cin >> ysize;
    cin >> x0;
    cin >> y0;
    cin >> nn;
    nodes_coord.push_back(make_pair(x0, y0));
    memset(m, 0, sizeof(m));
    for (int j = 0; j < nn; ++j) {
      int x, y;
      cin >> x;
      cin >> y;
      nodes_coord.push_back(make_pair(x, y));
    }
    calcDistances(nodes_coord);
    int rmin = DMAX;
    init(nn);
    for (int i = 0; i < nn; ++i) {
      int nodes = pow(2, nn)-1;
      int r = F(i, nodes, nn) + m[1][i+2];
      if (r < rmin) rmin = r;
    }

    cout << "The shortest path has length " << ((rmin==DMAX)?0:rmin) << endl;
  }

  return 0;
}
