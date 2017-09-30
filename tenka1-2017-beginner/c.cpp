#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define repi(i, n) for(int i = 1; i < (n); i++)
#define reptoi(i, n) for(int i = 1; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end()) // ちゃんとユニークな配列にする。連続した値を除去して切り出す。
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

int main() {
  int N;
  cin >> N;
  int max = 3500;
  int from = (1 + N) / 4;
  if (from < 1) {
    from = 1;
  }

  for (int h = max; h >= from ; h--) {
    for (int n = max; n >= from ; n--) {
      for (int w = max; w >= from ; w--) {
        ll leftLE = n * w;
        ll leftRE = 4 * h - N;
        ll leftE = leftLE * leftRE;

        ll rightLE = n + w;
        ll rightRE = N * h;
        ll rightE = rightLE * rightRE;

        if (leftE == rightE) {
          cout << h << " " << n << " " << w << " " << endl;
          return 0;
        }
      }
    }
  }
}
