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

/**
 * i が K を超えるのに何度2倍する必要があるか
 */
int calExp(int i, int K) {
    int cnt = 0;
    while (i < K) {
        cnt++;
        i = i * 2;
    }
    return cnt;
}

int main() {
    int N, K;
    cin >> N >> K;
    int maxExp = calExp(1, K);
    // DEBUG(maxExp);
    ll sumBunshi = 0;
    for (int i = N; i >= 1; i--) {
        int tmpCalExp = calExp(i, K);
        // DEBUG(tmpCalExp);
        ll bunshi = pow(2, maxExp - tmpCalExp);
        // DEBUG(bunshi);
        sumBunshi = sumBunshi + bunshi;
    }
    // DEBUG(sumBunshi);
    long double bunbo = N * pow(2, maxExp);
    // DEBUG(bunbo);
    long double result = sumBunshi / bunbo;
    cout << fixed << setprecision(12) << result << endl;
}
