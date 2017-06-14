#include <iostream>

using namespace std;

int main() {
    int n2 = 0;
    int n1 = 1;
    int current = 2;
    int sum = current;

    // cout << n1 << endl;
    // cout << current << endl;

    while (current <= 4000000) {
        n2 = n1;
        n1 = current;
        current = n2 + n1;
        // cout << current << endl;
        if (current % 2 == 0) {
            sum = sum + current;
        }
    }
    cout << sum << endl;
    return 0;
}
