#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end()) // ユニークなvectorにする。連続した値を除去して切り出す。
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int main() {
  int N;
  cin >> N;

  vector<P> reds;
  vector<P> blues;

  rep(i, N) {
    int ai, bi;
    cin >> ai >> bi;
    reds.pb(make_pair(ai, bi));
  }
  sort(reds.rbegin(), reds.rend());

  rep(i, N) {
    int ci, di;
    cin >> ci >> di;
    blues.pb(make_pair(ci, di));
  }
  sort(blues.rbegin(), blues.rend());

  // DEBUG("--RED--");
  // for_each(reds.begin(), reds.end(), [](P p) {
  //   cout << "(" << p._1 << ":"  << p._2 << ")" << endl;
  // });

  // DEBUG("--BLUE--");
  // for_each(blues.begin(), blues.end(), [](P p) {
  //   cout << "(" << p._1 << ":"  << p._2 << ")" << endl;
  // });

  // 青の一番でかいものから貪欲法でペア作り
  int result = 0;
  set<P> selectedRed;

  for(int i = 0; i < blues.size(); i++) {
    for(int j = 0; j < reds.size(); j++) {
      P blue = blues[i];
      P red = reds[j];
      // DEBUG(blue._1);
      // DEBUG(blue._2);
      // DEBUG(red._1);
      // DEBUG(red._2);

      // 赤未選択かつ条件満たす
      if (selectedRed.count(red) == 0 && red._1 < blue._1 && red._2 < blue._2) { 
        result++;
        // DEBUG(result);
        // 見つかったら
        i++; // blue は次へ
        j = -1; // red は最初から 最後にインクリメントされるので -1
        selectedRed.insert(red); // 選択済みに追加
      }
      // DEBUG("-----");
    }
  }

  cout << result << endl;
}
