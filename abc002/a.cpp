#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cfenv>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x > y) {
        cout << x << endl;
    } else {
        cout << y << endl;
    }
}
