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

char rev(char animal) {
  if(animal == 'S') {
    return 'W';
  } else {
    return 'S';
  }
}

int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  char animals[100001]; // 最後のチェックのため一つ余裕持つ

  bool isOK = false;
  rep(p , 4) {

    // 4パターンしかないという前提で確かめていく
    if (p == 0) {
      animals[0] = 'S';
      animals[1] = 'S';
    } else if (p == 1) {
      animals[0] = 'S';
      animals[1] = 'W';
    } else if (p == 2) {
      animals[0] = 'W';
      animals[1] = 'W';
    } else if (p == 3) {
      animals[0] = 'W';
      animals[1] = 'S';
    }

    for (int i = 1; i <= N; i++) {
      if (i == N) { // 最後まで終わったらチェック
        if(animals[0] == animals[i]) { // 合致してOKの場合
          isOK = true;
        }
      } else { // 1 ~ N-1 まで
        if (animals[i] == 'S') {
          if (s[i] == 'o') {
            animals[i + 1] = animals[i - 1];
          } else {
            animals[i + 1] = rev(animals[i - 1]);
          }
        } else {
          if (s[i] == 'o') {
            animals[i + 1] = rev(animals[i - 1]);
          } else {
            animals[i + 1] = animals[i - 1];
          }
        }
      }
    }

    if (isOK) {
      string answer(animals, N);
      cout << answer << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
