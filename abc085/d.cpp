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
  int N, H;
  cin >> N >> H;
  vector<int> a;
  vector<int> b;
  priority_queue<int> bPQ;
  rep(i, N) {
    int ai, bi;
    cin >> ai >> bi;
    a.pb(ai);
    b.pb(bi);
    bPQ.push(bi);
  }

  // 最大Aを求める、一番効率の良い切りを取得
  int maxA = 0;
  rep(i, N) {
    maxA = max(maxA, a[i]);
  }

  // 全部投げフェーズ (ただし最大A)
  int throwAllTry = 0;
  int count = 0;
  
  while(!bPQ.empty() && throwAllTry < H) {
    int attack = bPQ.top();
    bPQ.pop();
    if(attack >= maxA) { // 切るより効率が良いやつだけ投げる
      throwAllTry += attack;
      count++;
    }
  }

  // DEBUG(throwAllTry);
  // DEBUG(count);

  if(throwAllTry >= H) {
    cout << count << endl;
    return 0;
  }

  // 投げずに最大でカウント (ただし最後は投げる)
  int minCount = INF;
  int totalDamage = 0;
  int countNotThrow = 0;

  rep(i, N) {
    if(b[i] >= maxA) { // 切るより効率がいいやつだけ投げる
      totalDamage += b[i];
      countNotThrow++;
    }
  }

  while (totalDamage < H) {
    totalDamage += maxA;
    countNotThrow++; 
  }

  cout << countNotThrow << endl;
}
