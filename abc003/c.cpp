#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/*
   小さいものから見ていったほうが点数が高くなる
   rate をソート
   その中から1 ~ k 個取る方法を考えて
   うしろの数の最大が含まれるように取ってみる
   もし点数が更新できなかったら終了
*/

int main() {
  int n, k;
  cin >> n >> k;
  long double result = 0.0;
  priority_queue<long> rates;
  for (int i = 0; i < n; i++) {
    long rate;
    cin >> rate;
    rates.push(rate);
  }

  for (int i = 1; i <= k; i++) {
    // i個取得する場合
    priority_queue<long> queue = rates;
    stack<long> stack;
    int counter = i;
    while (counter != 0) {
      stack.push(queue.top());
      queue.pop();
      counter--;
    }

    long c_e8 = 0;
    while (!stack.empty()) {
      long r = stack.top();
      c_e8 = (c_e8 + r * 10000000000) / 2;
      stack.pop();
    }
    long double c = (long double)c_e8 / 10000000000.0; 

    if (c > result) { // 最大値更新できるなら更新
      result = c;
    } 
  }

  cout << fixed << setprecision(6) << result << endl;
}
