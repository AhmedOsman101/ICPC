#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

using namespace std;

string number_to_string(unsigned long long num) {
  ostringstream result;

  if (num == floor(num)) {
    result << static_cast<unsigned long long>(num);
  } else {
    result << fixed << setprecision(6) << num;
  }

  return result.str();
}

string ltrim(const string &str, const string &characters) {
  // finds the index of the first character that is NOT in the `characters`
  // string.
  unsigned long index = str.find_first_not_of(characters);
  if (index == string::npos) { // if nothing found it return npos
    return "";                 // string only contains charsToRemove
  }
  return str.substr(index);
}

string sum_strings(string n, string m) {
  reverse(n.begin(), n.end());
  reverse(m.begin(), m.end());

  string res = "";
  unsigned int len = max(n.length(), m.length()) + 1;
  int carry = 0;
  for (unsigned int i = 0; i < len; i++) {
    // '5' - '0' is equivalent to 53 - 48 = 5 (using ASCII values)
    int na = (i < n.length()) ? (n[i] - '0') : 0;
    int nb = (i < m.length()) ? (m[i] - '0') : 0;
    int sum = na + nb + carry;

    // cout << "sum: " << na + nb << " carry: " << carry << endl;

    if (sum == 0) {
      res += "0";
      continue;
    } else if (sum < 10) {
      res += to_string(sum);
      carry = 0;
    } else {
      res += to_string(sum - 10);
      carry = 1;
    }
  }

  reverse(res.begin(), res.end());
  res = ltrim(res, "0");

  return res.length() == 0 ? "0" : res;
}

int numSize(unsigned long long num) {
  if (num == 0)
    return 1;
  int len = 0;

  while (num > 0) {
    len++;
    num /= 10;
  }
  return len;
}

unsigned long long karatsuba(unsigned long long x, unsigned long long y) {
  if (x < 10 || y < 10)
    return x * y;

  unsigned int n = max(numSize(x), numSize(y));

  // cout << n << endl;

  int half_n = n / 2;
  // cout << half_n << endl;

  unsigned long long a = stoull(number_to_string(x).substr(0, half_n));
  unsigned long long b = stoull(number_to_string(x).substr(half_n));
  unsigned long long c = stoull(number_to_string(y).substr(0, half_n));
  unsigned long long d = stoull(number_to_string(y).substr(half_n));
  printf("a: %llu b: %llu d: %llu c: %llu\n", a, b, c, d);

  unsigned long long ac = karatsuba(a, c);
  unsigned long long bd = karatsuba(b, d);
  unsigned long long ad_bc = karatsuba(a + b, c + d) - ac - bd;

  unsigned long long result =
      ac * pow(10, 2 * half_n) + ad_bc * pow(10, half_n) + bd;

  printf("%llux%llu= %llu\n", x, y, result);

  return result;
}

void Y() {
  unsigned long long a, b, c, d, result;
  cin >> a >> b >> c >> d;
  // a = pow(10, 9);
  // b = pow(10, 9);
  // c = pow(10, 9);
  // d = pow(10, 9);
  // a = 9999999999;
  // b = 9999999999;
  // c = 9999999999;
  // d = 9999999999;

  long double total = log(a) + log(b) + log(c) + log(d);
  total = exp(total);

  if (total == floor(total)) {
    result = static_cast<unsigned long long>(total) % 100;
    // cout << "int total: " << total << endl;
    cout << "int result: " << result << endl;
  } else {
    long double diff = total - floor(total);
    cout << "float diff: " << diff << endl;
    string tmp = to_string(diff);
    cout << "float tmp: " << tmp << endl;
    result = diff * pow(10, tmp.length() - 2);
    cout << "float result1: " << result << endl;
    result %= 100;
    cout << "float result2: " << result << endl;
  }
  cout << (result == 0 ? "00" : to_string(result)) << endl;

  string x = to_string(result);
  // cout << x << endl;
  cout << (x == "0" ? "00" : (x.substr(x.length() - 2))) << endl;
}

int main() {
  // unsigned long long a, b;
  // cin >> a >> b;
  // a = 9999999999;
  // b = 9999999999;
  // cout << karatsuba(a, b) << endl;

  Y();

  return 0;
}
