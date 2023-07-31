#include <iostream>
#include <iomanip>
#include "stack.cpp"

typedef int StackEntry;

using namespace std;

void print(int item) {
  cout << "\n" << item;
}

int main() {
  Stack s;

  initializeStack(&s);

  push(10, &s);
  push(20, &s);
  push(30, &s);

  traverseStack(&s, print);

  return 0;
}