// lab08 - recLinkedListFuncs.cpp
// Aarogya Pandey
// June 4th, 2020

#include "linkedList.h"
#include "linkedListFuncs.h"
#include <iostream>
#include <algorithm>
using namespace std;


//head: ptr to a Node * which is the head of a linked list
//return sum of all values in linked list using a recursive approach
//if head is null return 0
int recursiveSum(Node* head) {
  if (head != NULL) {
    return head->data + recursiveSum(head->next);
  }
  else return 0;
}

//head: ptr to a Node* which is the head of a linked list
//return the largest value in the linked list using a recursive approach
//you may assume the list has at least one element
int recursiveLargestValue(Node* head) {
  if (head->next == NULL) {
    return head->data;
  }
  else {
    int num = recursiveLargestValue(head->next);
    if (head->data <= num)
      return num;
    else
        return head->data; 
  }
}
