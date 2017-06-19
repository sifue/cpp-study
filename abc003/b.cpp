#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int sum = 0;
  bool is_win = true;
  set<char> at_coder;
  at_coder.insert('a');
  at_coder.insert('t');
  at_coder.insert('c');
  at_coder.insert('o');
  at_coder.insert('d');
  at_coder.insert('e');
  at_coder.insert('r');
  for (int i = 0; i < s.size(); i++) {
     char sc = s[i];
     char tc = t[i];

     if (sc == tc) {
         continue;
     } else {
         if (sc == '@' && at_coder.count(tc) == 1) {
            continue;
         } else if (tc == '@' && at_coder.count(sc) == 1) {
            continue;
         }
         is_win = false;
         break;
     }
  }

  if (is_win) {
    cout << "You can win" << endl;
  } else {
    cout << "You will lose" << endl;
  }
}
