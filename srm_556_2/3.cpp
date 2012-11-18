#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class LeftRightDigitsGame {
public:
  string minNumber(string digits);
};

string dp[50];

char minNonCero(string s) {
  char min = '9';
  for (int i = 0; i < s.size(); ++i)
    if (s[i] < min and s[i] != '0') min = s[i];
  return min;
}


string LeftRightDigitsGame::minNumber(string digits) {
  dp[0] = digits[0];
  size_t n = digits.size();
  char m = minNonCero(digits);

  for (size_t i = 1; i < n; ++i) {
    
    string left=digits[i]+dp[i-1], right=dp[i-1]+digits[i];
  
    if (left[0] == m)
      right = left;

    if (right[0] == m)
      left = right;
  
    dp[i] = min(left, right);

  }
  return dp[n-1];
}

int main() {
  LeftRightDigitsGame o;
  //    string digits = "565";
  //  string digits = "9876543210";
      string digits = "8016352";
  cout << o.minNumber(digits) << endl;
  return 0;
}
