#include <stdio.h>
#include <stdlib.h>

struct MyStruct {
  int i;
  double d;
  char a[5];
};

int main() {
  //   void *p = malloc(sizeof(int)); throws error
  int *p1 = (int *)malloc(sizeof(int));
  printf("address=%p, value=%d\n", p1, *p1);

  int *p2 = (int *)malloc(sizeof(int));
  printf("address=%p, value=%d\n", p2, *p2);

  int *p3 = (int *)malloc(sizeof(int));
  printf("address=%p, value=%d\n", p3, *p3);

  // reserve memory for several integers
  int *p4 = (int *)malloc(3 * sizeof(int));
  printf("address=%p, value=%d\n", p4, *p4);

  // Memory for Arrays and Structs
  MyStruct *p = (MyStruct *)calloc(4, sizeof(MyStruct));
  p[0].i = 1;
  p[0].d = 3.14159;
  p[0].a[0] = 'a';

  return 0;
}