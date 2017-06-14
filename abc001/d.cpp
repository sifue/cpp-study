#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cfenv>

using namespace std;

int main() {
    int n;
    string record;
    cin >> n;

    int fivesCount = 24*12;
    int fives[fivesCount];
    for (int i = 0; i < fivesCount; i++) {
        fives[i] = 0;
    }

    for (int j = 0; j < n; j++) {
        int start, end;
        scanf("%d-%d", &start, &end);
        int sHour, sMinFive, eHour, eMinFive;
        sHour = start / 100;
        sMinFive = start % 100 / 5;
        eHour = end / 100;
        eMinFive = ((end % 100) - 1) / 5;
        //cout << "j:" << j << endl;
        //cout << sHour << endl;
        //cout << sMinFive << endl;
        //cout << eHour << endl;
        //cout << eMinFive << endl;
        for (int k = 0; k < fivesCount; k++) {
            //cout << "k:" << k << endl;
            if (sHour * 12 + sMinFive <= k &&  k < eHour * 12 + eMinFive) {
                fives[k] = 1;
                // cout << fives[k] << endl;
            }
        }
    }

    int current = 0;
    for (int l = 0; l < fivesCount; l++) {
        fives[l];

        if(current == 0 && fives[l] == 1) {
            cout << setfill('0') << setw(2) << (l / 12);
            cout << setfill('0') << setw(2) << (l % 12) * 5;
            current = 1;
        }

        if(current == 1 && fives[l] == 0) {
            cout << "-";
            cout << setfill('0') << setw(2) << (l / 12);
            cout << setfill('0') << setw(2) << (l % 12) * 5 << endl;
            current = 0;
        }

        if (current == 1 && fives[l] == 1 && l == (fivesCount - 1)) {
            cout << "-";
            cout << setfill('0') << setw(2) << 24;
            cout << setfill('0') << setw(2) << 0 << endl;
        }
    }
}
