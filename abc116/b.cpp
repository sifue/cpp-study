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
int s;

int fun(int n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3 * n + 1;
    }
}

int main() {
    cin >> s;
    int ai = s;
    set<int> used;
    int count = 1;
    used.insert(ai);
    while (true) {
        count++;
        int newai = fun(ai);
        if (used.count(newai) == 0) {
            used.insert(newai);
            ai = newai;
        } else {
            cout << count << endl;
            exit(0);
        }
    }
}
