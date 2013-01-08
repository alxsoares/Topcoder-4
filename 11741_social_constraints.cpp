#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Constraint {
public:
  int a;
  int b;
  int c;
};

Constraint constraints[21];

int main() {
  while (true) {
    int N, M;
    cin >> N >> M;
    if (N == 0 and M == 0) break;

    for (int m = 0; m < M; ++m) {
      cin >> constraints[m].a 
	  >> constraints[m].b 
	  >> constraints[m].c;
    }
    vector<int> row(N);
    for (int i = 0; i < row.size(); i++)
      row[i] = i;

    int r = 0;

    do {
      bool add = true;
      for (int m = 0; m < M; ++m) {
	int d = fabs(row[constraints[m].a]-row[constraints[m].b]);
	if ((d < fabs(constraints[m].c) and constraints[m].c < 0) or (d > fabs(constraints[m].c) and constraints[m].c > 0)) {
	    add = false;
	    break;
	  }
	  }
	if (add) ++r;
      } while (next_permutation(row.begin(), row.end()));
      
      cout << r << endl;
    }
  return 0;
}
