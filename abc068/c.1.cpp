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

  map<int, set<int>> pathMap;

  for(int i = 0; i < m ; i++) {
    int a, b;
    cin >> a >> b;

    set<int> av;
    if(pathMap.count(a) > 0) {
      av = pathMap.at(a);
    }
    av.insert(b);
    pathMap.erase(a);
    pathMap.insert(make_pair(a, av));

    set<int> bv;
    if(pathMap.count(b) > 0) {
      bv = pathMap.at(b);
    }
    bv.insert(a);
    pathMap.erase(b);
    pathMap.insert(make_pair(b, bv));
  }

  bool is_possible = false;
  if(pathMap.count(1) > 0) {
    set<int> first_paths = pathMap.at(1);
      for(int second : first_paths) {
        if(pathMap.count(second) > 0) {
          set<int> second_paths = pathMap.at(second);
          if (second_paths.count(n) > 0) {
            is_possible = true;
            break;
          }
        }
      }
  }

  if (is_possible) {
    cout << "POSSIBLE" << endl;
  } else { 
    cout << "IMPOSSIBLE" << endl;
  }
}
