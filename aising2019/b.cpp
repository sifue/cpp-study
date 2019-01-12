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

__attribute__((constructor))
void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> P1;
    vector<int> P2;
    vector<int> P3;
    rep(i, N) {
        int pi;
        cin >> pi;
        if (A >= pi) {
            P1.pb(pi);
        } else if (A < pi && B >= pi) {
            P2.pb(pi);
        } else {
            P3.pb(pi);
        }
    }
    int result = min(P1.size(), min(P2.size(), P3.size()));
    cout << result << endl;
}
