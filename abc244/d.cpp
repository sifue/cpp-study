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
    string S;
    string T;
    cin >> S[0] >> S[1] >> S[2];
    cin >> T[0] >> T[1] >> T[2];
    
    string res = "No";
    if ((S[0] == T[0] && S[1] == T[1] && S[2] == T[2]) ||
        (S[0] == T[1] && S[1] == T[2] && S[2] == T[0]) ||
        (S[0] == T[2] && S[1] == T[0] && S[2] == T[1])
     ) {
        res = "Yes";
    }

    cout << res << endl;
}
