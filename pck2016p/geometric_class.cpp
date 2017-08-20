#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

class Surface {
  public:
      int a;
      int b;
      int c;
    bool operator<(const Surface& s) const;
};

bool Surface::operator<(const Surface& s) const
{
  std::vector<int> v_1;
  v_1.push_back(a);
  v_1.push_back(b);
  v_1.push_back(c);
  std::vector<int> v_2;
  v_2.push_back(s.a);
  v_2.push_back(s.b);
  v_2.push_back(s.c);
  return v_1 < v_2;
}

using namespace std;

int main() {
  set<Surface> surfaces;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    Surface surface;
    int a, b, c;
    cin >> a >> b >> c;
    surface.a = a;
    surface.b = b;
    surface.c = c;
    surfaces.insert(surface);
  }
  cout << (n - surfaces.size()) << endl;
}
