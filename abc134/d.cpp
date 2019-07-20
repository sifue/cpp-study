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
    vector<int> a;
    cin >> N;
    rep(i, N) {
        int ai;
        cin >> ai;
        a.pb(ai);
    }

    int result[200000] = {0};
    // 後ろから確定させていく
    for (int j = N - 1; j >= 0; j--) {
        int i = j + 1;

        // i が 2分の1以上だとその数だけ
        if (i > N / 2) {
            result[j] = a[j];
        } else {
            // そうじゃないものはiの倍数を2倍、3倍と足し合わせる
            int sum = 0;
            for (int k = i * 2 ; k <= N; k = k + i) {
                sum += result[k - 1];
            }

            sum %= 2;
            if ((a[j] == 0 && sum == 0) || (a[j] == 1 && sum == 1)) {
                result[j] = 0;
            } else {
                result[j] = 1;
            }
        }
    }

    int M = 0;
    rep(i, N) {
        if (result[i] == 1) M++;
    }

    cout << M << endl;
    rep(i, N) {
        if (result[i] == 1) {
            cout << (i + 1) << endl;
        }
    }
}
