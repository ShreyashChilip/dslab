#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;  // Initially, the queue is empty

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Function to enqueue (insert) an element into the queue
void enqueue(int element) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d.\n", element);
    } else {
        if (front == -1)  // If inserting the first element
            front = 0;
        rear++;
        queue[rear] = element;
        printf("%d enqueued into the queue.\n", element);
    }
}

// Function to dequeue (remove) an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! The queue is empty.\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        front++;
        if (front > rear) {  // Reset queue if it becomes empty
            front = rear = -1;
        }
    }
}

// Function to display the current queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, element, maxSize;

    printf("Enter the maximum size of the queue: ");
    scanf("%d", &maxSize);

    if (maxSize > MAX) {
        printf("Maximum allowed queue size is %d.\n", MAX);
        maxSize = MAX;
    }

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear < maxSize - 1) {
                    printf("Enter the element to enqueue: ");
                    scanf("%d", &element);
                    enqueue(element);
                } else {
                    printf("Queue Overflow! Cannot enqueue more elements.\n");
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}
