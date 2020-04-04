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

__attribute__((constructor))
void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

ll limitLL = 3234566667;
priority_queue<ll, vector<ll>, greater<ll>> que;

void dfs(ll current) {
    if(current > limitLL) return;
    que.push(current);
    int lastDidit = current % 10;
    ll newLL = current * 10 + lastDidit;
    dfs(newLL);

    if (lastDidit > 0) {
        dfs(newLL - 1);
    }

    if (lastDidit < 9) {
        dfs(newLL + 1);
    }
}

int main() {
    int K;
    cin >> K;
    for (int i = 1; i <= 9; i++)
    {
        dfs(i);
    }

    vector<ll> LL;
    while (!que.empty()) {
        LL.pb(que.top());
        que.pop();
    }
    cout << LL[K - 1] << endl;
}
