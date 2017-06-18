#include <complex>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <class T> bool operator<(const complex<T> &a, const complex<T> &b) {
  return a.real() == b.real() ? a.imag() < b.imag() : a.real() < b.real();
}

typedef complex<double> P;
#define X real()
#define Y imag()

double dot(P a, P b) { return (a * conj(b)).X; }

double cross(P a, P b) { return (a * conj(b)).Y; }

int main() {
  cout << "hello!" << endl;
  return 0;
}
