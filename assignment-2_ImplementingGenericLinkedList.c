#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  void *data;
  size_t dataSize;
  struct ListNode *next;
} ListNode;

typedef struct GenericList {
  ListNode *head;
  size_t dataSize;
} GenericList;

ListNode* createListNode(GenericList *list, void *data) {
  ListNode *newListNode = (ListNode*)malloc(sizeof(ListNode));
  if (newListNode == NULL) {
    return NULL;
  }

  newListNode->data = malloc(list->dataSize);
  if (newListNode->data == NULL) {
    free(newListNode);
    return NULL;
  }

  memcpy(newListNode->data, data, list->dataSize);
  newListNode->next = NULL;
  return newListNode;
}

GenericList* initializeGenericList(size_t dataSize) {
  GenericList *list = (GenericList*)malloc(sizeof(GenericList));
  if (list == NULL) {
    return NULL;
  }

  list->head = NULL;
  list->dataSize = dataSize;
  return list;
}

void insertAtBeginning(GenericList *list, void *data) {
  ListNode *newListNode = createListNode(list, data);
  if (newListNode == NULL) {
    return;
  }

  newListNode->next = list->head;
  list->head = newListNode;
}

void printGenericList(GenericList *list, void (*printData)(void *data)) {
  ListNode *current = list->head;
  while (current != NULL) {
    printData(current->data);
    printf(" -> ");
    current = current->next;
  }
  printf("NULL\n");
}

void printInt(void *data) {
  int *intData = (int*)data;
  printf("%d", *intData);
}

void printFloat(void *data) {
  float *floatData = (float*)data;
  printf("%f", *floatData);
}

void freeGenericList(GenericList *list) {
  ListNode *current = list->head;
  while (current != NULL) {
    ListNode *temp = current;
    current = current->next;
    free(temp->data);
    free(temp);
  }
  free(list);
}

int main() {
  int intListSize;
  int floatListSize;

  GenericList *intList = initializeGenericList(sizeof(int));
  GenericList *floatList = initializeGenericList(sizeof(float));

  if(intList==NULL || floatList==NULL){
    printf("List Initialization Failed.\n");
    return -1;
  }

  printf("Enter Integer List Size : ");
  scanf("%d",&intListSize);
  printf("Enter Integer List Elements : ");

  while(intListSize--){
    int data;
    scanf("%d",&data);
    insertAtBeginning(intList, &data);
  }

  printf("Enter Float List Size : ");
  scanf("%d",&floatListSize);
  printf("Enter Float List Elements : ");

  while(floatListSize--){
    float data;
    scanf("%f",&data);
    insertAtBeginning(floatList, &data);
  }
  
  printf("Integer List: ");
  printGenericList(intList, printInt);

  printf("Float List: ");
  printGenericList(floatList, printFloat);

  freeGenericList(intList);
  freeGenericList(floatList);

  return 0;
}