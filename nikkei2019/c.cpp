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

struct Dish {
    int i;
    ll a;
    ll b;
    bool operator<( const Dish& right ) const {
            return (a+b) < (right.a + right.b);
    }
};

__attribute__((constructor)) void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    int N;
    cin >> N;
    priority_queue<Dish> que;
    rep(i, N) {
        int A, B;
        cin >> A >> B;

        Dish d;
        d.i = i;
        d.a = A;
        d.b = B;
        que.push(d);
    }

    //while (!que.empty()) {
    //    DEBUG(que.top().i);
    //    DEBUG(que.top().a);
    //    DEBUG(que.top().b);
    //    que.pop();
    //}
    // cout << "------------" << endl;
    // while (!queB.empty()) {
    //     DEBUG(queB.top().i);
    //     DEBUG(queB.top().a);
    //     DEBUG(queB.top().b);
    //     DEBUG(queB.top().diff);
    //     queB.pop();
    // }

    bool isA = true;
    ll sumA = 0;
    ll sumB = 0;
    while (!que.empty()) {
        if (isA) {
    //        DEBUG(que.top().a);
            sumA += que.top().a;
            isA = false;
        } else {
    //       DEBUG(que.top().b);
            sumB += que.top().b;
            isA = true;
        }
        que.pop();
    }
   // DEBUG(sumA);
   // DEBUG(sumB);
    cout << (sumA - sumB) << endl;

}
