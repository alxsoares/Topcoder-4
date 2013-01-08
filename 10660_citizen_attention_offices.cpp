#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
#include <limits>
#include <numeric>

using namespace std;

int population[6][6];
int distances[26][26];

void calc_distances() {
  for (int x1 = 0; x1 < 5; ++x1) {
    for (int y1 = 0; y1 < 5; ++y1) {
      for (int x2 = 0; x2 < 5; ++x2) {
	for (int y2 = 0; y2 < 5; ++y2) {
	  int n = (fabs(x1-x2)+fabs(y1-y2));
	  distances[x1*5+y1][x2*5+y2] = n;
	  // 	  printf("distances[%d][%d]=%d\n", 
	  //	 x1, x2, n);
	}
      }
    }
  }
}

int main() {
  int TC;
  cin >> TC;
  calc_distances();

  for (int tc = 1; tc <= TC; ++tc) {
    memset(population, 0, sizeof(population));
    int P;
    cin >> P;
    for (int k = 1; k <= P; ++k) {
      int x, y, p;
      cin >> x >> y >> p;
      population[x][y] = p;
    }
    int ssmin = numeric_limits<int>::max();
    int x1min, x2min, x3min, x4min, x5min;
    for (int i1 = 0; i1 < 25; ++i1) {
      for (int i2 = i1+1; i2 < 25; ++i2) {
	for (int i3 = i2+1; i3 < 25; ++i3) {
	  for (int i4 = i3+1; i4 < 25; ++i4) {
	    for (int i5 = i4+1; i5 < 25; ++i5) {
	      vector <int> s(25, numeric_limits<int>::max());
	      int ss = 0;
	      for (int x = 0; x < 25; ++x) {
		int p = population[x/5][x%5];
		s[x] = min(distances[x][i1]*p, s[x]);
		s[x] = min(distances[x][i2]*p, s[x]);
		s[x] = min(distances[x][i3]*p, s[x]);
		s[x] = min(distances[x][i4]*p, s[x]);
		s[x] = min(distances[x][i5]*p, s[x]);
		ss += s[x];
	      }
	      if (ss < ssmin) { 
		ssmin = ss;
		x1min = i1;
		x2min = i2;
		x3min = i3;
		x4min = i4;
		x5min = i5;
	      }
	    }
	  }
	}
      }
    }
    cout << x1min << " ";
    cout << x2min << " ";
    cout << x3min << " ";
    cout << x4min << " ";
    cout << x5min << endl;
  }

  return 0;
}
