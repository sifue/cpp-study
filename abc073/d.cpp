#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define P(s) cout << s << endl;
#define DEBUG(x) cout << #x << ": " << x << endl;

int Cs[19901][19901] = {};

int main() {
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> rs;
  for (int i = 0; i < r; i++) {
    int r;
    cin >> r;
    rs.push_back(r);
  }
  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B>> C;
    Cs[A][B] = C;
    Cs[B][A] = C;
  }
  cout << nums.size() << endl;
}
