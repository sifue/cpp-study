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

int toInt(vector<int> i) {
  return i[0] * 1000 + i[1] * 100 + i[2] * 10 + i[3];
}

vector<int> toVec(int n) {
  vector<int> result;
  result.pb(n / 1000);
  result.pb((n / 100) % 10);
  result.pb((n / 10) % 10);
  result.pb(n % 10);
  return result;
}

vector<int> calc(vector<int> v) {
  sort(v.rbegin(), v.rend());
  int L = toInt(v);

  sort(v.begin(), v.end());
  int S = toInt(v);

  int N = L - S;
  return toVec(N);
}

int main() {
  int N;
  while (cin >> N) {
  if (N == 0) break;
    vector<int> input = toVec(N);

    if(input[0] == input[1] &&
      input[1] == input[2] &&
      input[2] == input[3] ) {
        cout << "NA" << endl;
    } else {
      int count = 0;
      while (toInt(input) != 6174) {
        count++;
        input = calc(input);
      }
      cout << count << endl;
    }
  }
}
