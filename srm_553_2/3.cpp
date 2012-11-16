#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
  int sum[55][55][55][55];
  int F[55][55][55][55];

class SafeRemoval {
public:
  SafeRemoval();
  int removeThem(vector<int> seq, int k);
  int f(int a, int b, int c, int d);
  int S(int a, int b, int c, int d);
  vector<vector<int> > ordered;
  int n0;
  int n1;
  int n2;
  int n3;
  int K;
};

SafeRemoval::SafeRemoval() {

  for (int i = 0; i < 55; ++i)
    for (int j = 0; j < 55; ++j)
      for (int k = 0; k < 55; ++k)
	for (int l = 0; l < 55; ++l)
	  sum[i][j][k][l] = -1;

  for (int i = 0; i < 55; ++i)
    for (int j = 0; j < 55; ++j)
      for (int k = 0; k < 55; ++k)
	for (int l = 0; l < 55; ++l)
	  F[i][j][k][l] = -2;

}

int SafeRemoval::removeThem(vector<int> seq, int k) {
  int n = seq.size();
  K = k;
  vector<int> s0;
  vector<int> s1;
  vector<int> s2;
  vector<int> s3;


  for (int i = 0; i < n; ++i) {
    if (seq[i] % 4 == 0) s0.push_back(seq[i]);
    else if (seq[i] % 4 == 1) s1.push_back(seq[i]);
    else if (seq[i] % 4 == 2) s2.push_back(seq[i]);
    else  s3.push_back(seq[i]);
  }
  sort(s0.begin(), s0.end());
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  sort(s3.begin(), s3.end());
  n0 = s0.size();
  n1 = s1.size();
  n2 = s2.size();
  n3 = s3.size();
  ordered.push_back(s0);
  ordered.push_back(s1);
  ordered.push_back(s2);
  ordered.push_back(s3);
  return f(0, 0, 0, 0);
}

int SafeRemoval::S(int i0, int i1, int i2, int i3) {
  if (i0 > 0 and sum[i0-1][i1][i2][i3]) return sum[i0-1][i1][i2][i3]+ordered[0][i0];
  if (i1 > 0 and sum[i0][i1-1][i2][i3]) return sum[i0][i1-1][i2][i3]+ordered[1][i1];
  if (i2 > 0 and sum[i0][i1][i2-1][i3]) return sum[i0][i1][i2-1][i3]+ordered[2][i2];
  if (i3 > 0 and sum[i0][i1][i2][i3-1]) return sum[i0][i1][i2][i3-1]+ordered[3][i3];
  int s0 = 0;

  for (int i = 0; i < i0; ++i) {
    s0 += ordered[0][i];
  }
  for (int i = 0; i < i0; ++i) {
    s0 += ordered[0][i];
  }
  for (int i = 0; i < i0; ++i) {
    s0 += ordered[0][i];
  }
  for (int i = 0; i < i0; ++i) {
    s0 += ordered[0][i];
  }
  
  return s0;
}

int SafeRemoval::f(int i0, int i1, int i2, int i3) {
  if (F[i0][i1][i2][i3] != -2) return F[i0][i1][i2][i3];
  int r = -2;
  int s = sum[i0][i1][i2][i3];
  if (s == -1) {
    s = S(i0, i1, i2, i3);
    sum[i0][i1][i2][i3] = s;
  }
  int mod = s%4;
  if (i0 + i1 + i2 + i3 == K) {
    if (mod != 0)
      r = s;
    else
      r = -1;
  } else {
    if (i0 < n0)
      s = f(i0+1, i1, i2, i3);
    if (i1 < n1)
      s = max(s, f(i0, i1+1, i2, i3));
    if (i2 < n2)
      s = max(s, f(i0, i1, i2+1, i3));
    if (i3 < n3)
      s = max(s, f(i0, i1, i2, i3+1));
    r = s;
  }

  return r;
}

int main() {

  SafeRemoval o;
    vector<int> seq = {3, 8, 4};
    int k = 1;

  //  vector<int> seq = {1,1,1,1,1,1};
  //  int k = 3;
  cout << o.removeThem(seq, k) << endl;
  return 0;
}
