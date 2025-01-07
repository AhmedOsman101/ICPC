// #include <stdlib.h>
#include <string.h>
#include <stdio.h>

void K() {
  int n, x, y, z, x_sum = 0, y_sum = 0, z_sum = 0;
  scanf("%i", &n);



  for(int i = 0; i < n; i++) {
    scanf("%i %i %i", &x, &y, &z);

    x_sum += x;
    y_sum += y;
    z_sum += z;
  }

  if(x_sum != 0 || y_sum != 0 || z_sum != 0) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
}

void L() {
  int n, k;
  scanf("%i %i", &n, &k);

  for(int i = 0; i < k; i++) {
    (n % 10 != 0) ? n-- : (n /= 10);
  }
  printf("%i\n", n);
}

int M() {
  int count = 1;
  char str[100];
  fgets(str, sizeof(str), stdin);

  for(size_t i = 0; i < strlen(str) - 1; i++) {
    if(count == 7) {
      printf("YES\n");
      return 0;
    }

    if(str[i] == str[i + 1]) count += 1;
    else count = 1;
  }

  printf("NO\n");
  return 0;
}

void N() {
  int lucky = 0;
  char str[20];
  fgets(str, sizeof(str), stdin);

  for(size_t i = 0; i < strlen(str); i++) {
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
  //
}

void R() {
  //
}

void S() {
  //
}

void T() {
  //
}

void U() {
  //
}

void V() {
  //
}

void W() {
  //
}

int main() {
  P();
  return 0;
}
