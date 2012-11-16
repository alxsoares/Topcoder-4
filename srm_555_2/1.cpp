#include <iostream>
#include <vector>

using namespace std;

class XorBoardDivTwo {
public:
  int theMax(vector<string> board);
};

int XorBoardDivTwo::theMax(vector<string> board) {
  size_t n = board.size();
  size_t m = board[0].size();
  vector<int> rowcount(0, n);
  vector<int> colcount(0, m);
  int tot = 0;
  for (size_t i = 0; i < n; ++i) {
    int sum = 0;
    for (size_t j = 0; j < m; ++j) {
      sum += (board[i][j]=='1')?1:0;
    }
    tot += sum;
    rowcount.push_back(sum);
  }

  for (size_t i = 0; i < m; ++i) {
    int sum = 0;
    for (size_t j = 0; j < n; ++j) {
      sum += (board[j][i]=='1')?1:0;
    }
    colcount.push_back(sum);
  }
  int summax = 0;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      int sum = 0;
      if (board[i][j] == '1') {
	sum += tot;
	sum += n-2*rowcount[i];
	sum += m-2*colcount[j]+2;
	
      } else {
	sum += tot;
	sum += n-2*rowcount[i];
	sum += m-2*colcount[j]-2;
      }
      if (sum > summax) summax = sum;
    }
  }
  return summax;
}

int main() {
  XorBoardDivTwo o;
  /*  
      vector<string> board = {"101",
			  "010",
			  "101"};
  */
  /*  vector <string> board = {"111",
			   "111",
			   "111"};
  */
  /*  vector <string> board = {"0101001",
      "1101011"};*/
  /*  vector<string> board = {"000",
			  "001",
			  "010",
			  "011",
			  "100",
			  "101",
			  "110",
			  "111"};*/
  vector<string> board = {"000000000000000000000000",
			  "011111100111111001111110",
			  "010000000100000001000000",
			  "010000000100000001000000",
			  "010000000100000001000000",
			  "011111100111111001111110",
			  "000000100000001000000010",
			  "000000100000001000000010",
			  "000000100000001000000010",
			  "011111100111111001111110",
			  "000000000000000000000000"};

  cout << o.theMax(board) << endl;
  return 0;
}
