#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end()) // ちゃんとユニークな配列にする。連続した値を除去して切り出す。
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

int main() {
  // ただの枝刈全探索
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  int max_ai, max_bj, max_ci, max_dj;
  max_ai = F / A;
  max_bj = F / B;
  max_ci = (E * F / 100) / C;
  max_dj = (E * F / 100) / D;

  double max_cons = 0.0;
  int result_water = 0;
  int result_sugar = 0;

  repto (ai, max_ai) {
    if((A * 100 * ai) > F) break;
    repto (bj, max_bj) {
      int water = (A * 100 * ai) + (B * 100 * bj);
      if(water > F) break;
      repto (ci, max_ci) {
        if((C * ci) > (water / 100 * E))  break;
        repto (dj, max_dj) {
          int sugar = C * ci + D * dj;
          if((water + sugar) <= F &&  sugar <= (water / 100 * E)) {
            double cons = (double)sugar / (double)(water + sugar);
            if (cons > max_cons) {
              max_cons = cons;
              result_water = water;
              result_sugar = sugar;
            }
          }
        }
      }
    }
  }

  cout << (result_water + result_sugar) << " " << result_sugar << endl;
}
