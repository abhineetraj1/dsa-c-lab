#include <stdio.h>

// Function to insert an element at a specific position
void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= position && position > 0) {
        for (int i = *size; i >= position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position - 1] = element;
        (*size)++;
        printf("Element inserted\n");
    } else {
        printf("Invalid position for insertion\n");
    }
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int *size, int position) {
    if (position > 0 && position <= *size) {
        for (int i = position - 1; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted\n");
    } else {
        printf("Invalid position for deletion\n");
    }
}

// Function to perform linear search
int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i + 1; // Element found at position i+1
        }
    }
    return -1; // Element not found
}

// Function to traverse and print the array
void traverseArray(int arr[], int size) {
    printf("Array Elements:");
    for (int i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    // Read the size of the array
    printf("Enter size n: ");
    scanf("%d", &n);

    int arr[n];
    int size = n;

    // Input array elements
    printf("Enter Array elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int option;
    do {
        printf("\n***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                {
                    int element, position;
                    printf("Element to insert: ");
                    scanf("%d", &element);
                    printf("Enter Position: ");
                    scanf("%d", &position);
                    insertElement(arr, &size, element, position);
                }
                break;

            case 2:
                {
                    int position;
                    printf("Enter Position to delete: ");
                    scanf("%d", &position);
                    deleteElement(arr, &size, position);
                }
                break;

            case 3:
                {
                    int element;
                    printf("Element to search: ");
                    scanf("%d", &element);
                    int position = linearSearch(arr, size, element);
                    if (position != -1) {
                        printf("Element found at position %d\n", position);
                    } else {
                        printf("Element not found\n");
                    }
                }
                break;

            case 4:
                traverseArray(arr, size);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option. Please enter a valid option.\n");
                break;
        }
    } while (option != 5);

    return 0;
}
