#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TheBrickTowerMediumDivTwo {
public:
  vector<int> find(vector<int> heights);
};

vector<int> h;

bool cmp(int a, int b) {
  return h[a] < h[b];
}

vector<int> TheBrickTowerMediumDivTwo::find(vector<int> heights) {
  size_t n = heights.size();
  h = heights;
  vector<int> idxs; 
  for (size_t i = 0; i < n; ++i) idxs.push_back(i);
  sort(idxs.begin(), idxs.end(), cmp); // minimal distance module lexicography
  
  for (size_t i = 0; i < n; ++i) {
    int idx0 = idxs[i];
    for (size_t j = i; j < n; ++j) {
      if (idxs[j] < idx0 and idxs[j] >= i and (heights[idxs[j]] <= heights[idx0] or i == 0)) {
	cout << "Remplace for " << idx0 << " is " << idxs[j] 
	     << " with heights " << heights[idxs[j]]
	     << " vs " << heights[idx0]
	     << ", is principe? " << ((i==0)?"yes":"no")
	     << endl;
	
	reverse(idxs.begin()+i, idxs.begin()+j+1);
	for (size_t i = 0; i < idxs.size(); ++i) cout << idxs[i] << " ";
	cout << endl;
	break;
      }
    }
  }
  
  return idxs;
}

int main() {
  TheBrickTowerMediumDivTwo o;
  //  vector<int> heights = {13, 32, 38, 25, 43, 47, 6};
  //  vector<int> heights = {4, 7, 5};
  //  vector<int> heights = {4, 4, 4, 4, 4, 4, 4};
  vector<int> heights = {2, 3, 3, 2};
  vector <int> res = o.find(heights);
  cout << "Result:" << endl;
  for (size_t i = 0; i < heights.size(); ++i) cout << res[i] << " ";
  cout << endl;
  return 0;
}
