#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the largest element in the BST
int findLargest(struct Node* root) {
    if (root == NULL) {
        printf("BST is empty.\n");
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

// Function to find the smallest element in the BST
int findSmallest(struct Node* root) {
    if (root == NULL) {
        printf("BST is empty.\n");
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to find the height of a node in the BST
int findHeight(struct Node* root, int data) {
    if (root == NULL) {
        return -1;
    }

    if (data < root->data) {
        return 1 + findHeight(root->left, data);
    } else if (data > root->data) {
        return 1 + findHeight(root->right, data);
    } else {
        return 0;
    }
}

// Function to count the number of leaf nodes in the BST
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function for preorder traversal of the BST
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to find the minimum element in the BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node with a given key from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, data, choice;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    while (1) {
        printf("\nMAIN MENU\n");
        printf("1. Preorder\n");
        printf("2. Postorder\n");
        printf("3. Inorder\n");
        printf("4. Search\n");
        printf("5. Insert\n");
        printf("6. Largest\n");
        printf("7. Smallest\n");
        printf("8. Height\n");
        printf("9. Count leaf nodes\n");
        printf("10. Delete\n");
        printf("11. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 2:
                // Postorder traversal code here
                break;
            case 3:
                // Inorder traversal code here
                break;
            case 4:
                printf("Enter element to search in BST: ");
                scanf("%d", &data);
                if (findHeight(root, data) != -1) {
                    printf("Element %d found in BST.\n", data);
                } else {
                    printf("Element %d not found in BST.\n", data);
                }
                break;
            case 5:
                printf("Enter element to insert in BST: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Element %d inserted in BST.\n", data);
                break;
            case 6:
                printf("Largest element in BST: %d\n", findLargest(root));
                break;
            case 7:
                printf("Smallest element in BST: %d\n", findSmallest(root));
                break;
            case 8:
                printf("Enter element to find height: ");
                scanf("%d", &data);
                int height = findHeight(root, data);
                if (height == -1) {
                    printf("Element not found in BST.\n");
                } else {
                    printf("Height of %d: %d\n", data, height);
                }
                break;
            case 9:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 10:
                printf("Enter element to delete from BST: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Element %d deleted from BST.\n", data);
                break;
            case 11:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
