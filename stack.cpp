#include "stack.h"

#include <iostream>

void InitializeStack(Stack *pStack) {
  pStack->top = nullptr;
  pStack->size = 0;
}

StackNode *CreateNode(StackEntry item) {
  StackNode *pStackNode = (StackNode *)malloc(sizeof(StackNode));
  pStackNode->entry = item;
  pStackNode->next = nullptr;
  return pStackNode;
}

void Push(Stack *pStack, StackEntry item) {
  StackNode *pStackNode = CreateNode(item);
  pStackNode->next = pStack->top;
  pStack->top = pStackNode;
  pStack->size++;
}

void Pop(Stack *pStack, StackEntry *item) {
  StackNode *pStackNode = pStack->top;
  *item = pStackNode->entry;
  pStack->top = pStackNode->next;
  free(pStackNode);
  pStack->size--;
}

int StackEmpty(Stack *pStack) { return pStack->top == nullptr; }

int StackFull(Stack *pStack) { return 0; }

void ClearStack(Stack *pStack) {
  StackNode *pStackNode = pStack->top;
  while (pStackNode) {
    pStack->top = pStackNode->next;
    free(pStackNode);
    pStackNode = pStack->top;
  }
  pStack->size = 0;
}

// int stackSize(Stack *pStack) {
//   int size;
//   StackNode *pStackNode = pStack -> top;
//   for (size = 0; pStackNode; pStackNode = pStackNode -> next) {
//     size++;
//   }
//   return size;
// }

int StackSize(Stack *pStack) { return pStack->size; }

void TraverseStack(Stack *pStack, void (*pVisit)(StackEntry item)) {
  StackNode *pStackNode = pStack->top;
  while (pStackNode) {
    (*pVisit)(pStackNode->entry);
    pStackNode = pStackNode->next;
  }
}

// Different version of traverse stack used for loop
// void traverseStack(Stack *pStack, void (*pVisit)(StackEntry *item)) {
//   for (StackNode *pStackNode = pStack -> top; pStackNode; pStackNode = pStackNode -> next) {
//     (*pVisit)(pStackNode -> entry);
//   }
// }