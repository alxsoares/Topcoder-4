#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

/*

You are given a vector <int> S containing a set of pairwise distinct positive integers.

Return the size of the largest subset T of S such that any two numbers from T are relatively prime

 */
/*
int primes[15] =  {2
		  ,3
		  ,5
		  ,7
		  ,11
		  ,13
		  ,17
		  ,19
		  ,23
		  ,29
		  ,31
		  ,37
		  ,41
		  ,43
		  ,47 };
*/

int primes[1] = {0};

long long factorize(int n) {
  long long fac = 0;
  while (n > 1) {
    for (int i = 0; i < 15; i++)
      if (n % primes[i] == 0) { 
	if (primes[i] != n || n <= 47)
	  fac |= (1 << i);
	n /= primes[i];
      }  
  }
  return fac;
}

class RelativelyPrimeSubset {
public:
  int findSize(vector <int> S);
};

int RelativelyPrimeSubset::findSize (vector<int> s) {
  const int m = 32768-1;
  int d[50][m] = {0};  /* cantidad de numeros coprimos en el subconjunto S[0..i] teniendo en cuenta los primos j */
  int size = s.size();
  int r = 0;
  for (int i = 1; i < size; i++) {
    for (int j = 0; j < m; j++) {
      if (j | factorize(i) == j) {
	d[i][j] = max(d[i-1][j], d[i][m & factorize(i)] + 1);
      } else {
	d[i][j] = d[i-1][j];
      }
      r = max(r, d[i][j]);
    }
  }
  return r;
}

int main() {
  RelativelyPrimeSubset rpss;
  int v[5] = {2,3,7,11,4};
  vector<int> vv(v, v+5);
  cout << rpss.findSize(vv) << endl;

  return 0;
}
