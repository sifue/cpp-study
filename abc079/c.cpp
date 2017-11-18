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

int ctoi(char c){
  switch(c){
      case '0': return 0;
      case '1': return 1;
      case '2': return 2;
      case '3': return 3;
      case '4': return 4;
      case '5': return 5;
      case '6': return 6;
      case '7': return 7;
      case '8': return 8;
      case '9': return 9;
      default : return -1;
  }
}

void dfs(int index, int sum, vector<char> ops, vector<char> &D) {
  if(index == 3 && sum == 7) {
    cout << D[0] << ops[0] << D[1] << ops[1] << D[2] << ops[2] << D[3] << "=7" << endl;
    exit(0);
  }

  if(index == 3) {
    return;
  }

  index++;
  int plusSum = sum + ctoi(D[index]);
  vector<char> plusOps = ops;
  plusOps.pb('+');
  dfs(index, plusSum, plusOps, D);

  int minusSum = sum - ctoi(D[index]);
  vector<char> minusOps = ops;
  minusOps.pb('-');
  dfs(index, minusSum, minusOps, D);
}

int main() {
  string digits;
  cin >> digits;
  vector<char> ops;
  vector<char> D;
  rep(i, 4) {
    D.pb(digits[i]);
  }
  dfs(0, ctoi(D[0]), ops, D);
}
