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

struct DishA {
    int i;
    ll diff;
    ll a;
    ll b;
    bool operator<( const DishA& right ) const {
        if (diff == right.diff) {
            return a < right.a;
        } else {
            return diff > right.diff;
        }
    }
};

struct DishB {
    int i;
    ll diff;
    ll a;
    ll b;
    bool operator<( const DishB& right ) const {
        if (diff == right.diff) {
            return b < right.b;
        } else {
            return diff > right.diff;
        }
    }
};
__attribute__((constructor)) void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    int N;
    cin >> N;
    priority_queue<DishA> queA;
    priority_queue<DishB> queB;
    rep(i, N) {
        int A, B;
        cin >> A >> B;

        DishA da;
        da.i = i;
        da.diff = A-B;
        da.a = A;
        da.b = B;
        queA.push(da);

        DishB db;
        db.i = i;
        db.diff = A-B;
        db.a = A;
        db.b = B;
        queB.push(db);
    }

    // while (!queA.empty()) {
    //     DEBUG(queA.top().i);
    //     DEBUG(queA.top().a);
    //     DEBUG(queA.top().b);
    //     DEBUG(queA.top().diff);
    //     queA.pop();
    // }
    // cout << "------------" << endl;
    // while (!queB.empty()) {
    //     DEBUG(queB.top().i);
    //     DEBUG(queB.top().a);
    //     DEBUG(queB.top().b);
    //     DEBUG(queB.top().diff);
    //     queB.pop();
    // }

    bool isA = true;
    set<int> delSet;
    ll sumA = 0;
    ll sumB = 0;
    while (!queA.empty() && !queB.empty()) {
        if (isA) {
            while(delSet.count(queA.top().i) != 0) queA.pop();
            sumA += queA.top().a;
            delSet.insert(queA.top().i);
            isA = false;
            queA.pop();
        } else {
            while(delSet.count(queB.top().i) != 0) queB.pop();
            sumB += queB.top().b;
            delSet.insert(queB.top().i);
            isA = true;
            queB.pop();
        }
    }
//     DEBUG(sumA);
//     DEBUG(sumB);
    cout << (sumA - sumB) << endl;

}
