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

int A[100001];
int B[100001];
int C[100001];
int diffs[100001]; // index => diff
vector<P> diffIndexes; // 昇順 (diff, index)
ll sumA = 0;
ll sumB = 0;

int main() {
    int N;
    cin >> N;
    rep(i, N) {
        ll ai;
        cin >> ai;
        A[i] = ai;
        C[i] = ai;
        sumA += ai;
    }
    rep(i, N) {
        ll bi;
        cin >> bi;
        B[i] = bi;
        sumB += bi;
        ll diff = A[i] - B[i]; // diff Bを基準にしたときのA
        diffs[i] = diff;
        diffIndexes.pb(make_pair(diff, i));
    }

    if (sumA < sumB) {
        cout << -1 << endl;
        return 0;
    }

    // ソート
    sort(all(diffIndexes));

    int plusIndex = diffIndexes.size() - 1;
    int minusIndex = 0;
    //DEBUG(plusIndex);
    //DEBUG(minusIndex);
    //rep (i, N) {
    //    DEBUG(diffIndexes[i]._1);
    //    DEBUG(diffIndexes[i]._2);
    //}
    //DEBUG("----------");

    while (diffs[diffIndexes[minusIndex]._2] < 0) { // minusIndexの場所のdiffが0以上で終了
        int currentMinIndex = diffIndexes[minusIndex]._2;
        int currentMaxIndex = diffIndexes[plusIndex]._2;
        int restLack = B[currentMinIndex] - C[currentMinIndex] ;
        int restExtra = C[currentMaxIndex] - B[currentMaxIndex];
        //DEBUG(plusIndex);
        //DEBUG(minusIndex);
        //DEBUG(currentMinIndex);
        //DEBUG(currentMaxIndex);
        //DEBUG(restLack);
        //DEBUG(restExtra);
        //DEBUG("----------");

        if (restLack > restExtra) {
            C[currentMinIndex] += restExtra;
            C[currentMaxIndex] -= restExtra;
            plusIndex--;
        } else if (restExtra > restLack) {
            C[currentMinIndex] += restLack;
            C[currentMaxIndex] -= restLack;
            minusIndex++;
        } else if (restLack == restExtra) {
            C[currentMinIndex] += restLack;
            C[currentMaxIndex] -= restExtra;
            plusIndex--;
            minusIndex++;
        }
    }

    int result = 0;
    rep (i, N) {
        if (A[i] != C[i]) result++;
    }
    cout << result << endl;
}
