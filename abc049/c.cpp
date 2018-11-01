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
   string S;
   cin >> S;
   int ptr = S.length() - 1; // 最後の文字位置

   vector<string> pattens;
   pattens.pb("dream");
   pattens.pb("dreamer");
   pattens.pb("erase");
   pattens.pb("eraser");

   bool isMatch = true;
   while (ptr >= 0 || isMatch) {
       isMatch = false;
       // DEBUG(ptr);

       rep(i, 4) {
         string p = pattens[i];
         // DEBUG(p);
         int len = p.length();
         bool isSame = true;
         rep (j, len) {
            if (p[len - 1 - j] != S[ptr - j]) {
                isSame = false;
            }
         }
         if (isSame) {
             isMatch = true;
             ptr = ptr - len;
             break;
         }
       }

       if (!isMatch) break;
   }

   if(ptr < 0) {
     cout << "YES" << endl;
    } else {
     cout << "NO" << endl;
    }
}
