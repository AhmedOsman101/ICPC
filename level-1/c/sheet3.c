#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// void L() {
//   int n, q, start, end;
//   scanf("%i %i", &n, &q);

//   int a[n];

//   for (int i = 0; i < n; i++) scanf("%i", &a[i]);

//   for (int i = 0; i < q; i++) {
//     int sum = 0;
//     scanf("%i %i", &start, &end);
//     start--;

//     for (int j = start; j < end; j++) sum += a[j];

//     printf("%i\n", sum);
//   }
// }

void L() {
  int n, q, start, end;
  scanf("%i %i", &n, &q);

  int a[n];
  // Create prefix sum array (one size larger than input array)
  int prefix[n + 1];
  prefix[0] = 0;

  // Read input and build prefix sum array in one pass
  for (int i = 0; i < n; i++) {
    scanf("%i", &a[i]);
    prefix[i + 1] = prefix[i] + a[i];
  }

  // Process queries
  for (int i = 0; i < q; i++) {
    scanf("%i %i", &start, &end);
    start--; // Adjust for 0-based indexing

    // Calculate range sum in O(1) using prefix sums
    int sum = prefix[end] - prefix[start];
    printf("%i\n", sum);
  }
}

void M() {}

void N() {}

void O() {}

void P() {}

void Q() {}

bool isUnique(int num) {
  int digits[10] = {0};

  while (num > 0) {
    int digit = num % 10;
    digits[digit]++;

    if (digits[digit] > 1) return false;

    num /= 10;
  }

  return true;
}

void R() {}

void S() {}

void T() {}

void U() {}

void swap(int* a, int* b) {
  int temp = *a; // Dereference `a` to get its value
  *a = *b; // Dereference `a` and assign the value of `b`
  *b = temp; // Dereference `b` and assign the stored value
}

void bubbleSort(int arr[], size_t length) {
  for (size_t i = length - 1; 0 < i; i--) {
    for (size_t j = 0; j < i; j++) {
      if (arr[i] < arr[j]) swap(&arr[i], &arr[j]);
    }
  }
}

void V() {}

void W() {}

int main() {
  L();
  return 0;
}

