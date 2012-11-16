#include <iostream>
#include <string>

using namespace std;

class EasyConversionMachine {
public:
  string isItPossible(string originalWord, string finalWord, int k);
};

string EasyConversionMachine::isItPossible(string originalWord, string finalWord, int k) {
  int size = originalWord.size(), c = 0;
  for (int i = 0; i < size; i++) {
    if (originalWord[i] != finalWord[i]) c++;
  }
  cout << c << endl;
  cout << c-k % 2 << endl;
  if (c >= k && (c-k) % 2 == 0) return "POSSIBLE";
  else return "IMPOSSIBLE";
}


int main() {
  EasyConversionMachine em;
  int k;
  string original, final;
  while (cin >> original) {
    cin >> final;
    cin >> k;
    cout << em.isItPossible(original, final, k) << endl;
  }
}
