#include <iostream>

using namespace std;

int main() {
  char field[4][4] = {};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> field[i][j];
    }
  }

  for (int i = 3; i >= 0; i--) {
    for (int j = 3; j >= 0; j--) {
      if (j == 0) {
        cout << field[i][j];
      } else {
        cout << field[i][j] << " ";
      }
    }
    cout << endl;
  }
}
