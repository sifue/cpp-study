#include <cfenv>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;

  int a, b, c, d;
  a = xb - xa;
  b = yb - ya;
  c = xc - xa;
  d = yc - ya;

  int rect = abs((a * d) - (b * c));
  double s = rect / 2.0;

  cout << fixed << setprecision(1) << s << endl;
}
