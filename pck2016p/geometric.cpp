#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  set<set<int> > surfaces;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    set<int> surface;
    int a, b, c;
    cin >> a >> b >> c;
    surface.insert(a);
    surface.insert(b);
    surface.insert(c);
    surfaces.insert(surface);
  }
  cout << (n - surfaces.size()) << endl;
}
