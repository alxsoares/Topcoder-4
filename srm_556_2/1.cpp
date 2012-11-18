#include <iostream>

using namespace std;

class ChocolateBar {
public:
  int maxLength(string letters);
};

int ChocolateBar::maxLength(string letters) {
  size_t n = letters.size();
  int max_size = 0;
  for (size_t a = 0; a < n; ++a) 
    for (size_t b = 0; b < n; ++b) {
      int size = b-a+1;
      bool rep = false;

      for (size_t i = a; i <= b; ++i) {
	string first = letters.substr(a, i-a);
	string last = letters.substr(i+1, b-i);

	if (first.find(letters[i])!=string::npos 
	    or last.find(letters[i])!=string::npos) {
	  rep = true;
	  break;
	} 
      }
      if (size > max_size and not rep) {
	max_size = size;
      }
    }
  return max_size;
}

int main() {
  ChocolateBar o;
  //  string letters = "srm";
  //  string letters = "dengklek";
  //  string letters = "haha";
  //  string letters = "www";
  string letters = "thisisansrmbeforetopcoderopenfinals";
  cout <<   o.maxLength(letters) << endl;
  return 0;
}
