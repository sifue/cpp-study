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
  int A[2][100] = {0};
  cin >> N;
  rep(i, N) {
    int a;
    cin >> a;
    A[0][i] = a;
  }
  rep(i, N) {
    int a;
    cin >> a;
    A[1][i] = a;
  }

  int maxCount = 0;
  rep(i, N) {
    int sum = 0;
    for(int first = 0; first <= i ; first++) {
      sum += A[0][first];
      // DEBUG(first);
    }
    
    // DEBUG(sum);
    for(int second = i; second < N ; second++) {
      sum += A[1][second];
      // DEBUG(second);
    }

    // DEBUG(sum);
    maxCount = max(sum, maxCount);
  }
  cout << maxCount << endl;
}
