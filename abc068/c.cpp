#include <iostream>
#include <map>
#include <set>

using namespace std;

#define P(s) cout << s << endl;
#define PVEC(v) cout << "vector: "; for(auto i = v.begin(); i != v.end(); ++i) cout << *i << ","; cout << endl;
#define PSET(v) cout << "set: "; for(auto i = v.begin(); i != v.end(); ++i) cout << *i << ","; cout << endl;
#define PMAP(m) cout << "map: "; for(auto elem : m)  elem.first << "->" << elem.second ", "; cout << endl;
#define DEBUG(x) cout << #x << ": " << x << endl;

int main() {
  int n, m;
  cin >> n >> m;

  set<pair<int, int>> pathSet;
  for(int i = 0; i < m ; i++) {
    int a, b;
    cin >> a >> b;
    pathSet.insert(make_pair(a, b));
    pathSet.insert(make_pair(b, a));
  }

  bool is_possible = false;
  for(int second = 2; second < n ; second++) {
    if (pathSet.count(make_pair(1, second)) > 0) {
      if(pathSet.count(make_pair(second, n)) > 0) {
        is_possible = true;
        break;
      }
    }
  }

  if (is_possible) {
    cout << "POSSIBLE" << endl;
  } else { 
    cout << "IMPOSSIBLE" << endl;
  }
}
