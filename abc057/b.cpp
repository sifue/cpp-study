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
  ll N, M;
  cin >> N >> M;
  vector<P> students;
  vector<P> checkPoints;

  rep(i , N) {
    ll a, b;
    cin >> a >> b;
    students.pb(make_pair(a, b));
  }

  rep(j , M) {
    ll c, d;
    cin >> c >> d;
    checkPoints.pb(make_pair(c, d));
  }

  rep(i, N) {
    ll minLength = INF;
    ll minIndex = -1;

    rep(j, M) {
      ll length = abs(students[i]._1 - checkPoints[j]._1) + abs(students[i]._2 - checkPoints[j]._2);
      if (length < minLength) {
        minLength = length;
        minIndex = j;
      }
    }

    cout << (minIndex + 1) << endl;
  }

}
