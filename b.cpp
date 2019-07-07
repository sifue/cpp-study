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
    vector<int> p;
    int N;
    cin >> N;
    rep(i, N) {
        int pi;
        cin >> pi;
        p.pb(pi);
    }
    int result = 0;
    for (int i = 1; i < (N - 1); i++) {
        int ord = 0;
        // cout << "------------" << endl;
        // DEBUG(i);
        // DEBUG(p[i-1]);
        // DEBUG(p[i]);
        // DEBUG(p[i+1]);
        if (p[i-1] > p[i]) ord++;
        if (p[i+1] > p[i]) ord++;
        if (ord == 1) result++;
        // DEBUG(result);
    }
    cout << result << endl;
}
