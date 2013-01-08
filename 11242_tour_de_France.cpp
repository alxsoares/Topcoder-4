#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;


int main() {
  int FC, RC;
  //    cout << setprecision(3);
  while (true) {
    cin >> FC;
    if (not (cin >> RC)) break;

    vector<int> fv;
    vector<int> rv;
    for (int fc = 1; fc <= FC; ++fc) {
      int fn;
      cin >> fn;
      fv.push_back(fn);
    }
    for (int rc = 1; rc <= RC; ++rc) {
      int rn;
      cin >> rn;
      rv.push_back(rn);
    }
    vector<double> dv;
    for (int i = 0; i < fv.size(); ++i) {
      for (int j = 0; j < rv.size(); ++j) {
	double d = (double)fv[i]/rv[j];
	dv.push_back(d);
      }
    }
    sort(dv.begin(), dv.end());
    double dmax = 0.0;
    for (int i = 1; i < dv.size(); ++i) {
      double d = (double)dv[i]/dv[i-1];
      if (d > dmax) dmax = d;
    }
    //       cout << dmax << endl;
    printf("%.2f\n", floor(dmax*100+0.5)/100.0);
  }

  return 0;
}
