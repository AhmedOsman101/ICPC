#include <iostream>
#include <map>

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

int B() {
  int k, s, count = 0;
  int skips = 0;
  cin >> k >> s;

  if(s == 0) {
    printf("1\n");
    return 0;
  }

  int limit = k < s ? k : s;

  for(int x = limit; 0 <= x; x--) {
    if(limit <= skips) {
      break;
    }
    for(int y = limit; 0 <= y; y--) {
      if(skips > 0) {
        --skips;
        continue;
      }
      for(int z = 0; z <= limit; z++) {
        int sum = x + y + z;
        // printf("current: %i %i %i => %i, skips: %i\n", x, y, z, sum, skips);
        if(sum - s > 0) {
          skips = sum - s - 1;
          // printf("too big: %i %i %i => %i\n\n", x, y, z, sum);
          break;
        } else if(k < s - sum - 1) {
          skips = (s - sum) % k;
          // printf("%i < %i => %i\n", k, s - sum, (s - sum) % k);
          // printf("too small: %i %i %i => %i, skips: %i\n\n", x, y, z, sum, skips);
          break;
        } else if(sum == s) {
          count++;
          // printf("match: %i %i %i => %i\n\n", x, y, z, sum);
        }
      }
    }
  }

  printf("%d\n", count);
  return 0;
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


int main() {
  B();
  return 0;
}
