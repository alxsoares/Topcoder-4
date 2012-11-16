#include <iostream>

using namespace std;

class BallAndHats {
public:
  int getHat(string hats, int numSwaps) {
    int n = hats.size();
    int p = 0;
    for (int i = 0; i < n; i++)
      if (hats[i] == 'o') p = i;
    if (numSwaps == 0) return p;
    if (numSwaps % 2 == 0 && p == 1) return 1;
    if (numSwaps % 2 == 0 && p != 1) return 0;
    if (p == 0) return 1;
    if (p != 0) return 0;
  };
};


int main() {
  BallAndHats b;
  string a = "o..";
  int s = 101;
  cout << b.getHat(a, s) << endl;
  return 0;
}
