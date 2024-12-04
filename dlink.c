#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *start;

void insertFirst() {
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("\n Memory allocation failed.\n");
        return;
    }

    printf("\n Enter the data: ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        temp->right = start;
        start->left = temp;
        start = temp;
    }
}

void insertLast() {
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("\n Memory allocation failed.\n");
        return;
    }

    printf("\n Enter the data: ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        node *ptr = start;
        while (ptr->right != NULL) {
            ptr = ptr->right;
        }

        ptr->right = temp;
        temp->left = ptr;
    }
}

void deleteFirst() {
    if (start == NULL) {
        printf("\n Underflow.\n");
        return;
    }

    node *temp = start;
    start = start->right;
    if (start != NULL) {
        start->left = NULL;
    }
    free(temp);
}

void deleteLast() {
    if (start == NULL) {
        printf("\n Underflow.\n");
        return;
    }

    node *ptr = start;
    while (ptr->right != NULL) {
        ptr = ptr->right;
    }

    if (ptr == start) {
        start = NULL;
    } else {
        ptr->left->right = NULL;
        free(ptr);
    }
}

void display() {
    if (start == NULL) {
        printf("\n List is Empty.\n");
        return;
    }

    node *ptr = start;
    while (ptr != NULL) {
        printf(" %d ", ptr->data);
        ptr = ptr->right;
    }
}

void sortList() {
    if (start == NULL || start->right == NULL) {
        return; // List is empty or has only one node
    }

    int swapped;
    node *ptr;
    node *last = NULL;

    do {
        swapped = 0;
        ptr = start;

        while (ptr->right != last) {
            if (ptr->data > ptr->right->data) {
                // Swap the data of the nodes
                int temp = ptr->data;
                ptr->data = ptr->right->data;
                ptr->right->data = temp;
                swapped = 1;
            }
            ptr = ptr->right;
        }
        last = ptr;  // Reduce the range of sorting
    } while (swapped);
    printf("List sorted");
}

void reverseList() {
    if (start == NULL || start->right == NULL) {
        return; // List is empty or has only one node
    }

    node *temp = NULL;
    node *current = start;

    while (current != NULL) {
        // Swap the left and right pointers of each node
        temp = current->left;
        current->left = current->right;
        current->right = temp;
        current = current->left;
    }

    if (temp != NULL) {
        start = temp->left;  // The last node processed will be the new head
    }
    printf("List reversed");
}

int main() {
    start = NULL;
    int ch;

    while (1) {
        printf("\n 1 for Insert First ");
        printf(" 2 for Insert Last ");
        printf(" 3 for Delete First ");
        printf(" 4 for Delete Last ");
        printf(" 5 for Display ");
        printf(" 6 for Exit ");
        printf(" 7 for Sort List ");
        printf(" 8 for Reverse List ");
        printf("\n Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insertFirst();
                break;

            case 2:
                insertLast();
                break;

            case 3:
                deleteFirst();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(1);

            case 7:
                sortList();
                break;

            case 8:
                reverseList();
                break;

            default:
                printf("\n Invalid choice.\n");
        }
    }
}
