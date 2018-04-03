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
  int N, A, B;
  cin >> N >> A >> B;

  priority_queue<ll> values;
  map<ll, int> counts;

  rep(i, N) {
    ll v;
    cin >> v;
    values.push(v);

    if(counts.count(v) > 0) {
      int now = counts.at(v);
      counts.erase(v);
      counts.insert(make_pair(v, now + 1));
    } else {
      counts.insert(make_pair(v, 1));
    }
  }

  long double maxAvarage = -1;
  int maxTakeCount = -1;
  for (int takeCount = A; takeCount <= B ; takeCount++) {
    ll sum = 0;
    priority_queue<ll> copyValues = values;
    rep(i, takeCount) {
      sum += copyValues.top();
      copyValues.pop();
    }
    long double avarage = (long double)sum / takeCount;

    if(avarage > maxAvarage) {
      maxAvarage = avarage;
      maxTakeCount = takeCount;
    }
  }

  cout << fixed << setprecision(6) << maxAvarage << endl; 

  int pattern = 1;
  set<ll> useValues;
  priority_queue<ll> copyValues = values;
  rep(i, maxTakeCount) {
    ll useValue = copyValues.top();
    copyValues.pop();

    if(useValues.count(useValue) == 0) {
      pattern *= counts.at(useValue);
      useValues.insert(useValue);
    }
  }

  cout << pattern << endl;
}
