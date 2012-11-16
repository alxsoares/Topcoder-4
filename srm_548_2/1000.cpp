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


void printint(int i) {
  cout << i << endl;
}


int minabs(int n, int m, vector<int> v) {
  int min = INT_MAX;
  int ite_min = v.size();
  for (int ite = 0; ite < v.size(); ite++) {
    int abs = fabs(n-v[ite]);
    if (abs < min && v[ite] != m) {
      min = abs;
      ite_min = ite; 
    }
  }
  return ite_min;
}

int maxrest(int m, vector<int> v) {
  int max = 0;
  int ite_max = v.size();
  for (int ite = 0; ite < v.size(); ite++) {
    if (max < v[ite] && v[ite] != m) {
      max = v[ite];
      ite_max = ite;
    }
  }
  return ite_max;
}


class KingdomAndPassword {
public:
  long long newPassword(long long oldPassword, vector<int> restrictedDigits) {
    ostringstream so;
    so << oldPassword;
    string op = so.str();
    int size = op.size();
    int state = 0;
    vector<int> v;
    string r;
    for (int i = 0; i < size; i++) {
      v.push_back(op[i]-48);
    }
    for (int i = 0; i < size; i++) {
      if (state == 0) {
	if (restrictedDigits[i] != op[i]-48) {
	  r += op[i];
	  if (v.size() > 1) {
	    v[i] = v[v.size()-1];
	  }
	  v.pop_back();
	} else {
	  state = 1;
	}

      } 
      if (state == 1) {
	int ite = minabs(v[i], restrictedDigits[i], v);
	if (ite == v.size()) return -1;
	int tmp = v[ite];
	if (v.size() > 1) {
	  v[ite] = v[v.size()-1];
	}
	v.pop_back();
	ITOA(tmp);
	r+=s;
	state = 2;
      } else if (state == 2) {
	int ite = maxrest(restrictedDigits[i], v);
	if (ite == v.size()) return -1;
	int tmp = v[ite];
	if (v.size() > 1) {
	  v[ite] = v[v.size()-1];
	}
	v.pop_back();
	ITOA(tmp);
	r += s;
	state = 2;
      }
    }
    istringstream rs(r);
    long long rl;
    rs >> rl;
    return rl;
  };
};


int main() {
  KingdomAndPassword k;
  long long oldPassword = 241529363573463LL;
  // int rd[] = {5, 1, 8};
  //  int rd[] = {4, 7, 4, 7};
  //  int rd[] = {4, 7};
  //  int rd[] = {4, 7, 4};
  int rd[] = {1, 4, 5, 7, 3, 9, 8, 1, 7, 6, 3, 2, 6, 4, 5};
  vector<int> rdv(rd, rd+15);
  cout << k.newPassword(oldPassword, rdv) << endl;
  return 0;
}
