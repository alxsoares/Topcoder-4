#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <ctime>
#include <complex>

using namespace std;

#define PB push_back
#define FOR(x,a,b) for (int x = a; x <= b; x++)
#define FORD(x,a,b) for (int x = a; x >= b; x--)

int cnt[11111];



void printint(int a) {
  cout << a << endl;
}


class KingdomAndDice {
public:

double newFairness(vector < int > firstDie, vector < int > secondDie, int X) {
  int n = firstDie.size();//n is the number of sides in each dice

  set < int > infirst;//store fixed number in first dice
  FOR (i, 0, n- 1) infirst.insert(firstDie[i]);

  secondDie.PB(0);
  secondDie.PB(X + 1);
  sort (secondDie.begin(), secondDie.end());

  vector < int > S; //store the values f()s we can chose
  FOR (i, 0, n) {
    int cnt = 0;
    FOR (j, secondDie[i] + 1, secondDie[i + 1] - 1)
      if (infirst.find(j) == infirst.end()) {
	//call f(j) and push it in S
	int f = 0;
	FOR (k, 1, n) f += secondDie[k] < j;
	S.PB(f);

	cnt++;
	if (cnt == n) break;
      }
  }

  for_each(S.begin(), S.end(), printint);
  int m = 0;//number of un-fixed sides in 1st dice
  FOR (i, 0, n - 1) m += firstDie[i] == 0;

  //we now calculate the values cnt(s)
  cnt [0] = 0;
  FOR (i, 1, n * n) cnt[i] = m + 1;

  int z = S.size();
  FOR (i, 0, z - 1)
    FORD (j, n * n, 1)
    if (j - S[i] >= 0) cnt[j] = min(cnt[j], cnt[j - S[i]] + 1);



  //calculate the sum of f() value in all fixed label side of 1st dice
  int sum = 0;
  FOR (i, 0, n - 1)
    if (firstDie[i] != 0)
      FOR (j, 1, n) sum += firstDie[i] > secondDie[j];

  //find the final result
  int res = -1;
  FOR (i, 0, n * n)
    if (cnt[i] <= m) {
      if (res == -1) res = i + sum;
      else if (abs(2 * (sum + i) - n * n) < abs(2 * res - n * n)) res = i + sum;
    }

  return (double) res / (double) (n * n);
};
};


int main() {
  KingdomAndDice k;
  int fd[] = {0, 2, 7, 0};
  int sd[] = {6, 3, 8, 10};
  vector<int> firstDie(fd, fd+4);
  vector<int> secondDie(sd, sd+4);
  cout << k.newFairness(firstDie, secondDie, 12) << endl;
  return 0;
}
