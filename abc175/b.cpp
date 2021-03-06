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
    vector<int> L;
    rep(i, N) {
        int Li;
        cin >> Li;
        L.pb(Li);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if(L[i] != L[j] && L[i] != L[k] && L[j] != L[k]) {
                    vector<int> tri;
                    tri.pb(L[i]);
                    tri.pb(L[j]);
                    tri.pb(L[k]);
                    sort(all(tri));
                    if(tri[0] + tri[1] > tri[2]) count++;
                }
            }
        }
    }

    cout << count << endl;
}
