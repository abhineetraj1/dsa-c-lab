#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specific position
void insertNode(struct Node **head, int data, int position) {
    struct Node *newNode = createNode(data);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted.\n");
        return;
    }

    struct Node *temp = *head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position for insertion.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted.\n");
}

// Function to delete a node from a specific position
void deleteNode(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (position == 1) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node deleted.\n");
        return;
    }

    struct Node *prev = NULL;
    struct Node *temp = *head;
    int count = 1;

    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position for deletion.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted.\n");
}

// Function to count nodes in the linked list
int countNodes(struct Node *head) {
    int count = 0;
    struct Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to traverse and print the linked list
void traverseList(struct Node *head) {
    struct Node *current = head;
    printf("The list is: ");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to search for an element in the linked list
int searchElement(struct Node *head, int element) {
    int position = 0;
    struct Node *current = head;
    while (current != NULL) {
        position++;
        if (current->data == element) {
            return position;
        }
        current = current->next;
    }
    return -1;
}

// Function to sort the linked list in ascending order using bubble sort
void sortList(struct Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // List is empty or has only one node, no sorting needed
    }

    int swapped;
    struct Node *ptr1;
    struct Node *ptr2 = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != ptr2) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data of ptr1 and ptr1->next
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}

// Function to reverse the linked list
void reverseList(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    struct Node *head = NULL;
    int n, choice, data, position, element;

    // Input the number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input the elements of the linked list
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&head, data, i + 1);
    }

    // Menu-driven loop
    do {
        printf("\nMENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traverse\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertNode(&head, data, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 3:
                printf("The total number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                printf("Enter element to be searched: ");
                scanf("%d", &element);
                position = searchElement(head, element);
                if (position != -1) {
                    printf("Element found at node-%d\n", position);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 6:
                sortList(&head);
                printf("List sorted in ascending order.\n");
                break;
            case 7:
                reverseList(&head);
                printf("List reversed.\n");
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}
