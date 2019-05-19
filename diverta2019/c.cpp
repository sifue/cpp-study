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
    int N;
    ll AB = 0;
    ll fB = 0;
    ll lA = 0;
    ll fBlA = 0;

    cin >> N;
    rep(n, N) {
        string s;
        cin >> s;
        char firstMatch = '.';
        char lastMatch = '.';
        int cntA = 0;
        int cntB = 0;
        int cntAB = 0;

        rep(i, s.size()) {
            if(s[i] == 'A' || s[i] == 'B') {
                if (firstMatch == '.') {
                    firstMatch = s[i];
                }
                lastMatch = s[i];
            }
            if(s[i] == 'A') cntA++;
            if(s[i] == 'B') cntB++;

            if (cntA > 0 && s[i] == 'B') {
                cntA--;
                cntB--;
                cntAB++;
            }
        }
        //cout << "------------" << endl;
        //DEBUG(s);
        //DEBUG(cntAB);
        //cout << "------------" << endl;
        AB += cntAB;

        if (firstMatch == 'B' && lastMatch == 'A') {
            fBlA++;
        } else if (firstMatch == 'B' && lastMatch != 'A') {
            fB++;
        } else if (firstMatch != 'B' && lastMatch == 'A') {
            lA++;
        }
    }

    ll pair = min(fB, lA);
    ll pairDiff = abs(fB - lA);
    ll add = min(pairDiff, fBlA);
    ll result = AB + pair + add;

    cout << result << endl;
}
