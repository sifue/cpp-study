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

long getDigit(long num){
  long digit = 0;
  while (num != 0){
      num /= 10;
      digit++;
  }
  return digit;
}

int main() {
  long N;
  cin >> N;
  double r = sqrt(N);
  long minResult = INF;

  // r から試し割
  long divider = r;
  while (divider > 0) {
    if (N % divider == 0) {
      long result = max(getDigit(divider), getDigit(N / divider));
      minResult = min(result, minResult);
      // DEBUG(divider);
      // DEBUG(minResult);
    }
    divider--;
  }

  cout << minResult << endl;
}
