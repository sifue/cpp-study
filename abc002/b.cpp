#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cfenv>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int length = s.size();
    char c[length] = {};
    char fTarget[5] = {'a', 'i', 'u', 'e', 'o'}; 
    s.copy(c, length);
    vector<char> filtered;

    for(int i = 0; i < length ; i++) {
        bool isFilter = false;
        for(int j = 0; j < 5 ; j++) {
            if ( c[i] == fTarget[j]) isFilter = true;
        }

        if(!isFilter) {
            filtered.push_back(c[i]);
        }
    }

    for(int k = 0; k < filtered.size(); k++) {
        cout << filtered.at(k);
    }
    cout << endl;
}
