#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insertNode(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    if (root == NULL) {
        return newNode;
    }
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root; 

    while (front < rear) {
        struct Node* temp = queue[front++];  

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else {
            queue[rear++] = temp->left;  
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}
void inOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    printf("In-order Traversal: ");
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
    printf("\n");
}
void preOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    printf("Pre-order Traversal: ");
    while (top >= 0) {
        
        struct Node* node = stack[top--];
        printf("%d ", node->data);

        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
    printf("\n");
}
void postOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left != NULL) {
            stack1[++top1] = node->left;
        }
        if (node->right != NULL) {
            stack1[++top1] = node->right;
        }
    }
    printf("Post-order Traversal: ");
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
    printf("\n");
}
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (root == NULL && choice != 1 && choice != 5) {
            printf("Please insert a value first.\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                inOrderTraversal(root);
                break;
            case 3:
                preOrderTraversal(root);
                break;
            case 4:
                postOrderTraversal(root);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
