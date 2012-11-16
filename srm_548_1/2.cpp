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

const double EPS = 1e-10;
const double PI = 3.14159265358979323846264338328;

#define PB push_back
#define FOR(a,start,end) for(long long a = (start); a < (end); a++)
#define FORI(a,start,end) for(long long a = (start); a >= (end); a--)
#define MSG(a) cout << #a << " = " << a << endl;
#define ITOA(a) char c[500]; sprintf(c,"%d",a); string s(c);
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())
#define tr(container, it) for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define CLOCK cout << "CLOCK " << (double)clock()/CLOCKS_PER_SEC << endl
#define DMSG(a) FOR(i,0,(a).size()) { FOR(j,0,(a)[i].size()) cout << (a)[i][j] << " "; cout << endl; }


void printint(int a) {
  cout << a << endl;
}

class KingdomAndDice {
public:
  double newFairness(vector<int> firstDie, vector<int> secondDie, int X) {
    // calculate f(x) for x in [0..X]
    int *f = new int[X+1];
    int size = secondDie.size();
    for (int i = 0; i <= X; i++) {
      for (int j = 0; j < size; j++) {
	f[i] += (i > secondDie[j])?1:0;
      }
    }

    set <int> infirst;
    for (int i = 0; i < size; i++) infirst.insert(firstDie[i]);

    secondDie.PB(0);
    secondDie.PB(X+1);
    sort(secondDie.begin(), secondDie.end());

    vector<int> S;
    for (int i = 0; i <= size; i++) {
      int cnt = 0;
      for (int j = secondDie[i]+1; j <= secondDie[i+1]-1; j++) {

	if (infirst.find(j) == infirst.end()) {
	  S.push_back(f[j]);
	  cnt++;
	  if (cnt == size) break;
	}
      }
    }

    int m = 0;
    for (int i = 0; i < size; i++) m += (firstDie[i] == 0);

    int cnt[11111] = {0};
    for (int i = 1; i <= size*size; i++) cnt[i] = m+1;

    for (int i = 0; i < S.size(); i++) {
      for (int j = size*size; j > 0; j--) {
	if (j >= S[i]) {
	  cnt[j] = min(cnt[j], cnt[j-S[i]]+1);
	}
      }
    }

    int sum = 0;
    for (int i = 0; i < size; i++)  sum += f[firstDie[i]];
    

    int res = -1;

    for (int i = 0; i < size*size; i++) {
      if (cnt[i] <= m) {
	if (res == -1) res = i + sum;
	else if (fabs(2*(sum+i) - size*size) < fabs(2*res - size*size)) {
	  res = i + sum;
	}
      }
    }
    
    delete[] f;

    return (double)res/(double)(size*size);

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
