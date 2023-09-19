#include <iomanip>
#include <iostream>

#include "stack.cpp"

typedef int StackEntry;

using namespace std;

void print(int item) { cout << item << " "; }

int main() {
  Stack s;

  InitializeStack(&s);

  Push(&s, 10);
  Push(&s, 20);
  Push(&s, 30);

  TraverseStack(&s, print);

  return 0;
}