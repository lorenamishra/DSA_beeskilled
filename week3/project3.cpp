
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of a contact
struct Node {
    char name[50];
    char phone[20];
    struct Node *left, *right;
};

// Create a new contact
struct Node* createNode(char name[], char phone[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a contact
struct Node* insert(struct Node* root, char name[], char phone[]) {

    if (root == NULL) {
        return createNode(name, phone);
    }

    int cmp = strcmp(name, root->name);

    if (cmp < 0) {
        root->left = insert(root->left, name, phone);
    }
    else if (cmp > 0) {
        root->right = insert(root->right, name, phone);
    }
    else {
        printf("Contact already exists!\n");
    }

    return root;
}

// Search for a contact
struct Node* search(struct Node* root, char name[]) {

    if (root == NULL || strcmp(name, root->name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    }

    return search(root->right, name);
}

// Find minimum node
struct Node* findMin(struct Node* root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Delete a contact
struct Node* deleteContact(struct Node* root, char name[]) {

    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(name, root->name);

    if (cmp < 0) {
        root->left = deleteContact(root->left, name);
    }
    else if (cmp > 0) {
        root->right = deleteContact(root->right, name);
    }
    else {

        // Case 1: No left child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: No right child
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct Node* temp = findMin(root->right);

        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);

        root->right = deleteContact(root->right, temp->name);
    }

    return root;
}

// Display contacts alphabetically
void inorder(struct Node* root) {

    if (root != NULL) {
        inorder(root->left);

        printf("Name: %-20s Phone: %s\n",
               root->name, root->phone);

        inorder(root->right);
    }
}

// Main function
int main() {

    struct Node* root = NULL;

    int choice;
    char name[50];
    char phone[20];

    while (1) {

        printf("\n===== CONTACT DIRECTORY =====\n");
        printf("1. Insert Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Enter phone number: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0';

                root = insert(root, name, phone);
                printf("Contact inserted successfully!\n");
                break;

            case 2:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                struct Node* found;
                found = search(root, name);

                if (found != NULL) {
                    printf("\nContact Found!\n");
                    printf("Name: %s\n", found->name);
                    printf("Phone: %s\n", found->phone);
                }
                else {
                    printf("Contact not found!\n");
                }
                break;

            case 3:
                printf("Enter name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                if (search(root, name) != NULL) {
                    root = deleteContact(root, name);
                    printf("Contact deleted successfully!\n");
                }
                else {
                    printf("Contact not found!\n");
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("Contact Directory is empty!\n");
                }
                else {
                    printf("\n--- Contact List (Alphabetical) ---\n");
                    inorder(root);
                }
                break;

            case 5:
                printf("Exiting Contact Directory...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
