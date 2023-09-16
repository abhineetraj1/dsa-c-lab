#include <stdio.h>

// Function to perform insertion sort in ascending order
void insertionSortAscending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function to perform insertion sort in descending order
void insertionSortDescending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int size;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort in ascending order
    insertionSortAscending(arr, size);

    printf("Ascending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Sort in descending order
    insertionSortDescending(arr, size);

    printf("\nDescending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
