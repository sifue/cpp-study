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

ll bill[3] = { 10000LL, 5000LL, 1000LL };
int N;
ll Y;

void dfs(int index, int rest, int x, int y, ll sum) {
    if (index == 2) {
        sum += bill[index] * rest;
        if (sum == Y) {
            cout << x << " " << y << " " << rest << endl;
            exit(0);
        }
        return;
    }

    repto (i, rest) {
        if (index == 0) dfs(index + 1, rest - i, x + i, y, sum + bill[index] * i);
        if (index == 1) dfs(index + 1, rest - i, x, y + i, sum + bill[index] * i);
    }
}

int main() {
    cin >> N >> Y;
    dfs(0, N, 0, 0, 0LL);
    cout << "-1 -1 -1" << endl;
}
