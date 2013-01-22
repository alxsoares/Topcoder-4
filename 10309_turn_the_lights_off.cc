#include <cstdio>
#include <bitset>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;


bool lights[10][10];
bool now_lights[10][10];

const int xbuttom[5] = {-1, 0, 1, 0, 0};
const int ybuttom[5] = {0, 0, 0, 1, -1};

int ones_count(int k) {
  int r = 0;
  do {
    if (k&1) ++r;
  } while (k >>= 1);
  return r;
}

void press_buttom(int i, int j) {
  for (int k = 0; k < 5; ++k) {
    int x = xbuttom[k];
    int y = ybuttom[k];
    x += i;
    y += j;
    if (0 <= x && x < 10 && 0 <= y && y < 10) {
      now_lights[x][y] = !now_lights[x][y];
    }
  }
}

void press_first_row(int k) {
    for (int i = 0; i < 10; ++i) {
      int j = (1 << (10 - i - 1));
      if (k & j) {
        press_buttom(0, i);
      }
    }
}

bool all_off() {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (now_lights[i][j]) return false;
      }
    }
    return true;
  }





int chase(int k) {
  int r = 0;

  memcpy(now_lights, lights, sizeof(lights));
  //  printk(k);
  //  print(now_lights);
  press_first_row(k);
  //  print(now_lights);
  for (int i = 1; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (now_lights[i-1][j]) {
        press_buttom(i, j);
        ++r;
        //    print(now_lights);
      }
    }
  }
  if (!all_off()) return 101;
  return r;
}

int main() {
  string name;
  
  while (cin >> name) {
    if (name.compare("end") == 0) break;
    int r = 0;
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        char c; cin >> c;
        lights[i][j] = (c == 'O');
      }
    }
    int n = pow(2, 10);
    int rmin = 101;
    for (int k = 0; k < n; ++k) {
      int r = chase(k);
      r += ones_count(k);
      if (r < rmin) rmin = r;
    }

    printf("%s %d\n", name.c_str(), (rmin == 101)? -1: rmin);
  }
  
  return 0;
}
