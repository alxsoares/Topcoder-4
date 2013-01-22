#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> binary_input;

int leds[10] = {126, 48, 109, 121, 51, 91, 95, 112, 127, 123};


int toBin(string s) {
  int r = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'Y') r |= (1 << (6 - i));
  }
  return r;
}

bool F(int N, int i, int t, int b) {
  if (i == N) return true;
  if (t < 0) return false;
  bool r = false;
  int bb = leds[t] & ~b;
  if ((binary_input[i] | bb) == bb) {
    //    printf("%d works\n", t);
    b |= binary_input[i] ^ bb;
    r = F(N, i+1, t-1, b);
  }
  return r;
}

int main() {
  int N;
  while (cin >> N) {
    if (N == 0) break;
    binary_input.clear();
    for (int i = 0; i < N; ++i) {
      string s; cin >> s;
      binary_input.push_back(toBin(s));
    }
    bool match = false;
    for (int i = 0; i < 10; ++i) {
      //      printf("Testing %d\n", i);
      match = match || F(N, 0, i, 0);
      //      printf("%d\n\n", match);
    }
    if (match)
      cout << "MATCH" << endl;
    else
      cout << "MISMATCH" << endl;
  }
  return 0;
}
