#include <cctype>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

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

unsigned long long fib(
  unsigned long long n,
  map<unsigned long long, unsigned long long>& memo
) {
  if(memo.count(n)) return memo[n];

  memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
  return memo[n];
}

void G() {
  unsigned long long n;
  cin >> n;
  map<unsigned long long, unsigned long long> memo = {{1, 0}, {2, 1}};
  for(unsigned long long i = 1; i <= n; ++i) {
    printf("%llu ", fib(i, memo));
  }
  printf("\n");
}

void H() {
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

void I() {
  int n, prev = 0;
  cin >> n;
  n *= 2;

  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];

  for(int i = 0; i < n; i++) prev ^= a[i]; // xor will eliminate any duplicates

  // if all elements are the same it will output 0, then it's a permutation else it's not
  cout << (prev == 0 ? "yes" : "no") << endl;
}

#include <iostream>

using namespace std;

bool isSubseq(vector<int> x, vector<int> y) {
  size_t i = 0, j = 0;
  size_t n = x.size(), m = y.size();
  bool proceed = false;
  // cin >> n >> m;

  // int x[n], y[m];

  // for(size_t z = 0; z < n; z++) cin >> x[z];
  // for(size_t z = 0; z < m; z++) cin >> y[z];

  while(i < x.size()) {
    proceed = false;
    while(j < y.size()) {
      proceed = true;

      size_t a = x[i];
      size_t b = y[j];

      if(a == b) {
        if(i == (n - 1) && j < (m - 1)) return false;
        i++;
        j++;
        break;
      } else {
        x.erase(x.begin() + i);
        if(i == (n - 1)) return false;
        i++;
      }
    }
    if(!proceed) return false;
  }
  return true;
}

void J() {
  // cout << (isSubseq() ? "YES" : "NO") << endl;

  vector<pair<vector<int>, vector<int >>> testCases = {
    // Edge cases
    {{1}, {1}},           // Minimal case, subsequence (YES)
    {{1}, {}},            // Empty B is a subsequence (YES)
    {{1, 2, 3}, {4}},     // B not in A (NO)

    // Basic cases
    {{1, 4, 7}, {1, 7}},  // Subsequence (YES)
    {{1, 8, 4, 7}, {4, 5}}, // Not subsequence (NO)
    {{21, 8, 40}, {21, 8, 40}}, // Full sequence match (YES)

    // Large cases
    {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {2, 4, 6, 8, 10}}, // Alternating subsequence (YES)
    {{10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, {20, 50, 90}}, // Gaps between elements (YES)
    {{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, {3, 2, 1}}, // Reverse order subsequence (YES)

    // Cases with duplicates
    {{1, 1, 1, 1, 1}, {1, 1}}, // All elements identical (YES)
    {{1, 2, 2, 3, 3, 3, 4}, {2, 3, 3}}, // Duplicates in subsequence (YES)
    {{1, 2, 3, 4}, {2, 2}}, // Not subsequence due to repetition (NO)

    // Complex cases
    {{100, 200, 300, 400, 500}, {200, 400}}, // Skipping intermediate elements (YES)
    {{1, 3, 5, 7, 9}, {1, 7}}, // Subsequence with gaps (YES)
    {{10, 20, 30, 40}, {10, 50}}, // Element not found (NO)

    // Edge boundary cases
    {{1, 1, 1, 1, 1}, {}}, // Empty subsequence (YES)
    {{10}, {20}}, // Single element mismatch (NO)
    {{5, 10, 15, 20}, {20}}, // Last element match (YES)
    {{1, 3, 5}, {1, 2}}, // Missing element in sequence (NO)
    {{7, 8, 9, 10}, {9, 10}}, // Last part match (YES)
  };

  for(size_t i = 0; i < testCases.size(); i++) {
    vector<int> A = testCases[i].first;
    vector<int> B = testCases[i].second;

    cout << "Test case " << i + 1 << ":\n";
    cout << "A: ";
    for(int a : A) cout << a << " ";
    cout << "\nB: ";
    for(int b : B) cout << b << " ";
    cout << "\nExpected: " << (isSubseq(A, B) ? "YES" : "NO") << "\n\n";
  }
}

int q() {
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

bool isValidSquare(int row, int col, int rows, int cols) {
  return row >= 0 && row < rows && col >= 0 && col < cols;
}

int K() {
  int directions[8][2] = {
    {-1, 0}, // up
    {1, 0}, // down
    {0, -1}, // right
    {0, 1}, // left

    {-1, -1}, // top left
    {-1, 1}, // top right
    {1, -1}, // bottom left
    {1, 1}, // bottom right
  };

  int rows, cols, row, col;
  cin >> rows >> cols;

  char mat[rows][cols];

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) cin >> mat[i][j];
  }

  cin >> row >> col;
  row--; col--;

  for(int i = 0; i < 8; i++) {
    int newRow = row + directions[i][0];
    int newCol = col + directions[i][1];
    if(!isValidSquare(newRow, newCol, rows, cols)) continue;

    char opposing = mat[newRow][newCol];
    if(opposing == '.') {
      cout << "no" << endl;
      return 0;
    }
  }

  cout << "yes" << endl;
  return 0;
}


void L() {}

int main() {
  K();
  return 0;
}
