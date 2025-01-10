#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void K() {
  int n, x, y, z, x_sum = 0, y_sum = 0, z_sum = 0;
  scanf("%i", &n);

  for(int i = 0; i < n; i++) {
    scanf("%i %i %i", &x, &y, &z);

    x_sum += x;
    y_sum += y;
    z_sum += z;
  }

  if(x_sum != 0 || y_sum != 0 || z_sum != 0) printf("NO\n");
  else printf("YES\n");
}

void L() {
  int n, k;
  scanf("%i %i", &n, &k);

  for(int i = 0; i < k; i++) {
    (n % 10 != 0) ? n-- : (n /= 10);
  }
  printf("%i\n", n);
}

void M() {
  int count = 1;
  char str[100];
  fgets(str, sizeof(str), stdin);

  for(size_t i = 0; i < strlen(str) - 1; i++) {
    if(count == 7) {
      printf("YES\n");
      return;
    }

    if(str[i] == str[i + 1]) count += 1;
    else count = 1;
  }

  printf("NO\n");
}

void N() {
  int lucky = 0;
  char str[20];
  fgets(str, sizeof(str), stdin);

  for(int i = 0; i < strlen(str); i++) {
    if(str[i] == '4' || str[i] == '7') lucky++;
  }

  printf((lucky == 4 || lucky == 7) ? "YES\n" : "NO\n");
}

void O() {
  int n, a_count = 0, d_count = 0;
  scanf("%i\n", &n);
  char s[n + 1];
  fgets(s, sizeof(s), stdin);

  for(int i = 0; i < n; i++) {
    s[i] == 'A' ? a_count++ : d_count++;
  }

  if(d_count < a_count) printf("Anton\n");
  else if(a_count < d_count) printf("Danik\n");
  else printf("Friendship\n");
}

void P() {
  int n, in, out, max = 0, curr = 0;

  scanf("%i\n", &n);

  for(int i = 0; i < n; i++) {
    scanf("%i %i", &out, &in);
    curr -= out;
    curr += in;
    if(curr > max) max = curr;
  }

  printf("%i\n", max);
}

void Q() {
  int n, h, w = 0, friend;
  scanf("%i %i\n", &n, &h);

  for(int i = 0; i < n; i++) {
    scanf("%i", &friend);
    (friend <= h) ? w++ : (w += 2);
  }

  printf("%i\n", w);
}

bool isUnique(int num) {
  int digits[10] = {0};

  while(num > 0) {
    int digit = num % 10;
    digits[digit]++;
    if(digits[digit] > 1) return false;

    num /= 10;
  }
  return true;
}

void R() {
  int year;
  scanf("%i", &year);

  year++;

  while(!isUnique(year)) year++;

  printf("%i\n", year);
}

void S() {
  int n, lucky[14] = {
    4,   7,   44,  47,  74,  77,  444,
    447, 474, 477, 744, 747, 774, 777
  };
  scanf("%i", &n);

  for(int i = 0; i < 14; i++) {
    if(n % lucky[i] == 0) {
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
}

void T() {
  int n, answer;
  scanf("%i", &n);

  for(int i = 0; i < n; i++) {
    scanf("%i", &answer);
    if(answer == 1) {
      printf("HARD\n");
      return;
    }
  }

  printf("EASY\n");
}

void U() {
  int n, in, max, count = 0;
  scanf("%i", &n);

  for(int i = 0; i < n; i++) {
    scanf("%i %i", &in, &max);
    if(max - in >= 2) count++;
  }
  printf("%i\n", count);
}

void swap(int* a, int* b) {
  int temp = *a; // Dereference `a` to get its value
  *a = *b;       // Dereference `a` and assign the value of `b`
  *b = temp;     // Dereference `b` and assign the stored value
}

void bubbleSort(int arr[], size_t length) {
  for(size_t i = length - 1; 0 < i; i--) {
    for(size_t j = 0; j < i; j++) {
      if(arr[i] < arr[j]) swap(&arr[i], &arr[j]);
    }
  }
}

void V() {
  int n, a, b, c, d, left, right;
  scanf("%i", &n);

  for(int i = 0; i < n; i++) {
    scanf("%i %i %i %i", &a, &b, &c, &d);
    int arr[4] = {a, b, c, d};
    bubbleSort(arr, 4);

    left = a < b ? b : a;
    right = c < d ? d : c;

    bool pass = (left == arr[2] || left == arr[3])
                && (right == arr[2] || right == arr[3]);

    if(pass) printf("YES\n");
    else printf("NO\n");
  }
}

void W() {
  char event;
  int n, value, seats = 0, people = 0;
  scanf("%i", &n);

  for(int i = 0; i < n; i++) {
    scanf(" %c %i", &event, &value);

    switch(event) {
      case 'P':
      case 'p':
        people += value;
        break;
      case 'B':
      case 'b':
        if(people <= value) {
          seats = value - people;
          people = 0;
        } else {
          people -= value;
          seats = 0;
        }
        if(people <= 0 && 0 < seats) {
          printf("YES\n");
        } else printf("NO\n");
        break;
    }
  }
}

int main() {
  W();
  return 0;
}
