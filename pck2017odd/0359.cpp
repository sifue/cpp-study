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
  int X;
  cin >> X;
  int dayOfWeek = X % 7;

  if (dayOfWeek == 0) cout << "thu" << endl;
  if (dayOfWeek == 1) cout << "fri" << endl;
  if (dayOfWeek == 2) cout << "sat" << endl;
  if (dayOfWeek == 3) cout << "sun" << endl;
  if (dayOfWeek == 4) cout << "mon" << endl;
  if (dayOfWeek == 5) cout << "tue" << endl;
  if (dayOfWeek == 6) cout << "wed" << endl;
  
}
