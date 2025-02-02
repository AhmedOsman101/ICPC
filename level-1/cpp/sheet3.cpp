#include <cctype>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <map>
#include <stdbool.h>
#include <stdio.h>
#include <string>

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

int F() {
  int a, b;
  string s;
  scanf("%d %d\n", &a, &b);

  int len = a + b + 1;

  getline(cin, s);

  if(s[a] == '-') {
    for(int i = a + 1; i < len; i++) {
      if(!isdigit(s[i])) {
        cout << "No" << endl;
        return 0;
      }
    }
  } else {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}

void G() {
  int n, count = 0;
  bool finished = false;

  cin >> n;

  int arr[n];

  for(int i = 0; i < n; i++) cin >> arr[i];

  while(!finished) {
    for(int i = 0; i < n; i++) {
      /*
        The least significant bit (LSB) of a number determines if it is even or odd.
        read more on my blog:
        https://obsidian-notes-swart.vercel.app/Programming/BitwiseOperations.html#_1-checking-if-a-number-is-even
      */
      if((arr[i] & 1) != 0) {
        finished = true;
        break;
      }
      /*
        Each right shift halves the value of arr[i].
        read more on my blog:
        https://obsidian-notes-swart.vercel.app/Programming/BitwiseOperations.html#_6-dividing-a-number-by-using-right-shifts
      */
      else arr[i] >>= 1;
    }
    if(!finished) count++;
  }
  cout << count << endl;
}

void H() {
  int n, prev = 0;
  cin >> n;
  n *= 2;

  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];

  for(int i = 0; i < n; i++) prev ^= a[i]; // xor will eliminate any duplicates

  // if all elements are the same it will output 0, then it's a permutation else it's not
  cout << (prev == 0 ? "yes" : "no") << endl;
}

void I() {}

void J() {}

int Q() {
  int n, mid, inc = 0;
  string s, res;

  cin >> n;
  mid = n % 2 == 0 ? (n / 2) - 1 : n / 2;

  cin >> s;

  if(n <= 2) {
    cout << s << endl;
    return 0;
  }

  res = s;

  for(int i = 0; i < n - 1; i++) {
    if(i % 2 == 0) res[mid + inc] = s[i];
    else {
      inc ++;
      res[mid - inc] = s[i];
    }
  }

  cout << res << endl;
  return 0;
}

int main() {
  H();
  return 0;
}
