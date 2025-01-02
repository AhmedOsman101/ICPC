#include <cstdio>
#include <cstring>
#include <iomanip>
#include <ios>
#include <iostream>
#include <math.h>
#include <map>
#include <string>

using namespace std;

string strrepeat(string s, int times) {
  string y;
  for(int i = 1; i <= times; i++) {
    y += s;
  }
  return y;
}

unsigned long long fib(
  unsigned long long n,
  map<unsigned long long, unsigned long long>& memo
) {
  if(memo.count(n)) return memo[n];

  memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
  return memo[n];
}

void A() {
  unsigned long long n;
  cin >> n;
  map<unsigned long long, unsigned long long> memo = {{1, 0}, {2, 1}};
  for(unsigned long long i = 1; i <= n; ++i) {
    printf("%llu ", fib(i, memo));
  }
  printf("\n");
}

void B() {
  int k, s, count = 0;
  cin >> k >> s;

  for(int x = 0; x <= s; x++) {

    for(int y = 0; y <= s; y++) {
      for(int z = 0; z <= s; z++) {
        int sum = x + y + z;
        if(sum == s) count++;
      }
    }
  }

  printf("%d\n", count);
}

void C() {
  long n;
  cin >> n;

  for(int i = 1; i <= n; i++) {
    printf("%d\n", i);
  }

}

void D() {
  string symbol;
  long n, lines;
  cin >> symbol >> lines;

  for(int i = 0; i < lines; i++) {
    cin >> n;
    cout << strrepeat(symbol, n) << "\n";
  }
}

void E() {
  int n;
  cin >> n;

  for(int i = n; 0 < i; i--) {
    cout << strrepeat("*", i) << "\n";
  }
}

void F() {
  int times;
  string n;
  cin >> times;

  for(int t = 1; t <= times; t++) {
    cin >> n;
    for(int i = n.length() - 1; 0 <= i; i--) {
      printf("%c ", n[i]);
    }
    cout << "\n";
  }
}

void G() {
  int size;
  cin >> size;

  for(int i = 0; i < size; i++) {
    int spaces = size - i - 1;
    int stars = (2 * i) + 1;
    cout << strrepeat(" ", spaces) << strrepeat("*", stars) << endl;
  }

}

void H() {
  int input;
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      cin >> input;
      if(input == 1) {
        cout << abs(2 - i) + abs(2 - j) << endl;
        return;
      }
    }
  }
}

void I() {
  int count = 0, length;
  string s;
  cin >> length >> s;

  for(int i = 0; i < length - 1; i++) {
    if(s[i] == s[i + 1]) {
      count++;
    }
  }
  cout << count << endl;
}


void J() {
  int cost, balance, amount, total = 0;
  cin >> cost >> balance >> amount;

  for(int i = 1; i <= amount; i++) total += i;

  total *= cost;

  cout << (balance < total ? total - balance : 0) << endl;
}

void K() {
  string n;
  cin >> n;
  int iterations, len = n.length();

  iterations = ceil((float) len / 2);
  iterations = len % 2 == 0 ? iterations : iterations - 1;

  for(int i = 0; i < iterations; i++) {
    int j = iterations * 2 - i;

    if(n[i] != n[j]) {
      cout << "No" << endl;
      return;
    }
  }

  cout << "Yes" << endl;
}

void L() {
  int A, B;
  cin >> A >> B;

  if(0 < A && B == 0)
    cout << "Gold" << endl;
  else if(A == 0 && 0 < B)
    cout << "Silver" << endl;
  else if(0 < A && 0 < B)
    cout << "Alloy" << endl;
}

void M() {
  int d, steps = 0, i = 5;
  cin >> d;

  while(d != 0) {
    if(0 <= d - i) {
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

  cout << ((float) A / 100) * B << endl;
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

  for(int i = 0; i < t; i++) {
    cin >> a >> b >> c;

    cout << (a + b == c ? '+' : '-') << endl;
  }
}

void R() {
  int t, a, b, c;

  cin >> t;

  for(int i = 0; i < t; i++) {
    cin >> a >> b >> c;

    cout << ((a + b == c || a + c == b || b + c == a) ? "YES" : "NO") << endl;
  }
}

void S() {
  int t, x = 0;
  string cmd;

  cin >> t;

  for(int i = 0; i < t; i++) {
    cin >> cmd;

    if(cmd[0] == '+')
      ++x;
    else if(cmd[0] == '-')
      --x;
    else if(cmd[1] == '+')
      x++;
    else if(cmd[1] == '-')
      x--;
  }

  cout << x << endl;
}

void T() {
  long long N, sum = 0;
  string A;
  cin >> N >> A;

  for(short i = 0; i < N; i++)
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

int main() {
  J();
  return 0;
}
