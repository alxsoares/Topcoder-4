#include <iostream>

using namespace std;

int qv[8];

int rb(int col, int nchanges, int rows, int diag, int diag2) {
  if (col == 8 and rows == 255) {
    return nchanges;
  }
  if (col == 8 and rows != 255) {
    return 8;
  }
  int rmin = 8;
  for (int i = 0; i < 8; ++i) {
    if (not (rows&(1<<i)) and not (diag&(1<<(col+i))) and not (diag2&(1<<(7-col+i)))) {
      int nn = nchanges;
      if (qv[col] != i+1) ++nn;
      int r = rb(col+1, nn, rows|(1<<i), diag|(1<<(col+i)), diag2|(1<<(7-col+i)));
      if (r < rmin) rmin = r;
    }
  }
  return rmin;
}

int main() {
  int q1, tc=0;
  while (cin >> q1) {
    ++tc;
    qv[0] = q1;
    for (int q = 1; q < 8; ++q)
      cin >> qv[q];
    cout << "Case " << tc << ": " << rb(0, 0, 0, 0, 0) << endl;
  }
  return 0;
}
