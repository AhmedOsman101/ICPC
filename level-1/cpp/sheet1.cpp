#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

void A() {
  string name;
  cin >> name;
  cout << "Hello, " << name << endl;
}

void B() {
  const double PI = 3.141592653;
  double R;
  cin >> R;
  cout << fixed << setprecision(9) << pow(R, 2) * PI << endl;
}

void C() {
  long a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << a * b * c * d << endl;
}

void D() {
  string n1, n2;
  cin >> n1 >> n2;
  /*
    stoi method from the string library converts strings to integers,
    but using n1[index] returns a char data type which is not compatible with
    stoi, so I converted it to a string using string method which accepts the
    length of the string and the value
  */
  int sum = stoi(string(1, n1[n1.length() - 1])) +
    stoi(string(1, n2[n2.length() - 1]));
  cout << sum << endl;
}

void E() {
  int k, x;
  cin >> k >> x;

  string response = (k * 500 >= x) ? "Yes" : "No";

  cout << response << endl;
}

void F() {
  long long a, b, c, d, minLeft, minRight;
  string minlName, minrName, minimum;
  cin >> a >> b >> c >> d;

  minLeft = min(a, b);
  minlName = (a < b) ? "A" : "B";

  if (a == b)
    minlName = "Equal";

  minRight = min(c, d);
  minrName = (c < d) ? "C" : "D";

  if (c == d)
    minrName = "Equal";

  minimum = (minLeft < minRight) ? minlName : minrName;

  if (minLeft == minRight)
    minimum = "Equal";

  cout << minimum << endl;
}

void G() {
  string s;
  int max = 0, count = 0;
  cin >> s;

  for (short i = 0; i < 3; i++) {
    if (s[i] == 'R') {
      count++;
      max = count;
    } else
      count = 0;
  }

  cout << max << endl;
}

void H() {
  float V, T, S, D;
  cin >> V >> T >> S >> D;
  float time = D / V;

  cout << ((time < T || S < time) ? "Yes" : "No") << endl;
}

void I() {
  long long n, k, half;
  cin >> n >> k;

  half = ceil((double)n / 2);

  cout << ((k > half) ? (k - half) * 2 : (k * 2) - 1) << endl;
}

void J() {
  int w;
  cin >> w;

  cout << ((w % 2 == 0 && w > 2) ? "YES" : "NO") << endl;
}

void K() {
  string n;
  cin >> n;
  int iterations, len = n.length();

  iterations = ceil((float)len / 2);
  iterations = len % 2 == 0 ? iterations : iterations - 1;

  for (int i = 0; i < iterations; i++) {
    int j = iterations * 2 - i;

    if (n[i] != n[j]) {
      cout << "No" << endl;
      return;
    }
  }

  cout << "Yes" << endl;
}

void L() {
  int A, B;
  cin >> A >> B;

  if (0 < A && B == 0)
    cout << "Gold" << endl;

  else if (A == 0 && 0 < B)
    cout << "Silver" << endl;

  else if (0 < A && 0 < B)
    cout << "Alloy" << endl;
}

void M() {
  int d, steps = 0, i = 5;
  cin >> d;

  while (d != 0) {
    if (0 <= d - i) {
      d -= i;
      steps++;
    } else
      i--;
  }

  cout << steps << endl;
}

void N() {
  int A, B;
  cin >> A >> B;

  cout << ((float)A / 100) * B << endl;
}

void O() {
  int M;
  cin >> M;

  cout << (M == 0 ? 24 : 48 - M) << endl;
}

void P() {
  double A, B;
  cin >> A >> B;

  cout << fixed << setprecision(6) << ((A - B) / 3) + B << endl;
}

void Q() {
  int t, a, b, c;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c;

    cout << (a + b == c ? '+' : '-') << endl;
  }
}

void R() {
  int t, a, b, c;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c;

    cout << ((a + b == c || a + c == b || b + c == a) ? "YES" : "NO") << endl;
  }
}

