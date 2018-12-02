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

int main() {
    int N;
    cin >> N;
    int target = 357;
    int count = 0;
    while (target <= N) {
        int check = target;
        int c3 = 0;
        int c5 = 0;
        int c7 = 0;
        int ca = 0;
        // DEBUG(target);
        // DEBUG(check);

        int lastDigit = 0;
        int modTry = 0;
        while (check > 0) {
            // DEBUG(check);
            int mod = check % 10;
            if (mod == 3) {
                c3++;
            } else if (mod == 5) {
                c5++;
            } else if (mod == 7) {
                c7++;
            } else {
                ca++;
            }
            modTry++;
            lastDigit = check;
            check = check / 10;
        }
        // DEBUG(modTry);
        // DEBUG(lastDigit);

        if ((ca == 0) &&(c3 > 0 && c5 > 0 && c7 > 0)) {
            // DEBUG(target);
            // DEBUG(c3);
            // DEBUG(c5);
            // DEBUG(c7);
            // DEBUG(ca);
            count++;
        } 
        
        if (!(lastDigit == 3 || lastDigit == 5 || lastDigit == 7)) {
            target +=  10 * (modTry);
        } else {
            if (target % 10 == 3) {
                target += 2;
            } else if (target % 10 == 5) {
                target += 2;
            } else if (target % 10 == 7) {
                target += 6;
            }
        }
        

    }

    cout << count << endl;
}
