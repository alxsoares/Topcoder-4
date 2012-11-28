#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 51;
const int MAXC = 4;

int dp[MAXN][MAXN][MAXN][MAXC]; // index, stampSize, prevChunkColor, prevChunkSize


class Stamp {
public:
  string dcolor;
  int scost;
  int pcost;
  size_t n;
  int colorToInt(char color);
  int F(int index, int stampSize, int prevChunkColor, int prevChunkSize, int tab);
  int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
    int r = 0;
    dcolor = desiredColor;
    scost = stampCost;
    pcost = pushCost;
    n = desiredColor.size();

    for (size_t i = 0; i <= n; ++i) {
      for (size_t j = 0; j <= n; ++j) {
	for (size_t c = 0; c < MAXC; ++c) {
	  for (size_t k = 0; k <= n; ++k) {
	    if (i == n)
	      dp[i][j][k][c] = 0;
	    else 
	      dp[i][j][k][c] = -2;
	  }
	}
      }
    }

    int minr = 50*50;
    for (size_t ss = 1; ss <= n; ++ss)
      for (size_t c = 0; c < MAXC; ++c) {
	int r = F(0, ss, 0, 0, 0);
	if (r != -1) {
	  r += ss * scost;
	  if (r < minr) {
	    minr = r;
	  }
	}
      }
	
    return minr;
  }
};

int Stamp::colorToInt(char color) {
  switch (color) {
  case '*': 
    return 0;
  case 'R': 
    return 1;
  case 'G': 
    return 2;
  case 'B': 
    return 3;
  default:
    return 0;
  }
}


string pTabs(int tab) {
  string tabs = "";
  for (int i = 0;  i < tab; ++i)
    tabs += "\t";
  return tabs;
}

int Stamp::F(int index, int stampSize, int prevChunkColor, int prevChunkSize, int tabs) {
  int rmin = -1;
  cout << pTabs(tabs) << "begin **********" << endl;
  cout  <<  pTabs(tabs) << " index=" << index
        << " stampSize=" << stampSize
        << " prevChunkColor=" << prevChunkColor
	<< " prevChunkSize=" << prevChunkSize
	<< endl;
       

  if (dp[index][stampSize][prevChunkColor][prevChunkSize] != -2) {    
    cout <<  pTabs(tabs) << " in dp " << dp[index][stampSize][prevChunkColor][prevChunkSize] << endl;
    return dp[index][stampSize][prevChunkColor][prevChunkSize];
  }
  int i = 0;
  bool same_color = true;
  char cc = dcolor[index];

  for (i = index; i < min(index+stampSize, (int)n); ++i) {
    if (cc == '*' and dcolor[i] != '*')
      cc = dcolor[i];
  }
  
  cout <<  pTabs(tabs) << "color " << cc << endl;
  
  // forward
  if (index + stampSize <= n) {
    char c = dcolor[index];
    cc = c;
    for (i = index; i < index+stampSize; ++i) {
      if (c != dcolor[i] and c != '*' and dcolor[i] != '*') {
	same_color = false;
	break;
      }
    }
    if (same_color) {
      int chunkSize = stampSize;
      if (prevChunkColor == 0 or prevChunkColor == colorToInt(cc)
	  or colorToInt(cc) == 0)
	chunkSize += prevChunkSize;
      rmin=F(index+stampSize, stampSize, colorToInt(cc), chunkSize, tabs+1);
      if (rmin != -1)
	rmin += pcost;
    }
  }

  if (not same_color) {
    cout << pTabs(tabs) << "entro aca" << endl;

    int dif = index+stampSize-i;
    cout << pTabs(tabs) << "cc = " << cc << " prevChunkColor=" << prevChunkColor << endl;
    cout << pTabs(tabs) << "dif = " << dif << " prevChunkSize=" << prevChunkSize << endl;
    if ((colorToInt(cc) == prevChunkColor or cc == '*' or prevChunkColor == 0) 
	and dif <= prevChunkSize) {
      for (int j = index-1; index-prevChunkSize < j; --j) {
	int r = F(j, stampSize, colorToInt(cc), prevChunkSize-index+j, tabs+1);	
	cout << pTabs(tabs) << "r=" << r << endl;
	if (r != -1) {
	  if (rmin > r or rmin == -1) 
	    rmin = r;

	}
      }
    }
  }
  
  cout << pTabs(tabs) << "rmin=" << rmin << endl;
  
  if (index+stampSize > n) {
    cout <<  pTabs(tabs) << "entro alla" << endl;
      
    int dif = index+stampSize-n;
    if ((cc == prevChunkColor or cc == '*' or prevChunkColor == 0) 
	and dif <= prevChunkSize) {

      int r  = F(n, stampSize, colorToInt(cc), 0, tabs+1);
      r += pcost;
      if (r != -1) {
	if (r < rmin or rmin == -1) rmin = r;
	
      }
    }
  }

  cout <<  pTabs(tabs) << "end "
       << index << " " << stampSize 
       << " r=" << rmin 
       << endl; 
  
  dp[index][stampSize][prevChunkColor][prevChunkSize] = rmin;
  return rmin;
}

int main() {
  /*
      string desiredColor = "RRGGBB";
      int stampCost = 1;
      int pushCost = 1;
  */
    
  /*    string desiredColor = "R**GB*";
      int stampCost = 1;
      int pushCost = 1;
    
*/  
  /*      string desiredColor = "BRRB";
      int stampCost = 2;
      int pushCost = 7;
  */
  
  /*
    string desiredColor = "R*RR*GG";
      int stampCost = 10;
      int pushCost = 58;
  */
  /*
    string desiredColor = "*B**B**B*BB*G*BBB**B**B*";
      int stampCost = 5;
      int pushCost = 2;
  */
  string desiredColor = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
      int stampCost = 7;
      int pushCost = 1;
  Stamp s;
  cout << s.getMinimumCost(desiredColor, stampCost, pushCost) << endl;
  return 0;
}
