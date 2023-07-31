#include <iostream>
#include "stack.h"

void initializeStack(Stack *pStack) {
  pStack -> top = NULL;
  pStack -> size = 0;
}

StackNode * createNode(StackEntry item) {
  StackNode *pStackNode = (StackNode *)malloc(sizeof(StackNode));
  pStackNode -> entry = item;
  pStackNode -> next = NULL;
  return pStackNode;
}

void push(StackEntry item, Stack *pStack) {
  StackNode *pStackNode = createNode(item);
  pStackNode -> next = pStack -> top;
  pStack -> top = pStackNode;
  pStack -> size++;
}

void pop(StackEntry item, Stack *pStack) {
  StackNode *pStackNode = pStack -> top;
  item = pStackNode -> entry;
  pStack -> top = pStackNode -> next;
  free(pStackNode);
  pStack -> size--;
}

int stackEmpty(Stack *pStack) {
  return pStack -> top == NULL;
}

int stackFull(Stack *pStack) {
  return 0;
}

void clearStack(Stack *pStack) {
  StackNode *pStackNode = pStack -> top;
  while (pStackNode) {
    pStack -> top = pStackNode -> next;
    free(pStackNode);
    pStackNode = pStack -> top;
  }
  pStack -> size = 0;
}

// int stackSize(Stack *pStack) {
//   int size;
//   StackNode *pStackNode = pStack -> top;
//   for (size = 0; pStackNode; pStackNode = pStackNode -> next) {
//     size++;
//   }
//   return size;
// }

int stackSize(Stack *pStack) {
  return pStack -> size;
}

void traverseStack(Stack *pStack, void (*pVisit)(StackEntry item)) {
  StackNode *pStackNode = pStack -> top;
  while (pStackNode) {
    (*pVisit)(pStackNode -> entry);
    pStackNode = pStackNode -> next;
  }
}

// Different version of traverse stack used for loop
// void traverseStack(Stack *pStack, void (*pVisit)(StackEntry *item)) {
//   for (StackNode *pStackNode = pStack -> top; pStackNode; pStackNode = pStackNode -> next) {
//     (*pVisit)(pStackNode -> entry);
//   }
// }