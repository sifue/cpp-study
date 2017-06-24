#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const int mod_factor = 1000000007;

int get_pattern(int rest, int select) {
  if (select == 0)
    return 1;
  cout << "rest:" << rest << endl;
  return rest * get_pattern(rest - 1, select - 1);
}

int fact(int n) {
  if (n == 1)
    return 1;
  if (n == 0)
    return 1;
  return n * fact(n - 1);
}

int main() {
  int r, c, x, y, d, l;
  cin >> r >> c >> x >> y >> d >> l;

  // 1. まずは区画の置き方のパターンを計算する ps
  // 2. 区画内のデスクとラックの置き方を計算する pp
  // 3. ps * pp / 1000000007 が答えとなる
  int ps = (r - x + 1) * (c - y + 1); // 1 縦横の空き幅を掛け
  cout << "ps:" << ps << endl;

  // 2
  int space = x * y; // x y のスペースの数
  cout << "space:" << space << endl;

  int result = 0;
  if (space == d + l) { // 100点のパターン
    int gp = get_pattern(space, d);
    cout << "gp:" << gp << endl;
    int fc = fact(d);
    cout << "fc:" << fc << endl;
    int desk_pattern = gp / fc;
    int pp = (desk_pattern * ps);
    result = pp % mod_factor;
  } else { // 101点のパターン
    int gp = get_pattern(space, d);
    cout << "gp:" << gp << endl;
    cout << "fact(d):" << fact(d) << endl;
    int desk_pattern = gp / fc;
    cout << "desk_pattern:" << desk_pattern << endl;
    int lack_pattern = get_pattern(space - d, l) / fact(l);
    cout << "lack_pattern:" << lack_pattern << endl;
    int pp = (desk_pattern * lack_pattern * ps);
    result = pp % mod_factor;
  }

  cout << result << endl;
}
