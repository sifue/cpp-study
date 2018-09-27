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
   int N;
   cin >> N;
   vector<int> T;
   rep(i, N) {
       int Ti;
       cin >> Ti;
       T.pb(Ti);
   }

   int M;
   cin >> M;
   rep(i, M) {
       int p, x;
       cin >> p >> x;

       int sum = 0;
       rep (i, N) {
         if ((p - 1) == i) {
             sum += x;
         } else {
             sum += T[i];
         }
       }
       cout << sum << endl;
   }



}
