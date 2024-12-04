#include <stdio.h>
#include <stdlib.h>

void initDeque(int *front, int *rear, int *count) {
    *front = -1;
    *rear = -1;
    *count = 0;
}

int isFull(int count, int max) {
    return count == max;
}

int isEmpty(int count) {
    return count == 0;
}

void insertFront(int deque[], int *front, int *rear, int *count, int max, int value) {
    if (isFull(*count, max)) {
        printf("Deque is full!\n");
        return;
    }

    if (*front == -1) {
        *front = *rear = 0;
    } else if (*front == 0) {
        *front = max - 1;
    } else {
        (*front)--;
    }

    deque[*front] = value;
    (*count)++;
    printf("Inserted %d at the front\n", value);
}

void insertRear(int deque[], int *front, int *rear, int *count, int max, int value) {
    if (isFull(*count, max)) {
        printf("Deque is full!\n");
        return;
    }

    if (*rear == -1) {
        *front = *rear = 0;
    } else if (*rear == max - 1) {
        *rear = 0;
    } else {
        (*rear)++;
    }

    deque[*rear] = value;
    (*count)++;
    printf("Inserted %d at the rear\n", value);
}

void deleteFront(int deque[], int *front, int *rear, int *count, int max) {
    if (isEmpty(*count)) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deleted %d from the front\n", deque[*front]);

    if (*front == *rear) {
        *front = *rear = -1;
    } else if (*front == max - 1) {
        *front = 0;
    } else {
        (*front)++;
    }

    (*count)--;
}

void deleteRear(int deque[], int *front, int *rear, int *count, int max) {
    if (isEmpty(*count)) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deleted %d from the rear\n", deque[*rear]);

    if (*front == *rear) {
        *front = *rear = -1;
    } else if (*rear == 0) {
        *rear = max - 1;
    } else {
        (*rear)--;
    }

    (*count)--;
}

void displayDeque(int deque[], int front, int rear, int count, int max) {
    if (isEmpty(count)) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % max;
    }
    printf("\n");
}

int main() {
    int *deque, front, rear, count, max, choice, value;

    printf("Enter the size of the deque: ");
    scanf("%d", &max);

    deque = (int *)malloc(max * sizeof(int));

    initDeque(&front, &rear, &count);

    while (1) {
        printf("\n1. Insert Front  2. Insert Rear  3. Delete Front  4. Delete Rear  5. Display  6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(deque, &front, &rear, &count, max, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(deque, &front, &rear, &count, max, value);
                break;
            case 3:
                deleteFront(deque, &front, &rear, &count, max);
                break;
            case 4:
                deleteRear(deque, &front, &rear, &count, max);
                break;
            case 5:
                displayDeque(deque, front, rear, count, max);
                break;
            case 6:
                free(deque);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
