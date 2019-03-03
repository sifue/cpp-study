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

int N, A, B, C;
int cost = INF;
vector<int> l;


void dfs(int i, int curCost, int curA, int curB, int curC) {
    if (curA > 0 && curB > 0 && curC > 0) {
        int totalCost = curCost;
        totalCost += abs(A - curA);
        totalCost += abs(B - curB);
        totalCost += abs(C - curC);
        cost = min (totalCost, cost);
    }

    if (i >= N) return;

    dfs(i + 1, curA > 0 ? curCost + 10 : curCost, curA + l[i], curB, curC);
    dfs(i + 1, curB > 0 ? curCost + 10 : curCost, curA, curB + l[i], curC);
    dfs(i + 1, curC > 0 ? curCost + 10 : curCost, curA, curB, curC + l[i]);
    dfs(i + 1, curCost, curA, curB, curC); // 使わない
}

int main() {
    cin >> N >> A >> B >> C;

    rep(i, N) {
        int li;
        cin >> li;
        l.pb(li);
    }

    dfs(0,0,0,0,0);

    cout << cost << endl;
}
