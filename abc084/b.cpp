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
  int A, B;
  string S;
  cin >> A >> B >> S;
  int lengthOfStr = 0;
  lengthOfStr = A + B + 1;
  bool isPostalCode = true;

  if (S.length() != lengthOfStr) isPostalCode = false;
  if (isPostalCode) {
    rep(i, lengthOfStr) {
      if(i == A) {
        if(S[i] != '-') isPostalCode = false;
      } else {
        if(!isdigit(S[i])) isPostalCode = false;
      }
    }
  }

  if(isPostalCode) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
