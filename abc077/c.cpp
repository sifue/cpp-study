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
  int N;
  int size;
  cin >> N;
  vector<int> A;
  rep(i, N) {
    cin >> size;
    A.pb(size);
  }
  sort(all(A));

  vector<int> B;
    rep(i, N) {
    cin >> size;
    B.pb(size);
  }
  sort(all(B));

  vector<int> C;
  rep(i, N) {
    cin >> size;
    C.pb(size);
  }
  sort(all(C));

  int result = 0;
  rep(i, N) {
    // DEBUG(i);
    int b = B[i];
    decltype(A)::iterator ita = lower_bound(A.begin(), A.end(), b);
    int countA = ita - A.begin();
    // DEBUG(countA);
    decltype(C)::iterator itc = upper_bound(C.begin(), C.end(), b);
    int countC = N - (itc - C.begin());
    // DEBUG(countC);
    result = result + (countA * countC);
  }
  cout << result << endl;
}
