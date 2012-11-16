#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class ColorfulBricks {
public:
  int countLayouts(string bricks) {
    int nices = 0;
    sort(bricks.begin(), bricks.end());
    do {
      if (isNice(bricks)) {
	++nices;
      }
    } while (next_permutation(bricks.begin(), bricks.end()));
    return nices;
  };
private:
  bool isNice(string r) {
    size_t n = r.size();
    int c = 0;
    char prev = 0;
    for (int i = 0; i < n; ++i) {
      if (prev != r[i] and i != 0) ++c;
      prev = r[i];
    }
    return (c <= 1);
  };
};


int main() {
  ColorfulBricks cb;
  cout << cb.countLayouts("ABAB") << endl;
  
  return 0;
}
