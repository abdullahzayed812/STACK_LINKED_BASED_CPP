#define LINKED_STACK

typedef int StackEntry;

#ifdef LINKED_STACK

typedef struct stackNode {
  StackEntry entry;
  struct stackNode *next;
} StackNode;

typedef struct stack {
  StackNode *top;
  int size;
} Stack;

#endif

void initializeStack(Stack *);
void push(StackEntry, Stack *);
void pop(StackEntry&, Stack *);
int stackEmpty(Stack *);
int stackFull(Stack *);
void clearStack(Stack *);
int stackSize(Stack *);
void traverseStack(Stack *, void (*)(StackEntry));