void S() {
  int t, x = 0;
  string cmd;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> cmd;

    if (cmd[0] == '+')
      ++x;
    else if (cmd[0] == '-')
      --x;
    else if (cmd[1] == '+')
      x++;
    else if (cmd[1] == '-')
      x--;
  }

  cout << x << endl;
}

void T() {
  long long N, sum = 0;
  string A;
  cin >> N >> A;

  for (short i = 0; i < N; i++)
    sum += stoi(string(1, A[i]));

  cout << sum << endl;
}

void U() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;

  double l = b * log(a);
  double r = d * log(c);

  cout << (l > r ? "YES" : "NO") << endl;
}

void V() {
  long long n;
  cin >> n;
  cout << (n * (n + 1)) / 2 << endl;
}

void W() {
  double a, b;
  cin >> a >> b;

  cout << "floor " << a << " / " << b << " = " << floor(a / b) << endl;
  cout << "ceil " << a << " / " << b << " = " << ceil(a / b) << endl;
  cout << "round " << a << " / " << b << " = " << round(a / b) << endl;
}

void X() {
  int a, b, c;

  cin >> a >> b >> c;

  cout << min(min(a, b), c) << ' ' << max(max(a, b), c) << endl;
}

void Y() {
  unsigned long long a, b, c, d;
  cin >> a >> b >> c >> d;
  unsigned long long base[4] = {a, b, c, d};

  unsigned long long result = 1;

  for (unsigned long long i = 0; i < 4; i++) {
    base[i] %= 100;
    result = (result * base[i]) % 100;
  }

  string x = to_string(result);

  if (x.length() == 1)
    cout << 0 << result << endl;

  else
    cout << result << endl;
}

void Z() {
  double n, diff;
  cin >> n;
  diff = n - (int)n;

  if (diff == 0)
    cout << "int " << (int)n << endl;

  else
    cout << "float " << (int)n << ' ' << diff << endl;
}

void AA() {
  float x;
  cin >> x;

  if (x <= 25 && x >= 0)
    cout << "Interval [0,25]" << endl;
  else if (x <= 50 && x > 25)
    cout << "Interval (25,50]" << endl;
  else if (x <= 75 && x > 50)
    cout << "Interval (50,75]" << endl;
  else if (x <= 100 && x > 75)
    cout << "Interval (75,100]" << endl;
  else
    cout << "Out of Intervals" << endl;
}

void AB() {
  int a, b;
  char s;
  cin >> a >> s >> b;

  switch (s) {
    case '+':
      cout << a + b << endl;
      break;

    case '-':
      cout << a - b << endl;
      break;

    case '*':
      cout << a * b << endl;
      break;

    case '/':
      cout << defaultfloat << ((a * 1.0) / b) << endl;
      break;

    default:
      break;
  }
}

void AC() {
  int n, a, b, c, count = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;

    if (a + b + c >= 2)
      count++;
  }

  cout << count << endl;
}

void AD() {
  int m, n;
  cin >> m >> n;
  cout << floor((m * n) / 2) << endl;
}

void AE() {
  long double m, n, a;
  cin >> m >> n >> a;

  long double blocks = (ceil(m / a) * ceil(n / a));

  cout << defaultfloat << setprecision(30) << blocks << endl;
}

void AF() {
  string s;
  cin >> s;

  s[0] = s[0] > 90 ? s[0] - 32 : s[0];

  cout << s << endl;
}

void AG() {
  int t, a, b, c;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c;

    if (a < b && b < c)
      cout << "STAIR" << endl;
    else if (a < b && b > c)
      cout << "PEAK" << endl;
    else
      cout << "NONE" << endl;
  }
}

void AH() {
  string s, t;
  cin >> s >> t;

  reverse(t.begin(), t.end());

  cout << (s == t ? "YES" : "NO") << endl;
}

int main() {
  AH();
  return 0;
}
