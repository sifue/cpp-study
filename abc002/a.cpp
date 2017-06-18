#include <cfenv>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  if (x > y) {
    cout << x << endl;
  } else {
    cout << y << endl;
  }
}
