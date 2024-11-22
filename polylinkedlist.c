#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert a node into a linked list in descending order of exponents
void insertNode(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL && temp->next->exp > exp) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->exp == exp) {
            temp->next->coeff += coeff;
            free(newNode);
            if (temp->next->coeff == 0) { // Remove zero coefficient terms
                struct Node* toDelete = temp->next;
                temp->next = toDelete->next;
                free(toDelete);
            }
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Display the polynomial
void displayPolynomial(struct Node* poly) {
    if (!poly) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertNode(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertNode(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

// Multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    for (struct Node* ptr1 = poly1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (struct Node* ptr2 = poly2; ptr2 != NULL; ptr2 = ptr2->next) {
            int coeff = ptr1->coeff * ptr2->coeff;
            int exp = ptr1->exp + ptr2->exp;
            insertNode(&result, coeff, exp);
        }
    }
    return result;
}

// Free the linked list
void freePolynomial(struct Node* poly) {
    while (poly != NULL) {
        struct Node* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

// Function to take polynomial input from user
void inputPolynomial(struct Node** poly) {
    int terms;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &terms);
    for (int i = 0; i < terms; i++) {
        int coeff, exp;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertNode(poly, coeff, exp);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    printf("Enter polynomial 1:\n");
    inputPolynomial(&poly1);

    printf("Enter polynomial 2:\n");
    inputPolynomial(&poly2);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    displayPolynomial(sum);

    struct Node* product = multiplyPolynomials(poly1, poly2);
    printf("Product: ");
    displayPolynomial(product);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
    freePolynomial(product);

    return 0;
}
