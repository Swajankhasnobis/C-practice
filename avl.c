#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
} node;

node *create(int k) {
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL) { // Check for malloc failure
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    temp->data = k;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int getheight(node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int updateh(node *n) {
    if (n == NULL) return 0; // Important check
    return 1 + max(getheight(n->left), getheight(n->right));
}

int getbf(node *n) {
    if (n == NULL)
        return 0;
    return getheight(n->left) - getheight(n->right);
}

node *rrotate(node *y) {
    node *x = y->left;
    node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = updateh(y);
    x->height = updateh(x);
    return x;
}

node *lrotate(node *x) {
    node *y = x->right;
    node *t2 = y->left;
    y->left = x;
    x->right = t2;
    y->height = updateh(y);
    x->height = updateh(x);
    return y;
}

node *min_node(node *root) { // Renamed to avoid conflict with standard library min
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

node *insert(node *root, int k) {
    if (root == NULL)
        return create(k);
    else if (k < root->data)
        root->left = insert(root->left, k);
    else if (k > root->data)
        root->right = insert(root->right, k);
    else // Duplicate keys not allowed
        return root;

    root->height = updateh(root);
    int bf = getbf(root);

    // Rotations
    if (bf > 1 && k < root->left->data)
        return rrotate(root);
    if (bf < -1 && k > root->right->data)
        return lrotate(root);
    if (bf > 1 && k > root->left->data) {
        root->left = lrotate(root->left);
        return rrotate(root);
    }
    if (bf < -1 && k < root->right->data) {
        root->right = rrotate(root->right);
        return lrotate(root);
    }
    return root;
}
node *delete(node *root, int k) {
    if (root == NULL)
        return NULL;

    if (k < root->data)
        root->left = delete(root->left, k);
    else if (k > root->data)
        root->right = delete(root->right, k);
    else { // Node to be deleted found
        if (root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = min_node(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    // Update height and balance factor AFTER the recursive call
    if (root == NULL) return NULL; // Important: Check if root became NULL after deletion

    root->height = updateh(root);
    int bf = getbf(root);

    // Perform rotations
    if (bf > 1) {
        if (getbf(root->left) >= 0)
            return rrotate(root);
        else {
            root->left = lrotate(root->left);
            return rrotate(root);
        }
    }
    if (bf < -1) {
        if (getbf(root->right) <= 0)
            return lrotate(root);
        else {
            root->right = rrotate(root->right);
            return lrotate(root);
        }
    }

    return root;
}
void preorder(node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    node *root = NULL;
    int ch, x;
    while (1) {
        printf("1)Insert 2)Delete 3)Display 4)Exit Enter choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("enter data to be inserted :");
                scanf("%d", &x);
                root = insert(root, x);
                printf("Element inserted\n");
                break;
            case 2:
                printf("enter data to be deleted :");
                scanf("%d", &x);
                root = delete(root, x);
                printf("Element Deleted\n");
                break;
            case 3:
                printf("Inorder : ");
                inorder(root);
                printf("\nPreorder : ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                // Free all allocated memory before exiting (important!)
                // (Implementation for this is beyond the scope of this correction, but essential in real-world applications)
                exit(0); // Use exit(0) for successful exit
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}