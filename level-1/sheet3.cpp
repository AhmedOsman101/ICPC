#include <iostream>

using namespace std;

string strrepeat(string s, int times) {
  string y;
  for(int i = 1; i <= times; i++) y += s;
  return y;
}

void A() {
  int t, n, minGold, gold = 0, count = 0;

  cin >> t;

  for(int i = 0; i < t; i++) {
    gold = 0;
    count = 0;

    cin >> n >> minGold;
    int currentGold;

    for(int j = 0; j < n; j++) {
      cin >> currentGold;
      if(currentGold >= minGold) {
        gold += currentGold;
      } else if(currentGold  == 0 && gold > 0) {
        gold--;
        count++;
      }
    }
    cout << count << "\n";
  }
}

void B() {}

void C() {}

void D() {}

void E() {}

void F() {}

void G() {}

void H() {}

void I() {}


void J() {}


int main() {
  // A();
  return 0;
}
