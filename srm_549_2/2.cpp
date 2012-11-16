#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

vector <int> tradius;
vector <int> bradius;

int angle(int height, int radius) {
  return atan((double)height/(double)radius);
};
bool isWizard(int th, int tr, int bh, int br) {
  bool result = true;
  if (br == 0) { 
    result &= false;
  }
  double bh1 = (double)(tr)*(double)bh/(double)br;
  if (br <= tr) {
    result &= false;
  }
  if (bh1 >= (double)th) {
    result &= false;
  }
  return result;
};
bool tcomp(int i, int j) {
  return tradius[i] < tradius[j];
};
bool bcomp(int i, int j) {
  return bradius[i] < bradius[j];
};
void print(int i) {
    cout << i << endl;
}


class PointyWozardHats {
public:
int getNumHats(vector<int> topHeight, vector<int> topRadius, 
	       vector<int> bottomHeight, vector<int> bottomRadius);
};

int PointyWozardHats::getNumHats(vector<int> topHeight, 
				 vector<int> topRadius, 
				 vector<int> bottomHeight, 
				 vector<int> bottomRadius) {
  int nt = topHeight.size();
  int nb = bottomHeight.size();
  
  tradius = topRadius;
  bradius = bottomRadius;
  
  vector<int> ts;
  vector<int> bs;
  
  for (int i = 0; i < nt; i++)  ts.push_back(i);
  for (int i = 0; i < nb; i++)  bs.push_back(i);
  
  //  sort(ts.begin(), ts.end(), tcomp);
  //  sort(bs.begin(), bs.end(), bcomp);
  //  reverse(ts.begin(), ts.end());

  int max_result = 0;
  int *usedb = new int[nb];
  int *usedt = new int[nt];

  do {
    do {      
      int result = 0;
      
      memset(usedb, sizeof(usedb), 0);
      memset(usedt, sizeof(usedt), 0);
      
      for (int i = 0; i < nt; ++i) {
	for (int j = 0; j < nb; ++j) {

	  if (!usedb[bs[j]] 
	      && !usedt[ts[i]]
	      && isWizard(topHeight[ts[i]], topRadius[ts[i]], 
			  bottomHeight[bs[j]], bottomRadius[bs[j]])) {
	    ++result;
	    usedb[bs[j]] = 1;
	    usedt[ts[i]] = 1;
	  }
	}
      }
      if (result > max_result) max_result = result;
    } while (next_permutation(ts.begin(), ts.end()));
  } while (next_permutation(bs.begin(), bs.end()));


  delete[] usedb;
  delete[] usedt;

  return max_result;
}

int main() {
  
  PointyWozardHats pwh;

  /*  
      int th[] = {123,214,232,323,342,343};
  int tr[] = {123,123,232,123,323,434};
  int bh[] = {545,322,123,545,777,999};
  int br[] = {323,443,123,656,767,888};
  */

  int th[] = {30};
  int tr[] = {3};
  int bh[] = {3};
  int br[] = {30};
  vector<int> thv(th, th+1);
  vector<int> trv(tr, tr+1);
  vector<int> bhv(bh, bh+1);
  vector<int> brv(br, br+1);
  
  cout << pwh.getNumHats(thv, trv, bhv, brv) << endl;

  return 0;
}
