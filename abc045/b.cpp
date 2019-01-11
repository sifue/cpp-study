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

__attribute__((constructor))
void initial() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}


string SA, SB, SC;
int PA = 0;
int PB = 0;
int PC = 0;
char n = 'a';

bool isFinished() {
    if (n == 'a') {
        return PA >= SA.size();
    } else if (n == 'b') {
        return PB >= SB.size();
    } else if (n == 'c') {
        return PC >= SC.size();
    }
}

int main() {
    cin >> SA >> SB >> SC;
//    DEBUG(SA);
//    DEBUG(SB);
//    DEBUG(SC);

    while (!isFinished()){
//        DEBUG(n);
//        DEBUG(PA);
//        DEBUG(PB);
//        DEBUG(PC);

        if (n == 'a') {
            n = SA[PA];
            PA++;
        } else if (n == 'b') {
            n = SB[PB];
            PB++;
        } else if (n == 'c') {
            n = SC[PC];
            PC++;
        }
    }

    if (n == 'a') {
        cout << 'A' << endl;
    } else if (n == 'b') {
        cout << 'B' << endl;
    } else if (n == 'c') {
        cout << 'C' << endl;
    }
}
