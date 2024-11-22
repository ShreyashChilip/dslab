#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // For measuring time

// Function prototypes
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
void merge(int arr[], int l, int m, int r);
int partition(int arr[], int low, int high);
void printArray(int arr[], int n);

int main() {
    int choice, n, i;
    clock_t start, end;
    double time_taken;

    // Taking user choice input
    printf("Choose the sorting technique:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Quick Sort\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    // Taking array size input
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    // Taking array elements input
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Measuring time
    start = clock(); // Start the clock

    // Switch-case for sorting selection
    switch(choice) {
        case 1:
            printf("Performing Bubble Sort...\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("Performing Insertion Sort...\n");
            insertionSort(arr, n);
            break;
        case 3:
            printf("Performing Merge Sort...\n");
            mergeSort(arr, 0, n - 1);
            break;
        case 4:
            printf("Performing Quick Sort...\n");
            quickSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    end = clock(); // End the clock

    // Calculate time taken
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Printing sorted array
    printf("Sorted Array: ");
    printArray(arr, n);

    // Print time taken
    printf("Time taken for sorting: %f seconds\n", time_taken);

    return 0;
}

// Function to print array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
}

// Function to merge two subarrays of arr[]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Create temporary arrays
    int L[n1], R[n2];
    
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    // Merge the temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
