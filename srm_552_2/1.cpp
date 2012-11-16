#include <iostream>
#include <vector>


using namespace std;

class FoxAndFlowerShopDivTwo {
public:
  int theMaxFlowers(vector<string> flowers, int r, int c);
};


int FoxAndFlowerShopDivTwo::theMaxFlowers(vector<string> flowers, int r, int c) {
  int c1=0, c2=0, c3=0, c4=0;
  for (auto i = 0; i != flowers.size(); ++i) {
    for (auto j = 0; j != flowers[i].size(); ++j) {
      char is = flowers[i][j];
      bool t = (is == 'F');

      if (i < r && t) // cuadrante arriba 
	++c1;
      if (i > r && t) // cuadrante abajo
	++c2;
      if (j < c && t) // cuadrante izquierdo 
	++c3;
      if (i > c && t) // cuadrante derecho
	++c4;
    }
  }
  return max(c1, max(c2, max(c3, c4)));
}

int main() {
  FoxAndFlowerShopDivTwo o;
  vector<string> flowers = {"F.F",
			    ".F.",
			    ".F."};
  cout << o.theMaxFlowers(flowers, 1, 1) << endl;
  return 0;
}
