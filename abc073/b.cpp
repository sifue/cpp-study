#include <iostream>
#include <map>
#include <set>
 
using namespace std;
 
#define P(s) cout << s << endl;
#define DEBUG(x) cout << #x << ": " << x << endl;
 
int main() {
  int n, l, r;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    sum = sum + (r - l) + 1;
 
  }
  cout << sum << endl;
}