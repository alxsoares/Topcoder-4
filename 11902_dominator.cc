#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int kMaxNodes = 100;

int N = 0;
bool dominance[kMaxNodes][kMaxNodes];
bool adjacency[kMaxNodes][kMaxNodes];
bool visited[kMaxNodes];

void dfs(int n) {
  queue<int> q;
  memset(visited, false, sizeof(visited));
  q.push(0);
  visited[0] = true;
  while (!q.empty()) {
    int current_node = q.front();
    q.pop();
    for (int i = 0; i < N; ++i) {
      if (adjacency[current_node][i] && !visited[i] && i != n) {
	q.push(i);
	visited[i] = true;
	dominance[n][i] = false;
      }
    }
  }
}

void dfs0() {
  queue<int> q;
  memset(visited, false, sizeof(visited));
  q.push(0);
  visited[0] = true;
  while (!q.empty()) {
    int current_node = q.front();
    q.pop();
    for (int i = 1; i < N; ++i) {
      if (adjacency[current_node][i] && !visited[i]) {
	q.push(i);
	visited[i] = true;
	dominance[0][i] = true;
      }
    }
  }
}

void clean() {
  for (int i = 1; i < N; ++i)
    for (int j = 1; j < N; ++j)
    if (!dominance[0][i])
      dominance[j][i] = false;
}

void calculate_dominance() {
  memset(dominance, true, sizeof(dominance));
  for (int i = 1; i < N; ++i) {
    dominance[i][0] = false;
    dominance[0][i] = false;
  }
  dfs0();
  clean();
  for (int i = 1; i < N; ++i)
    dfs(i); // excluding node i
}

void print_separator() {
  printf("+");
  int n = 2*N-1;
  for (int i = 0; i < n; ++i) {
    printf("-");
  }
  printf("+\n");
}

void print_dominance_matrix() {
  for (int i = 0; i < N; ++i) {
    print_separator();
    for (int j = 0; j < N; ++j) {
      printf("|%c", dominance[i][j]? 'Y': 'N');
    }
    printf("|\n");
  }
  print_separator();
}

int main() {
  int TC = 0;
  cin >> TC;
  for (int tc = 1; tc <= TC; ++tc) {
    cin >> N;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
	cin >> adjacency[i][j];
    calculate_dominance();
    printf("Case %d:\n", tc);
    print_dominance_matrix();
  }
  return 0;
}
