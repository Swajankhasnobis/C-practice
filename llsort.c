#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to merge two sorted linked lists
struct Node* sortedMerge(struct Node* a, struct Node* b) {
    struct Node* result = NULL;

    // Base cases
    if (a == NULL) return b;
    if (b == NULL) return a;

    // Pick either a or b and recurse
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}
void frontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* fast;
    struct Node* slow;
    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is before the midpoint in the list, so split it in two
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    // Split head into 'a' and 'b' sublists
    frontBackSplit(head, &a, &b);

    // Recursively sort the sublists
    mergeSort(&a);
    mergeSort(&b);

    // Merge the two sorted lists together
    *headRef = sortedMerge(a,b);
}

// Function to push a node at the beginning of the list
void push(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to print nodes in a given linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


int main() {
    struct Node* res = NULL;
    struct Node* a = NULL;

    
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    printf("Linked List before sorting:\n");
    printList(a);
    mergeSort(&a);
    printf("Linked List after sorting:\n");
    printList(a);

    return 0;
}
