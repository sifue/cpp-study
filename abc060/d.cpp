#include <bits/stdc++.h>  // g++ -std=c++14 -o a a.cpp

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end()) // ユニークなvectorにする。連続した値を除去して切り出す。
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
  ll N, W;
  cin >> N >> W;

  ll w0 = -1;

  // key: w0 との diff value: vi の プライオリティキュー
  map<ll, priority_queue<ll> > vm;
  priority_queue<ll> q0;
  vm.insert(make_pair(0, q0));
  priority_queue<ll> q1;
  vm.insert(make_pair(1, q1));
  priority_queue<ll> q2;
  vm.insert(make_pair(2, q2));
  priority_queue<ll> q3;
  vm.insert(make_pair(3, q3));

  rep(i, N) {
    ll wi, vi;
    cin >> wi >> vi;
    if(w0 == -1) {
      w0 = wi;
    }
    ll diff = wi - w0;

    // DEBUG(diff);
    // DEBUG(vi);
    vm.at(diff).push(vi);
  }

  ll maxValue = 0;
  repto(i0, vm.at(0).size()) {
    repto(i1, vm.at(1).size()) { 
      repto(i2, vm.at(2).size()) {
        repto(i3, vm.at(3).size()) {

          // DEBUG(i0);
          // DEBUG(i1);
          // DEBUG(i2);
          // DEBUG(i3);

          ll wsum = i0 * w0 + i1 * w0 + i2 * w0 + i3 * w0;
          wsum += i1 * 1 + i2 * 2 + i3 * 3;
          if(wsum <= W) {
            ll vsum = 0;

            priority_queue<ll> cq0 = vm.at(0);
            rep(i, i0) {
              vsum += cq0.top();
              cq0.pop();
            }

            priority_queue<ll> cq1 = vm.at(1);
            rep(i, i1) {
              vsum += cq1.top();
              cq1.pop();
            }

            priority_queue<ll> cq2 = vm.at(2);
            rep(i, i2) {
              vsum += cq2.top();
              cq2.pop();
            }

            priority_queue<ll> cq3 = vm.at(3);
            rep(i, i3) {
              vsum += cq3.top();
              cq3.pop();
            }

            maxValue = max(maxValue, vsum);
          }
        }
        // DEBUG(maxValue);
      }
    }
  }
  cout << maxValue << endl;
}
