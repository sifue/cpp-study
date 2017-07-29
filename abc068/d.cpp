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
  int k;
  cin >> k;
  int a = k;
  cout << k << endl;
  cout << a;
  for (int i = 1 ; i < k; i++) {
    a--;
    cout << " " << a;
  }
  cout << endl;
}
