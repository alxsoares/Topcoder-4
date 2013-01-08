#include <iostream>
#include <random>
#include <cmath>

using namespace std;

int main() {
  int N = 1000;
  double s = 0;
  
  default_random_engine generator;
  uniform_real_distribution<double> distribution(0.0, 1.0);

  for (int i = 0; i < N; ++i) {
    double u = distribution(generator);
    double v = -log(1.0-u*(1.0-exp(-0.05)));
    s += v;
  }

  cout << s/N << endl;

  return 0;
}
