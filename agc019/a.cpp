#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

class Tea {
  public:
      long long size; // ml で保持
      long long price;
      long long price_per_size; // yen/l で保持
    bool operator<(const Tea& s) const;
};

bool Tea::operator<(const Tea& t) const
{
  return price_per_size < t.price_per_size; // リッター毎の価格でソート
}

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl;
#define MOD 1000000007

int main() {
  vector<Tea> teas;
  long long prices[4] = {250, 500, 1000, 2000};
  for (int i = 0; i < 4; i++) {
    Tea t;
    t.size = prices[i];
    cin >> t.price;
    t.price_per_size = t.price * 1000 / t.size;
    teas.push_back(t);
  }
  sort(teas.begin(), teas.end());

  long long N;
  cin >> N;
  N = N * 1000;

  bool is_full = false;
  int tryIndex = 0;
  long long totalPrice = 0;
  while(!is_full) {
    int trySize = teas[tryIndex].size;

    // DEBUG(tryIndex);
    // DEBUG(N);
    // DEBUG(trySize);
    // DEBUG(totalPrice);

    if (N >= trySize) {
      N = N - trySize;
      totalPrice = totalPrice + teas[tryIndex].price;
    } else {
      tryIndex++;
    }
    if (N == 0) {
      is_full = true;
    }
  }

  cout << totalPrice << endl;
}
