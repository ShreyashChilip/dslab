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
    //Traverse until finding empty node
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
int findHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}
void printLeafNodes(struct Node* node) {
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) {
            printf("%d ", node->data);
        }
        printLeafNodes(node->left);
        printLeafNodes(node->right);
    }
}
void printCurrentLevel(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
void printLevelOrder(struct Node* root) {
    int h = findHeight(root);
    for (int i = 1; i <= h; i++) {
        printf("Level %d: ",i);
        printCurrentLevel(root, i);
        printf("\n");
    }
}
void mirrorTree(struct Node* node) {
    if (node == NULL) {
        return;
    } else {
        struct Node* temp;
        mirrorTree(node->left);
        mirrorTree(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
int main() {
    struct Node* root = NULL;
    int choice, value;
    while (1) {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert\n2. Find Height\n3. Print Leaf Nodes\n4. Level-wise Display\n5. Mirror Tree\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (root == NULL && choice != 1 && choice != 6) {
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
                printf("Height of the tree: %d\n", findHeight(root));
                break;
            case 3:
                printf("Leaf Nodes: ");
                printLeafNodes(root);
                printf("\n");
                break;
            case 4:
                printf("Level-wise Display:\n");
                printLevelOrder(root);
                break;
            case 5:
                mirrorTree(root);
                printf("Mirror Image created.\n");
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}