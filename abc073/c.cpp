#include <iostream>
#include <map>
#include <set>

using namespace std;

#define P(s) cout << s << endl;
#define DEBUG(x) cout << #x << ": " << x << endl;

int main() {
  int n, a;
  cin >> n;
  set<int> nums;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (nums.count(a) == 0) {
      nums.insert(a);
    } else {
      nums.erase(a);
    }
  }
  cout << nums.size() << endl;
}
