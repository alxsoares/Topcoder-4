#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class SweetFruits {
public:
  int countTrees(vector<int> sweetness, int maxSweetness);
};


void printMatrix(vector<vector<double> > m) {
  int n = m.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << m[i][j] << " ";
    } 
    cout << endl;
  }
  cout << "END" << endl;
}

bool cmpVecAbs(vector<double> v1, vector<double> v2) { 
  int n = v1.size();
  for (int i = 0; i < n; ++i) {
    if (fabs(v1[i]) > fabs(v2[i])) return true;
    if (fabs(v1[i]) < fabs(v2[i])) return false;
  }
  return true;
}


vector<vector<double> > generate(int xCard, int numSweet) {
  int n = numSweet;
  vector<vector<double> > m;
  
  for (int i = 0; i < n; ++i) {
    vector<double> r;
    for (int j = 0; j < n; ++j) {
      if (i <= xCard) {
	if (xCard <= j) {
	  r.push_back(-1.0);
	} else {
	  r.push_back(0.0);
	}
      } else {
	r.push_back(0.0);
      }
    }
    m.push_back(r);
  }

  for (int i = 0; i < n; ++i) {
    if (i <= xCard)
      m[i][i] = xCard;
    else 
      m[i][i] = 0;
  }

  return m;
}

double determinant(vector<vector<double> > m) {
  double d = 1.0;
  int n = m.size();
  
  for (int c = 0; c < n; ++c) {
    printMatrix(m);
    sort(m.begin(), m.end(), cmpVecAbs);
    printMatrix(m);

    d *= m[c][c];
    for (int r = c; r < n; ++r) {
      double div = m[r][c];
      if (div != 0) {
	for (int cc = c; cc < n; ++cc) m[r][cc] /= div;
      }
    }
    printMatrix(m);
    for (int r = c+1; r < n; ++r) {
      if (m[r][c] != 0) { 
	for (int cc = c; cc < n; ++cc) {
	  m[r][cc] -= m[c][cc];
	}
      }
    }
    printMatrix(m);
  }

  return d;
}

int main() {
  vector<vector<double> > m;
  m = generate(5, 10);  
  cout << determinant(m) << endl;



  return 0;
}
