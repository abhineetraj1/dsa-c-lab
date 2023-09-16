#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return 1; // Element found
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return 0; // Element not found
}

int main() {
    int size, target;
    
    printf("Enter number of elements: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter elements in sorted order: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to be searched: ");
    scanf("%d", &target);
    
    int found = binarySearch(arr, size, target);
    
    if (found) {
        printf("Element found\n");
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}
