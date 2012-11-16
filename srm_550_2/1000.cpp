#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
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
#define FORI(a,start,end) for(long long a = (start); a > (end); a--)
#define MSG(a) cout << #a << " = " << a << endl;
#define ITOA(a) char c[500]; sprintf(c,"%d",a); string s(c);
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())
#define tr(container, it) for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define CLOCK cout << "CLOCK " << (double)clock()/CLOCKS_PER_SEC << endl
#define DMSG(a) FOR(i,0,(a).size()) { FOR(j,0,(a)[i].size()) cout << (a)[i][j] << " "; cout << endl; }


class TopView {
public:
  string findOrder(vector<string> grid);
};


struct carddata {
  int xinit;
  int xend;
  int yinit;
  int yend;
};

string TopView::findOrder(vector<string> grid) {
  map<int, carddata*> cards; 
  FOR(i,0,grid.size()) {
    FOR(j,0,grid[i].size()) {
      if (grid[i][j] != '.') {
	if (cards.find(grid[i][j]) == cards.end()) {
	  carddata *pc = new carddata;
	  pc->xinit = INT_MAX;
	  pc->yinit = INT_MAX;
	  pc->xend = 0;
	  pc->yend = 0;
	  cards[grid[i][j]] = pc;
	}
	cards[grid[i][j]]->xinit = 
	  min((int)(cards[grid[i][j]]->xinit), (int)j);
	cards[grid[i][j]]->xend =
	  max((int)(cards[grid[i][j]]->xend), (int)j);
	cards[grid[i][j]]->yinit = 
	  min((int)(cards[grid[i][j]]->yinit), (int)i);
	cards[grid[i][j]]->yend = 
	  max((int)(cards[grid[i][j]]->yend), (int)i);
      }
    }
  }

  
  string result;
  set<char> chars_set;
  int size;
  tr (cards,ite) chars_set.insert((*ite).first);
  do {
    size = result.size();
    set<char> rest;
    set<char> result_set(result.begin(), result.end());
    string parcial_result;
    set_difference(chars_set.begin(), chars_set.end(), result_set.begin(), 
		   result_set.end(), inserter(rest, rest.end()));
    tr(rest,c) {
      bool fail = false;
      FOR(i,0,grid.size()) {
	FOR(j,0,grid[0].size()) {
	  if (i >= cards[*c]->yinit 
	      && i <= cards[*c]->yend
	      && j >= cards[*c]->xinit 
	      && j <= cards[*c]->xend
	      && grid[i][j] != *c
	      && find(result.begin(), result.end(), grid[i][j]) == result.end()) {
	    fail = true;
	  }
	}
      }
      if (!fail) {
	parcial_result.push_back(*c);
      }
    }
    SORT(parcial_result);
    REV(parcial_result);
    result += parcial_result;
  } while (result.size() != size);
  
  if (result.size() != cards.size()) return "ERROR!";
  REV(result);

  return result;
}

int main() {
  TopView tv;
  vector<string> grid;
  /*
  grid.push_back("..AA..");
  grid.push_back(".CAAC.");
  grid.push_back(".CAAC.");
  */
  
  /*grid.push_back("..47..");
  grid.push_back("..74..");
  */

  grid.push_back("aabbaaaaaaaaaaaaaaaaaa");
  grid.push_back("aabbccccccccccccccaaaa");
  grid.push_back("aab11111ccccccccccaaaa");
  grid.push_back("aab12221ccccccccccaaaa");
  grid.push_back("aab12221ccccccccccaaaa");
  grid.push_back("aab12221ccccccccccaaaa");
  grid.push_back("aab12221ccccccccccaaaa");
  grid.push_back("aab12221ccccccccccaaaa");
  grid.push_back("aab12221ddddddddddaaaa");
  grid.push_back("aab13331DDDDDDDDDDaaaa");
  grid.push_back("aab13331DDDDDDDDDDaaaa");
  grid.push_back("aa.11111DDDDDDDDDDaaaa");
  grid.push_back("aaaaaaaaaaaaaaaaaaaaaa");


  /*
  grid.push_back("bbb666");
  grid.push_back(".655X5");
  grid.push_back("a65AA5");
  grid.push_back("a65AA5");
  grid.push_back("a65555");

  */

  cout << tv.findOrder(grid) << endl;

  return 0;
}
