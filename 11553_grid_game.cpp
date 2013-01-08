#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int m[8][8];

int main() {
  int TC;
  cin >> TC;
  
  for (int tc = 1; tc <= TC; ++tc) {
    int N;
    cin >> N;
    

    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
	m[i][j] = 1000;
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
	cin >> m[i][j];
      }
    }
    int states = 0;
    int smin = 8000;
    for (int i1 = 0; i1 < 8; ++i1) {
    for (int i2 = 0; i2 < 8; ++i2) {
      if (i2 != i1)
    for (int i3 = 0; i3 < 8; ++i3) {
      if (i3 != i1)
      if (i3 != i2)
    for (int i4 = 0; i4 < 8; ++i4) {
      if (i4 != i1)
      if (i4 != i2)
      if (i4 != i3)
    for (int i5 = 0; i5 < 8; ++i5) {
      if (i5 != i1)
      if (i5 != i2)
      if (i5 != i3)
      if (i5 != i4)
    for (int i6 = 0; i6 < 8; ++i6) {
      if (i6 != i1)
      if (i6 != i2)
      if (i6 != i3)
      if (i6 != i4)
      if (i6 != i5)
    for (int i7 = 0; i7 < 8; ++i7) {
      if (i7 != i1)
      if (i7 != i2)
      if (i7 != i3)
      if (i7 != i4)
      if (i7 != i5)
      if (i7 != i6)
    for (int i8 = 0; i8 < 8; ++i8) {
      if (i8 != i1)
      if (i8 != i2)
      if (i8 != i3)
      if (i8 != i4)
      if (i8 != i5)
	if (i8 != i6)
	  if (i8 != i7) {
	  int s = m[0][i1]
	    + m[1][i2]
	    + m[2][i3]
	    + m[3][i4]
	    + m[4][i5]
	    + m[5][i6]
	    + m[6][i7]
	    + m[7][i8];
	  if (s < smin) smin = s;
	  ++states;
	}
    }
    }
    }
    }
    }
    }
    }
    }
    
    cout << smin-1000*(8-N) << endl;
  }      
    
  return 0;
}
