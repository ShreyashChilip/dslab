#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Global head pointer for the linked list
struct Node* head = NULL;

// Function prototypes
void createList(int data);
void insertAtBeginning(int data);
void insertAtPosition(int data, int position);
void insertAtEnd(int data);
void deleteAtBeginning();
void deleteAtPosition(int position);
void deleteAtEnd();
void displayList();
void displayReverseList();

// Main function to demonstrate linked list operations
int main() {
    int choice, value, position;
    do {
        printf("\n\n--- Doubly Linked List Operations ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Position\n");
        printf("4. Insert at End\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at Position\n");
        printf("7. Delete at End\n");
        printf("8. Display List\n");
        printf("9. Display Reverse List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (head != NULL) {
                    printf("List is already created.\n");
                } else {
                    printf("Enter the value for the first node: ");
                    scanf("%d", &value);
                    createList(value);
                    printf("List created successfully.\n");
                }
                break;

            case 2:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                printf("Node inserted at the beginning.\n");
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;

            case 4:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                printf("Node inserted at the end.\n");
                break;

            case 5:
                deleteAtBeginning();
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;

            case 7:
                deleteAtEnd();
                break;

            case 8:
                displayList();
                break;

            case 9:
                displayReverseList();
                break;

            case 10:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != 10);

    return 0;
}

// Function to create the list with the first node
void createList(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert a node at a specific position in the list
void insertAtPosition(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        printf("Node inserted at position %d.\n", position);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        printf("Node inserted at position %d.\n", position);
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node from the beginning of the list
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("Node deleted from the beginning.\n");
    }
}

// Function to delete a node from a specific position in the list
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("Node deleted from position %d.\n", position);
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
    } else {
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        free(temp);
        printf("Node deleted from position %d.\n", position);
    }
}

// Function to delete a node from the end of the list
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from the end.\n");
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        printf("Node deleted from the end.\n");
    }
}

// Function to display the linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        printf("Doubly Linked List: ");
        while (temp != NULL) {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to display the linked list in reverse order
void displayReverseList() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        printf("Doubly Linked List in Reverse: ");
        while (temp != NULL) {
            printf("%d <-> ", temp->data);
            temp = temp->prev;
        }
        printf("NULL\n");
    }
}