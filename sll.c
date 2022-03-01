// A simple C program for traversal of a linked list
// based on https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
//
#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node* next;
};
 
// This function prints contents of linked list starting from
// the given node
void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

// This function creates a node  with data x and appends it to a linked list
void appendNode(struct Node** list, int x)
{
    struct Node* new = NULL;
    struct Node* last = *list;
    
    new = (struct Node*)malloc(sizeof(struct Node));
    new->data = x;
    new->next = NULL;
    
    // empty list, so the new node will be the head
    if (*list == NULL) {
        *list = new;
        return;
    }

    // loop to the end
    while (last->next != NULL)
        last = last->next;

    last->next = new;
    
}
 
int main()
{
    struct Node* Alist = NULL;
    int i;
    // create the list
 //   Alist = (struct Node*)malloc(sizeof(struct Node));
 //   Alist->data = 0;
 //   Alist->next = NULL;
    for (i=0;i<5; i++) {
        appendNode(&Alist,i);
    }
    
    printList(Alist);
    
    return 0;
}
