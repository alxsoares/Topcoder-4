#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> powof5 = {
  "1",
  "101",
  "11001",
  "1111101",
  "1001110001",
  "110000110101",
  "11110100001001",
  "10011000100101101",
  "1011111010111100001",
  "111011100110101100101",
  "100101010000001011111001",
  "10111010010000111011011101",
  "1110100011010100101001010001",
  "1001000110000100111001110010101",
  "101101011110011000100000111101001",
  "11100011010111111010100100110001101",
  "10001110000110111100100110111111000001",
  "1011000110100010101111000010111011000101",
  "110111100000101101101011001110100111011001",
  "100010101100011100100011000001001000100111101"};

class CuttingBitString {
public:
  int getmin(string S);
};

int F(string & S, int pos) {
  if (pos == S.size()) {
    return 0;
  }
  int minpart = 51;
  bool finded = false;
  for (size_t i = 0; i < powof5.size(); ++i) {
    if (S.find(powof5[i], pos) == pos) {
      int part = F(S, pos+powof5[i].size());
      if (part == -1) continue;
      ++part;
      if (part < minpart) minpart = part;
      finded = true;
    } 
  }
  if (not finded) minpart = -1;
  
  return minpart;
}

int CuttingBitString::getmin(string S) {
  reverse(powof5.begin(), powof5.end());
  return F(S, 0);
}

int main() {
  CuttingBitString o;
  //  string S = "101101101";
  //  string S = "1111101";
  //  string S = "00000";
  //  string S = "110011011";
  //  string S = "1000101011";
  string S = "111011100110101100101110111";
  cout << o.getmin(S) << endl;
  return 0;
}

