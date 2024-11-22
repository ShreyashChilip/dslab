#include <iostream>
#include <cstdlib>
#define TABLE_SIZE 10

using namespace std;

// Define a node for the linked list (for chaining)
struct Node {
    int key;
    struct Node* next;
};

// Hash Table Array of Pointers
struct Node* hashTable[TABLE_SIZE];

// Function to initialize the hash table
void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key into the hash table
void insert(int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;

    // Insert at the beginning of the linked list at the hash table index
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
    cout << "Inserted key " << key << " at index " << index << endl;
}

// Function to search for a key in the hash table
int search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return index; // Key found
        }
        temp = temp->next;
    }
    return -1; // Key not found
}

// Function to delete a key from the hash table
void deleteKey(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Key " << key << " not found in the hash table." << endl;
        return;
    }

    // Remove the node from the linked list
    if (prev == NULL) {
        hashTable[index] = temp->next; // First node case
    } else {
        prev->next = temp->next;
    }
    free(temp);
    cout << "Deleted key " << key << " from index " << index << endl;
}

// Function to display the hash table
void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            cout << temp->key << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

// Main function
int main() {
    initializeHashTable();

    int choice, key;
    while (1) {
        cout << "\nHash Table Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter key to insert: ";
                cin >> key;
                insert(key);
                break;
            }
            case 2: {
                cout << "Enter key to search: ";
                cin >> key;
                int result = search(key);
                if (result != -1) {
                    cout << "Key " << key << " found at index " << result << endl;
                } else {
                    cout << "Key " << key << " not found." << endl;
                }
                break;
            }
            case 3: {
                cout << "Enter key to delete: ";
                cin >> key;
                deleteKey(key);
                break;
            }
            case 4: {
                displayHashTable();
                break;
            }
            case 5:
                exit(0);
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
