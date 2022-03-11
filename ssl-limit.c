//
// Single linked list with upper node limit
//

#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node* next;
};

#define MAX 10
struct Node *avail = NULL;
int count = 0;

// This function prints contents of linked list starting from
// the given node
void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

// This function creates a node with data x and appends it to a linked list
void appendNode(struct Node** list, int x)
{
    struct Node* new = NULL;
    struct Node* last = *list;
    
    if (count < MAX) {
       new = (struct Node*)malloc(sizeof(struct Node));
       new->data = x;
       new->next = NULL;
    
       count += 1;
       
       // empty list, so the new node will be the head
       if (*list == NULL) {
          *list = new;
          return;
      }

      // loop to the end
      while (last->next != NULL)
          last = last->next;

      last->next = new;
    } else {
        if (avail == NULL) {
            avail = *list;
        }
        avail->data = x;
        avail = avail->next;
    }
    
}
 
int main()
{
    struct Node* Alist = NULL;
    int i;

    for (i=0;i<22; i++) {
        appendNode(&Alist,i);
    }
    
    printList(Alist);
    
    return 0;
}
