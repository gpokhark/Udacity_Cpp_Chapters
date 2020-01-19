#include <stdio.h>
#include <stdlib.h>

int main() {
  // reserve memory for two integers
  int *p = (int *)malloc(2 * sizeof(int));
  p[0] = 1;
  p[1] = 2;

  // resize memory to hold four integers
  p = (int *)realloc(p, 4 * sizeof(int));
  p[2] = 3;
  p[3] = 4;

  // resize memory again to hold two integers
  p = (int *)realloc(p, 2 * sizeof(int));

  printf("address=%p, value=%d\n", p + 0, *(p + 0));  // valid
  printf("address=%p, value=%d\n", p + 1, *(p + 1));  // valid

  printf("address=%p, value=%d\n", p + 2, *(p + 2));  // INVALID: But does not throw error
  printf("address=%p, value=%d\n", p + 3, *(p + 3));  // INVALID: But does not throw error

  return 0;
}