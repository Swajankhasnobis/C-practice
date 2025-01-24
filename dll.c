include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
    int data;
    struct node *left;
    struct node *right;
} node;
node* start;
void insertLast()
 {
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
void bsort()
{
    if(start==NULL||start->right==NULL)
    {
        return;
    }
    node* temp1=start;
    node* temp2=;

}
int main()
{
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    insertLast();
    bsort()
}