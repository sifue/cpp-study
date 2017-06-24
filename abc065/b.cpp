#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 1; i <= n; i++) {
      int to;
      cin >> to;
      m.insert(make_pair(i, to));
  }

  int current = 1;
  int push_count = 0;
  bool is_reached = false;
  while(!is_reached && !m.empty()){
     if (m.count(current) == 0) break;
     int next = m.at(current);
     push_count++;

     if (next == 2) {
         is_reached = true;
         break;
     }
     m.erase(current);
     current = next;
  }

  if (is_reached) {
    cout << push_count << endl;
  } else {
    cout << -1 << endl;
  }
}
