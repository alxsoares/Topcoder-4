#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

vector<string> m;

pair<int, int> find_robot() {
  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m[i].size(); ++j) {
      if (m[i][j] != '.' && 
	  m[i][j] != '*' && 
	  m[i][j] != '#')
	return make_pair(i, j);
    }
  }
}

void print() {
  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m[i].size(); ++j) {
      cout << m[i][j];
    }
    cout << endl;
  }
}

int go(string &cmds, int x, int y) {
  int n = 0;
  int xx = x, yy = y;
  for (int i = 0; i < cmds.size(); ++i) {
    //    cout << cmds[i] << endl;
    //    print();
    //    cout << endl;
    char o = m[xx][yy];
    if (cmds[i] == 'D') {

      if (o == 'N') {
	m[xx][yy] = 'L';
      } else if (o == 'S') {
	m[xx][yy] = 'O';
      } else if (o == 'L') {
	m[xx][yy] = 'S';
      } else if (o == 'O') {
	m[xx][yy] = 'N';
      }

    } else if (cmds[i] == 'E') {

      if (o == 'N') {
	m[xx][yy] = 'O';
      } else if (o == 'S') {
	m[xx][yy] = 'L';
      } else if (o == 'L') {
	m[xx][yy] = 'N';
      } else if (o == 'O') {
	m[xx][yy] = 'S';
      }

    } else if (cmds[i] == 'F') {
      
      if (o == 'N') {
	if (xx - 1 >= 0 && m[xx-1][yy] != '#') {
	  m[xx][yy] = '.';
	  if (m[xx-1][yy] == '*') ++n;
	  m[xx-1][yy] = 'N';
	  --xx;
	}
      } else if (o == 'S') {
	if (xx + 1 < m.size() && m[xx+1][yy] != '#') {
	  m[xx][yy] = '.';
	  if (m[xx+1][yy] == '*') ++n;
	  m[xx+1][yy] = 'S';
	  ++xx;
	}
      } else if (o == 'L') {
	if (yy + 1 < m[xx].size() && m[xx][yy+1] != '#') {
	  m[xx][yy] = '.';
	  if (m[xx][yy+1] == '*') ++n;
	  m[xx][yy+1] = 'L';
	  ++yy;
	}
      } else if (o == 'O') {
	if (yy - 1 >= 0 && m[xx][yy-1] != '#') {
	  m[xx][yy] = '.';
	  if (m[xx][yy-1] == '*') ++n;
	  m[xx][yy-1] = 'O';
	  --yy;
	}
      }
    }
  }
  return n;
}

int main() {
  int N, M, S;
  while (true) {
    cin >> N >> M >> S;
    if (N == 0 && M == 0 && S == 0) break;
    for (int i = 0; i < N; ++i) {
      string s; 
      cin >> s;
      m.push_back(s);
    }
    string cmds;
    cin >> cmds;
    pair<int, int> pos = find_robot();
    int n = go(cmds, pos.first, pos.second);
    cout << n << endl;
    m.clear();
  }


  return 0;
}
