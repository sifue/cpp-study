#include <iostream>
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
  double result = 0.0;
  priority_queue<int> rates;
  for (int i = 0; i < n; i++) {
    int rate;
    cin >> rate;
    rates.push(rate);
  }

  for (int i = 1; i <= k; i++) {
    // i個取得する場合
    priority_queue<int> queue = rates;
    stack<int> stack;
    int counter = i;
    while (counter != 0) {
      //cout << queue.top() << endl;
      stack.push(queue.top());
      queue.pop();
      counter--;
    }

    double c = 0.0;
    while (!stack.empty()) {
      int r = stack.top();
      if (r < c) break;
      // cout << r << " " ;
      c = (c + r) / 2.0;
      stack.pop();
    }
    cout << endl;

    if (c > result) { // 最大値更新できるなら更新
      result = c;
    } 
  }

  cout << result << endl;
}
