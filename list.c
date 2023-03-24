#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* newList = (List*)malloc(sizeof(List));
  newList->head = NULL;
  newList->tail = NULL;
  newList->current = NULL;
  
     return newList;
}

void * firstList(List * list) {
  if(list->head == NULL)
    
    return NULL;
      
  list->current =list->head;
  return list->current->data;
}

void * nextList(List * list) {
  if(list->current == NULL || list->current->next == NULL)
    return NULL;

  list->current = list->current->next;
  return list->current->data;
}

void * lastList(List * list) {
  if(list->tail == NULL)
    return NULL;
  list->current = list->tail;
  return list->tail->data;
}

void * prevList(List * list) {
  if(list->current == NULL || list->current->prev == NULL)
    return NULL;
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) {
  Node* newNode = createNode(data);
  if(list->head == NULL)
  {
    list->head = newNode;
    list->tail = newNode;
    list->current = newNode;
    
  } else 
  {
    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
  }
}

void pushBack(List * list, void * data) {
node* newNode = createNode(data);
  if (list->current == NULL) pushFront(list,data);
  else
    newNode->next = list->current->next;
    newNode->next = list->current;

      if(list->current->next != NULL)
        list->current->next->prev = newNode;
    list->current->next = newNode;
  list->current = newNode;
  if(newNode->next == NULL)
    list->tail=newNode;



  //implementar esto?
    //list->current = list->tail;
    //pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}