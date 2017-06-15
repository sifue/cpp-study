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
    int fives[fivesCount] = {};

    for (int j = 0; j < n; j++) {
        int start, end;
        scanf("%d-%d", &start, &end);
        int sHour, sMin, eHour, eMin;
        sHour = start / 100;
        sMin = start % 100;
        eHour = end / 100;
        eMin = end % 100;
        if (eMin == 0) {
            eHour--;
            eMin = 60;
        }
        //cout << "j:" << j << endl;
        //cout << sHour << endl;
        //cout << sMin << endl;
        //cout << eHour << endl;
        //cout << eMin << endl;
        for (int k = 0; k < fivesCount; k++) {
            if ((sHour * 12 + (sMin / 5)) <= k
                    && k <= (eHour * 12) + ((eMin - 1)/ 5)){
                fives[k] = 1;
                //cout << "k:" << k << endl;
            }
        }
    }

    int current = 0;
    for (int l = 0; l < fivesCount; l++) {

        if(current == 0 && fives[l] == 1) { // start
            cout << setfill('0') << setw(2) << (l / 12);
            cout << setfill('0') << setw(2) << (l % 12) * 5;
            current = 1;
        }

        if(current == 1 && fives[l] == 0) { // end
            cout << "-";
            int h = (l / 12);
            int m = (l % 12) * 5;
            if (m == 60) {
              h++;
              m = 0;
            }
            cout << setfill('0') << setw(2) << h;
            cout << setfill('0') << setw(2) << m << endl;
            current = 0;
        }

        if (current == 1 && fives[l] == 1 && l == (fivesCount - 1)) {
            cout << "-";
            cout << setfill('0') << setw(2) << 24;
            cout << setfill('0') << setw(2) << 0 << endl;
        }
    }
}
