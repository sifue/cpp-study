#include <cfenv>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int deg, dis, w;
  int dirIndex;
  string dir;
  cin >> deg >> dis;

  deg = deg * 10;
  dirIndex = deg / 1125;

  switch (dirIndex) {
  case 0:
  case 31:
    dir = "N";
    break;
  case 1:
  case 2:
    dir = "NNE";
    break;
  case 3:
  case 4:
    dir = "NE";
    break;
  case 5:
  case 6:
    dir = "ENE";
    break;
  case 7:
  case 8:
    dir = "E";
    break;
  case 9:
  case 10:
    dir = "ESE";
    break;
  case 11:
  case 12:
    dir = "SE";
    break;
  case 13:
  case 14:
    dir = "SSE";
    break;
  case 15:
  case 16:
    dir = "S";
    break;
  case 17:
  case 18:
    dir = "SSW";
    break;
  case 19:
  case 20:
    dir = "SW";
    break;
  case 21:
  case 22:
    dir = "WSW";
    break;
  case 23:
  case 24:
    dir = "W";
    break;
  case 25:
  case 26:
    dir = "WNW";
    break;
  case 27:
  case 28:
    dir = "NW";
    break;
  case 29:
  case 30:
    dir = "NNW";
    break;
  }

  double disd;
  disd = dis * 10.0;
  disd = disd / 60.0;
  disd = round(disd);

  if (disd <= 2) {
    w = 0;
  } else if (disd <= 15) {
    w = 1;
  } else if (disd <= 33) {
    w = 2;
  } else if (disd <= 54) {
    w = 3;
  } else if (disd <= 79) {
    w = 4;
  } else if (disd <= 107) {
    w = 5;
  } else if (disd <= 138) {
    w = 6;
  } else if (disd <= 171) {
    w = 7;
  } else if (disd <= 207) {
    w = 8;
  } else if (disd <= 244) {
    w = 9;
  } else if (disd <= 284) {
    w = 10;
  } else if (disd <= 326) {
    w = 11;
  } else {
    w = 12;
  }

  if (w == 0)
    dir = "C";

  cout << dir << " " << w << endl;
}
