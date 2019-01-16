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

int main() {
    int N;
    cin >> N;
    int t = 0;
    int x = 0;
    int y = 0;
    rep(i, N) {
        int ti, xi, yi;
        cin >> ti >> xi >> yi;
        int dt = ti - t;
        int dx = abs(xi - x);
        int dy = abs(yi - y);
        int d = dx + dy;
        if (d <= dt && d % 2 == dt % 2) { 
            t = ti;
            x = xi;
            y = yi;
        } else{
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
}
