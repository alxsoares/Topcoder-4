#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<char, string> m;
map<char, bool> u;
vector<char> R;
string A;
char T, M, L;
long long C;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
  stringstream ss(s);
  string item;
  while(getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}


vector<string> split(const string &s, char delim) {
  vector<string> elems;
  return split(s, delim, elems);
}

void make_adj_lst(string s) {
  vector<string> sv = split(s, '.');
  sv = split(sv[0], ';');
  for (long long i = 0; i < sv.size(); ++i) {
    vector<string> tsv = split(sv[i], ':');
    m[tsv[0][0]] = tsv[1];
    u[tsv[0][0]] = false;
  }
  /*  
      for (auto i = m.begin(); i != m.end(); ++i) {
      cout << i->first << " " << i->second << endl;
      }
  */
}

void go(char M, char T, long long d) {
  L = M;
  if (d == C) {
    u[M] = true;
    R.push_back(M);
    d = 0;
  }
  for (long long i = 0; i < m[M].size(); ++i) {
    if (m[M][i] != T && !u[m[M][i]]) {
      go(m[M][i], M, d+1);
      break;
    }
  }
}

int main() {
  while (true) {
    cin >> A;
    if (A == "#") break;
    cin >> M >> T >> C;
    make_adj_lst(A);
    go(M, T, 1);
    for (long long i = 0; i < R.size(); ++i) {
      if (R[i] != L)
      cout << R[i] << " ";
    }
    cout << "/" << L << endl;
    m.clear();
    u.clear();
    R.clear();
  }
  return 0;
}
