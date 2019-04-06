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
#define INF 10000000000L
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

__attribute__((constructor)) void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    int len[3];
    int K;
    cin >> len[0] >> len[1] >> len[2] >> K;
    vector<ll> A[3];
    rep(i, 3) {
        int inputLength = len[i];
        // DEBUG(inputLength);
        for (int j = 0; j < inputLength; j++) {
            // DEBUG(j);
            ll a;
            cin >> a;
            A[i].pb(a);
        }
    }

    rep(i, 3) {
        sort(A[i].rbegin(), A[i].rend());
    }

    // rep(i, A[0].size()) DEBUG(A[0][i]);
    // rep(i, A[1].size()) DEBUG(A[1][i]);
    // rep(i, A[2].size()) DEBUG(A[2][i]);

    vector<ll> AB;

    rep(i, A[0].size()) {
        rep(j, A[1].size()) {
            AB.pb(A[0][i] + A[1][j]);
        }
    }
    sort(AB.rbegin(), AB.rend());
    
    // rep(i, AB.size()) DEBUG(AB[i]);

    priority_queue<ll> que;
    for (int i = 0; i < AB.size() && i <= K; i++) {
        for (int j = 0; j < A[2].size() && j <= K; j++) {
            que.push(AB[i] + A[2][j]);
        }
    }

    int count = 1;
    while (!que.empty() && count <= K) {
      cout << que.top() << endl;
      que.pop();
      count++;
    }

}
