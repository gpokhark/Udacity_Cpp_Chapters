int main() {
  // initialize some variables on the stack
  int i, j, *p;

  // correct usage of lvalues and rvalues

  i = 42;  // i is an lvalue and 42 is an rvalue

  p = new int;
  *p = i;  // the dereferenced pointer is an lvalue
  delete p;

  ((i < 42) ? i : j) =
      23;  // the conditional operator returns an lvalue (eiter i or j)

  // incorrect usage of lvalues and rvalues
  // 42 = i; // error : the left operand must be an lvalue
  // j * 42 = 23; // error : the left operand must be an lvalue

  return 0;
}