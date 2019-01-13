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
    string answer = "keyence";
    string S;
    cin >> S;
    int length = S.size();
    int cutLength = length - answer.size();
    bool result = false;

    // DEBUG(cutLength);

    if (cutLength > 0) {
        for (int s = 0; s <= length - cutLength; s++) { // 全てのカットポジションsについて
            // 部分文字列を作る
            // DEBUG(s);
            vector<char> candidate;
            for(int i = 0; i < s; i++) { // カットした前側
                // DEBUG(S[i]);
                candidate.pb(S[i]);
            }

            for(int i = s + cutLength; i < length; i++) { // カットした後ろ側
                // DEBUG(S[i]);
                candidate.pb(S[i]);
            }

            bool tmpResult = true;
            rep(i, answer.size()) {
                // DEBUG(candidate[i]);
                // DEBUG(answer[i]);
                if (candidate[i] != answer[i]) tmpResult = false;
            }
            // DEBUG(tmpResult);
            if (tmpResult) result = true;
        }
        cout << (result ? "YES" : "NO") << endl;
    } else {
        cout << (answer == S ? "YES" : "NO") << endl;
    }
}
