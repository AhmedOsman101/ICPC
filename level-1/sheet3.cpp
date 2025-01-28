#include <cstdint>
#include <iostream>
#include <map>

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

void B() {
  int n, x = 0;
  char op[4];

  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> op;
    for(short j = 0; j < 3; j++) {
      if(op[j] == '+') {
        x++;
        break;
      } else if(op[j] == '-') {
        x--;
        break;
      }
    }
  }

  cout << x << endl;
}

int C() {
  int n, target;
  cin >> n;
  int arr[n];

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cin >> target;

  for(int j = 0; j < n; j++) {
    if(arr[j] == target) {
      cout << j << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}

void D() {
  int n, number;
  long long min = INTMAX_MAX;
  cin >> n;

  map<int, int> arr;

  for(int i = 0; i < n; i++) {
    cin >> number;
    if(number < min) min = number;
    arr[number]++;
  }

  cout << (arr[min] % 2 == 0 ? "Unlucky" : "Lucky") << endl;
}

void E() {
  int n, sum = 0;
  cin >> n;

  char arr[n + 1];

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i] - 48; // the digits 0~9 is equavilant to the range 48~57 in ascii
  }

  cout << sum << endl;
}

void F() {}

void G() {}

void H() {}

void I() {}


void J() {}


int main() {
  E();
  return 0;
}
