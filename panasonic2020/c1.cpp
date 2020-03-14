#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main(void){
ll a,b,c;

cin >> a >> b >> c;

ll d = c - a - b;
if(d > 0 && d * d > 4 * a * b){
cout << "Yes" << endl;
} else {
cout << "No" << endl;
}

return 0;
}

