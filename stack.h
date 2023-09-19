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

void InitializeStack(Stack *);
void Push(Stack *, StackEntry);
void Pop(Stack *, StackEntry *);
int StackEmpty(Stack *);
int StackFull(Stack *);
void ClearStack(Stack *);
int StackSize(Stack *);
void TraverseStack(Stack *, void (*)(StackEntry));