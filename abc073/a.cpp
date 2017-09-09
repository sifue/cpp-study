#include <iostream>
#include <map>
#include <set>

using namespace std;

#define P(s) cout << s << endl;
#define DEBUG(x) cout << #x << ": " << x << endl;

int main() {
  int n;
  cin >> n;
  bool has_nine = false;
  if ( n / 90 == 1) {
    has_nine = true;
  }

  if ( (n % 10) == 9 ) {
    has_nine = true;
  }

  if (has_nine) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
