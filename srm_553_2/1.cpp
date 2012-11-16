#include <iostream>

using namespace std;

class PlatypusDuckAndBeaver {
public:
  int minimumAnimals(int webbedFeet, int duckBills, int beaverTails);
};

int PlatypusDuckAndBeaver::minimumAnimals(int webbedFeet, int duckBills, int beaverTails) {
  int ducks = (webbedFeet-4*beaverTails)/2;
  int platypus = duckBills-ducks;
  int beaver = beaverTails-platypus;
  return ducks+platypus+beaver;
}

int main() {
  PlatypusDuckAndBeaver o;
  //  cout << o.minimumAnimals(4,1,1) << endl;
  //  cout << o.minimumAnimals(0,0,0) << endl;
  //  cout << o.minimumAnimals(10,2,2) << endl;
  //  cout << o.minimumAnimals(60,10,10) << endl;
  cout << o.minimumAnimals(1000,200,200) << endl;
  return 0;
}
