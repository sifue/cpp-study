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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int revCnt = 0;
    int result = 0;
    int maxResult = 0;
    char pre = '.';
    int maxL = -1;
    int tmpL = 0;
    int maxR = -1;

    rep(j, K) {
        // 初期化
        revCnt = 0;
        result = 0;
        maxResult = 0;
        pre = '.';
        maxL = -1;
        tmpL = 0;
        maxR = -1;

        rep(i, N) {

            if (S[i] != pre && S[i] == '0') { // 前と違い0
                result = revCnt + 1;
                revCnt = 0;
                tmpL = i;
            } else if (S[i] != pre && S[i] == '1') { // 前と違い1
                revCnt = 1;
                result++;
            } else if (S[i] == pre && S[i] == '0') { // 前と一緒0
                revCnt = 0;
                result++;
            } else if (S[i] == pre && S[i] == '1') { // 前と一緒1
                revCnt++;
                result++;
            }
            maxResult = max(maxResult, result);

            if (maxResult == result) {
                maxL = tmpL;
                maxR = i;
            }

            // DEBUG(i);
            // DEBUG(revCnt);
            // DEBUG(S[i]);
            // DEBUG(result);
            // DEBUG(maxL);
            // DEBUG(maxR);
            // cout << "------------" << endl;

            pre = S[i];
        }
        // 最大になるところを塗りつぶして次へ
        rep(i, N) {
            if(maxL <= i && i <= maxR) {
                S[i] = '1';
            }
        }

        if (maxResult == N) { // 最大なら終了
            break;
        }
    }
    cout << maxResult << endl;
}
