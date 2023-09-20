#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("\nKhong the cap phat bo nho!");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    } else {
        printf("\nGia tri %d da ton tai trong cay!", value);
        exit(1);
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void deleteTree(Node* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int value;

    printf("Nhap gia tri (nhap gia tri am de dung nhap):\n");
    while (1) {
        scanf("%d", &value);
        if (value < 0) {
            break;
        }
        root = insertNode(root, value);
    }

    printf("\nCay nhi phan sau khi duoc tao la:\n");
    inOrderTraversal(root);

    deleteTree(root);

    return 0;
}

