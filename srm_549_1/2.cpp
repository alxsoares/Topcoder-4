#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <cstring>

using namespace std;

const int maxHats = 13;
const int maxState = 1594323;
const int maxv = 15;
const int INFINITY = 20;

class MagicalHats {
private:
  int pow3[maxv];
  int numHatRow[maxv];
  int numHatCol[maxv];
  int numCoinsRow[maxv];
  int numCoinsCol[maxv];
  vector<pair<int, int> > hatPos;
  size_t boardSize;
  size_t coinsSize;
  int numGuesses;
  int numHats;

  enum state {DOWN, COIN, NO_COIN};
  
public:

  MagicalHats () {
    pow3[0] = 1;
    for (size_t i = 1; i <= 13; ++i)
      pow3[i] *= 3;
    memset(numHatRow, 0, sizeof(int)*maxv);
    memset(numHatCol, 0, sizeof(int)*maxv);
    memset(numCoinsRow, 0, sizeof(int)*maxv);
    memset(numCoinsCol, 0, sizeof(int)*maxv);

  };

  int setDigitBase3(int n, state d, int i) {
    return ((n/pow3[i+1])*pow3[i+1]+d*pow3[i]+n%pow3[i]);
  };

  int getDigitBase3(int n, int i) {
    return (n/pow3[i])%3;
  };

  int F(int state, int coinsPlaced, int hatsSelected,
	int *colCount, int *rowCount) {
    
    if (hatsSelected == numHats) {
      if (coinsPlaced != coins.size())
	return -INFINITY;

      for (int i = 0; i < C; ++i)
	if (colCount[i]%2 == 1) return -INFINITY;

      for (int i = 0; i < H; ++i)
	if (rowCount[i]%2 == 1) return -INFINITY;

      return 0;
    }


    r = dp[state];
    if (seen[state])
      return r;
    seen[state] = true;
    r = -INFINITY;

    for (int i = 0; i < numHats; ++i) {
      int r = hatPos[i], c = hatPos[i];
      int d = getDigitBase3(state, i);
      int r1 = -INFINITY;
      if (d == DOWN) {
	// case 1
	if (coinsPlaced < coinsSize) {
	  int newState = setDigitBase3(state, COIN, i);
	  int profit = 0;
	  if (hatsSelected < numGuesses) {
	    profit = 1;
	    colCount[c] += 2;
	    rowCount[r] += 2;
	    r1 = F(newState, coinsPlaced+1, hatsSelected+1, 
		       colCount, rowCount);
	    colCount[c] -= 2;
	    rowCount[r] -= 2;
	  }
	}
	
	// case 2

	int newState = setDigitBase3(state, NO_COIN, i);
	colCount[c] += 1;
	rowCount[r] += 1;
	int r2 = F(newState, coinsPlaced, hatsSelected+1,
		   colCount, rowCount);
	colCount[c] -= 1;
	rowCount[r] -= 1;
	
	if (r1 < 0)
	  r = max(r, r1);
	if (r2 < 0)
	  r = max(r, r2);
	else
	  r = max(r, min(r1, r2));
      }
    }
    return dp[state] = r;
  }


  int findMaximumReward(vector<string> board, 
			vector<int> coins, 
			int _numGuesses) {
    boardSize = board.size();
    coinsSize = coins.size();
    numGuesses = _numGuesses;
    vector<pair<int, int> > hatPos;

    for (size_t i = 0; i < boardSize; ++i) {
      for (size_t j = 0; j < boardSize; ++j) {
	if (board[i][j] == 'H') {
	  ++numHats;
	  hatPos.push_back(make_pair(i, j));
	  ++numHatRow[i];
	  ++numHatCol[i];
	}
      }
    }
    
    int maxNumCoins = 0;
    for (int s = 0; s < maxState; ++s) {
      int nCoins = isValidState(s);
      if (nCoins != -1 && maxNumCoins < nCoins) {
	maxNumCoins = nCoins;
      }
    }


    sort(coins.begin(), coins.end());
    int sumOfCoins = 0;

    // aca llamo a F por primera vez

    return sumOfCoins;
  };
};

int main() {
  MagicalHats mh;
  string s1 = ".............";
  string s2 = ".............";
  string s3 = ".............";
  string s4 = ".............";
  string s5 = ".............";
  string s6 = ".............";
  string s7 = ".....H.H.....";
  string s8 = "......H......";
  string s9 = ".....H.H.....";
  string s10 = ".............";
  string s11 = ".............";
  string s12 = ".............";
  string s13 = ".............";
  
  vector<string> board;
  board.push_back(s1);
  board.push_back(s2);
  board.push_back(s3);
  board.push_back(s4);
  board.push_back(s5);
  board.push_back(s6);
  board.push_back(s7);
  board.push_back(s8);
  board.push_back(s9);
  board.push_back(s10);
  board.push_back(s11);
  board.push_back(s12);
  board.push_back(s13);
  
  vector<int> coins;
  coins.push_back(22);
  int numGuesses = 3;

  cout <<  mh.findMaximumReward(board, coins, numGuesses) << endl;

  return 0;
}
