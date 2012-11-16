#include <vector>
#include <list>
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


class FavouriteDigits {
public:
  long long findNext(long long N, int digit1, int count1, 
		     int digit2, int count2);
};

string toString(long long n) {
  ostringstream convert;
  convert << n;
  string nstr = convert.str();
  return nstr;
}

long long toNum(vector<int> v) {
  long long n = 0;
  for (int i = 0; i < v.size(); i++) {
    n += v[i] * pow(10.0, v.size()-i-1);
  }
  return n;
}


long long prefix(string n, int p) {
  int size = n.size()-p;
  vector<int> num;
  for (int i = 0; i < size; i++){
    num.push_back(n[i]-48);
  }
  return toNum(num);
}


const long long maxN = 999999999999999LL;

long long FavouriteDigits::findNext(long long N, int digit1, int count1, 
				    int digit2, int count2) {
  string nstr = toString(N);
  int n = nstr.size();
  int tot1 = 0;
  int tot2 = 0;
  
  for (int i = 0; i < n; ++i) {
    if (nstr[i]-48 == digit1) {
      tot1 += 1;
    } else if (nstr[i]-48 == digit2) {
      tot2 += 1;
    }
  }
  int n1 = tot1, n2 = tot2;
  int idx = n-1;
  bool all = false;
  while (tot1 < count1 || tot2 < count2) {
    if (nstr[idx]-48 < digit2) tot2++;
    else if (nstr[idx]-48 < digit1) tot1++;
    else {
      tot2++;
      nstr[idx-1]++;
    }
    if (idx > 0) idx--;
    else {all = true; break;}
  }
  long long num_long;
  if (!all) {
  
    int used = n-1-idx;
    vector<int> perm;
    for (int i = 0; i < count1-n1; i++) {
      perm.push_back(digit1);
    }
    
    for (int i = 0; i < count2-n2; i++) {
      perm.push_back(digit2);
    }
    
    do {
      string a = toString(prefix(nstr, used));
      string b = toString(toNum(perm));
      string c = a + b;
      istringstream(c) >> num_long;
      if (num_long > N) break;
    } while (next_permutation(perm.begin(), perm.end()));

  } else {
    vector<int> perm;
    int nceros = n - count1 - count2 + 1;

    for (int i = 0; i < nceros; i++) {
      perm.push_back(0);
    }

    for (int i = 0; i < count1; i++) {
      perm.push_back(digit1);
    }
    
    for (int i = 0; i < count2; i++) {
      perm.push_back(digit2);
    }

    do {
      num_long = toNum(perm);
      if (num_long > N) break;
    } while (next_permutation(perm.begin(), perm.end()));
  }
  return num_long;
}

int main() {
  FavouriteDigits fd;
  //  cout << fd.findNext(123456789012345LL, 1, 2, 2, 4) << endl;
  //  cout << fd.findNext(47LL, 5, 0, 9, 1) << endl;
  //  cout << fd.findNext(47LL, 5, 0, 3, 1) << endl;
    cout << fd.findNext(47LL, 2, 1, 0, 2) << endl;
  //  cout << fd.findNext(92LL, 1, 1, 0, 0) << endl;
  return 0;
}
