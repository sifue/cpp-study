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
  double max_cons = 0.0;
  int result_water = 0;
  int result_sugar = 0;

  max_ai = F / (A * 100);
  // DEBUG(max_ai);
  repto (ai, max_ai) {
    int water_a = (A * 100 * ai);
    if(water_a > F) continue;
    max_bj = (F - water_a) / (B * 100);
    // DEBUG(max_bj);
    repto (bj, max_bj) {
      int water = (A * 100 * ai) + (B * 100 * bj);
      if(water > F) continue;
      int max_sugar = water * E / 100;
      max_ci = max_sugar / C;
      // DEBUG(max_ci);
      repto (ci, max_ci) {
        int sugar_c = C * ci;
        if(sugar_c > max_sugar) continue;
        max_dj = (max_sugar - sugar_c) / D;
        // DEBUG(max_dj);
        repto (dj, max_dj) {
          int sugar = C * ci + D * dj;
          if((water + sugar) <= F &&  sugar <= (water / 100 * E)) {
            double cons = (double)sugar / (double)(water + sugar);
            // DEBUG(ai);
            // DEBUG(bj);
            // DEBUG(ci);
            // DEBUG(dj);
            // DEBUG(cons);
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
