#include <stdio.h>
#include <stdlib.h>

#define max 3

int queue[max];
int front = -1, rear = -1;

void enque() {
    int item;
    if (rear == max - 1) {   
        printf("Overflow! Cannot insert the element\n");
        return;
    }

    printf("Enter the item to insert: ");
    scanf("%d", &item);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = item;

    printf("Inserted %d into the queue", item);
}

void deque() {
    if (front == -1 || front > rear) {
        printf("Underflow! Empty queue, cannot delete\n");
        return;
    }

    printf("Deleted %d from the queue", queue[front]);
    front++;

    if (front > rear)
        front = rear = -1;
}

void display() {
    if (front == -1) {
        printf("Empty queue! Nothing to display\n");
        return;   
    }

    printf("The queue elements are: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main() {
    int choice, item;

    while (1) {
        printf("1.insert 2.delete 3.display 4.exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("Enter the item to insert:");
            scanf("%d", &item);
            enque(item);
            break;
            case 2: deque(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid input! Try again");
        }
        printf("\n");
    }
}
