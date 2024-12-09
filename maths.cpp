#include <math.h>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;

typedef complex<double> Complex;

template <typename T>
void print_vector(const vector<T> &vec, const string &delimiter = " ") {
  for (size_t i = 0; i < vec.size(); ++i) {
    cout << vec[i];
    if (i + 1 < vec.size())
      cout << delimiter;
  }
  cout << "\n";
}

// Fast Fourier Transform
void fft(vector<Complex> &a, bool invert) {
  int n = a.size();
  if (n == 1)
    return;

  vector<Complex> a0(n / 2), a1(n / 2);
  for (int i = 0; 2 * i < n; i++) {
    a0[i] = a[2 * i];
    a1[i] = a[2 * i + 1];
  }

  fft(a0, invert);
  fft(a1, invert);

  double angle = 2 * M_PI / n * (invert ? -1 : 1);
  Complex w(1), wn(cos(angle), sin(angle));
  for (int i = 0; 2 * i < n; i++) {
    a[i] = a0[i] + w * a1[i];
    a[i + n / 2] = a0[i] - w * a1[i];
    if (invert) {
      a[i] /= 2;
      a[i + n / 2] /= 2;
    }
    w *= wn;
  }
}

// Multiply two large numbers
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
  vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  size_t n = 1;
  while (n < a.size() + b.size())
    n <<= 1;
  fa.resize(n);
  fb.resize(n);

  fft(fa, false);
  fft(fb, false);
  for (size_t i = 0; i < n; i++)
    fa[i] *= fb[i];
  fft(fa, true);

  vector<int> result(n);
  for (size_t i = 0; i < n; i++)
    result[i] = round(fa[i].real());

  // Handle carry
  int carry = 0;
  for (size_t i = 0; i < result.size(); i++) {
    result[i] += carry;
    carry = result[i] / 10;
    result[i] %= 10;
  }

  while (!result.empty() && result.back() == 0)
    result.pop_back();
  return result;
}

int main() {
  string num1, num2;
  num1 = "888888887111111112";
  num2 = "777777776222222223";

  vector<int> a(num1.rbegin(), num1.rend()), b(num2.rbegin(), num2.rend());
  for (int &c : a)
    c -= '0';
  for (int &c : b)
    c -= '0';

  vector<int> result = multiply(a, b);

  if (result.empty()) {
    cout << 0 << endl;
  } else {
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
      cout << *it;
    }
    cout << endl;
  }

  return 0;
}
