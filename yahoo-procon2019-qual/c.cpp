#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

__attribute__((constructor)) void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    ll K, A, B;
    cin >> K >> A >> B;
    ll result = 0L;
    if (B <= A + 2) {
        result = K + 1;
    } else {
        ll has = 1;
        ll lest = K;

        while (lest > 0) {
            // DEBUG(has);
            // DEBUG(lest);
            if (has < A) { // 足りないから叩いて作るとき
                ll need = A - has;
                if (lest < need + 2) {
                    has += lest;
                    lest = 0;
                    break;
                } else {
                    lest -= need;
                    has += need;
                    has -= A;
                    has += B;
                    lest -= 2;
                }
            } else { // 足りてるからクッキーを変換するとき
                if (lest < 2) {
                    has += lest;
                    lest = 0;
                    break;
                } else {
                    has -= A;
                    has += B;
                    lest -= 2;
                }
            }
        }
        result += has;
    }
    cout << result << endl;
}
