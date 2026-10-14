#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a value
struct Node* insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate values are not allowed.\n");

    return root;
}

// Pre-order: Root, Left, Right
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// In-order: Left, Root, Right
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Post-order: Left, Right, Root
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search a value
struct Node* search(struct Node *root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

// Find the minimum value node
struct Node* findMin(struct Node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// Delete a value
struct Node* deleteNode(struct Node *root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        // Case 1: No left child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: No right child
        if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


int main() {
    struct Node *root = NULL;
    struct Node *result;
    int choice, value;

    while(1){
        printf("\n\n--- BINARY SEARCH TREE ---\n");
        printf("1. Insert\n");
        printf("2. Tree Traversal\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter -1 to stop; Enter a value:");
                scanf("%d",&value);
                while(value!=-1){
                root = insert(root, value);
                printf("Enter -1 to stop; Enter a value:");
                scanf("%d",&value);
                }
                break;

            case 2:
                printf("\nThe Preorder display : ");
                preorder(root);
                printf("\nThe Inorder display : ");
                inorder(root);
                printf("\nThe Postorder display : ");
                postorder(root);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = search(root, value);
                if (result != NULL)
                    printf("%d found in the BST.\n", value);
                else
                    printf("%d not found in the BST.\n", value);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                if (search(root, value) != NULL) {
                    root = deleteNode(root, value);
                    printf("Value deleted successfully.\n");
                } else {
                    printf("Value not found in the BST.\n");
                }
                break;

           case 5: exit(0);
            default: printf("Invalid choice");
        }
    }
    return 0;
}
