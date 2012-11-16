#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

class ColorfulChocolates {

public:
  int maximumSpread(string chocolates, int maxSwaps);
};


int ColorfulChocolates::maximumSpread(string chocolates, int maxSwaps) {
  set<char> colors(chocolates.begin(), chocolates.end());
  set<char> ::const_iterator c;
  int n = chocolates.size();
  int maxSpread = 0;
  for (c = colors.begin(); c != colors.end(); ++c) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
	if (chocolates[i] == *c) {
	  int spread = 0, cost = 0, k = i, l = j;
	  while (k < n) {
	    while (chocolates[k] != *c and k < n-1) ++k;
	    if (chocolates[k] != *c) break;
	    cost += fabs(k-l);
	    if (cost > maxSwaps) break;
	    ++spread;
	    ++k;
	    ++l;
	  }
	  if (spread > maxSpread) maxSpread = spread;
	}
      }
    }
  }
  return maxSpread;
}

int main() {
  ColorfulChocolates cc;
  //  string chocolates = "ABCDCBC";
  //  string chocolates = "ABBABABBA";
  string chocolates = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
  cout << cc.maximumSpread(chocolates, 77) << endl;
  
  return 0;
}
