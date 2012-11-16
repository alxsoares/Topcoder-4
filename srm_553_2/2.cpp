#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Suminator {
public:
  int findMissing(vector<int> program, int wantedResult);
};

int Suminator::findMissing(vector<int> program, int wantedResult) {
  int n = program.size(), p = 0;
  stack<long long> s;

  for (int i = 0; i < n; ++i) {
    if (program[i] > 0) {
      s.push(program[i]);
    } else {
      long long e1 = 0, e2 = 0;
      if (not s.empty()) {e1 = s.top();s.pop();}
      if (not s.empty()) {e2 = s.top();s.pop();}
      s.push(e1+e2);
    }
  }
  if (not s.empty() and s.top() == wantedResult) return 0;
  stack<long long> s2;
  long long min = wantedResult;
  for (int i = 0; i < n; ++i) {
    if (program[i] > 0 or program[i] == -1) {
      s2.push(program[i]);
    } else {
      long long e1 = 0, e2 = 0;
      if (not s2.empty()) {e1 = s2.top();s2.pop();}
      if (not s2.empty()) {e2 = s2.top();s2.pop();}
      if (e1 == -1) {
	min -= e2;
	s2.push(e1);
      } else if (e2 == -1) {
	min -= e1;
	s2.push(e2);
      } else {
	s2.push(e1+e2);
      }
    }
  }
  if (min > 0 and s2.top() == -1) return min;
  else return -1;
}

int main() {
  Suminator o;
   vector<int> program = {7,-1,0};
    int wantedResult = 10;
  //  vector<int> program = {100, 200, 300, 0, 100, -1};
  //  int wantedResult = 600;
  //  vector<int> program = {-1, 7, 3, 0, 1, 2, 0, 0};
  //  int wantedResult = 13;
  //  vector<int> program = {-1, 8, 4, 0, 1, 2, 0, 0};
  //  int wantedResult = 16;

  //  vector<int> program = {1000000000, 1000000000, 1000000000,  
  //			 1000000000, -1, 0, 0, 0, 0};
  //  int wantedResult = 1000000000;

  //  vector<int> program = {7, -1, 3, 0};
  //  int wantedResult = 3;
  cout << o.findMissing(program, wantedResult) << endl;
  return 0;
}
