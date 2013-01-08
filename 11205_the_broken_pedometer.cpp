#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <cmath>

using namespace std;

int numbers[101];

void printBinary(int n, int p) {
  for(int i = p-1; i >= 0; --i) {
    if (n&(1<<i)) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");
}

int countOnes(int s) {
  int r = 0;
  while (s) {
    if (s&1)
      ++r;
    s >>= 1;
  }
  return r;
}

int main() {
  int TC;
  cin >> TC;

  for (int tc = 1; tc <= TC; ++tc) {
    int N, P;
    cin >> P;
    cin >> N;
    memset(numbers, 0, sizeof(numbers));
    for (int i = 0; i < N; ++i) {
      for (int j = P-1; j >= 0; --j) {
	int b = 0;
	cin >> b;
	if (b)
	  numbers[i] = numbers[i]|(1<<j);
	else
	  numbers[i] = numbers[i]&(~(1<<j));
      }
    }
    int minones = P;
    for (int s = 0; s <= pow(2, P)-1; ++s) {
      set<int> unique;
      int used = countOnes(s);
      for (int i = 0; i < N; ++i) {
	int n = numbers[i]&s;
	unique.insert(n);
      }
      if (unique.size() == N and used < minones) {
	minones = used;
      }
    }
    printf("%d\n", minones);
  }
  return 0;
}
