#include <iostream>
using namespace std;

typedef struct Tree{
    int val;
    struct Tree* left;
    struct Tree* right;
} node;

node* createNode(int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

Tree* mirrorTree(node* root)
{
   
    if (root == NULL)
        return root;
    node* t = root->left;
    root->left = root->right;
    root->right = t;

    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);

    return root;
}

int main()
{

    node* tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);
    printf("Inorder of original tree: ");
    inorder(tree);

    mirrorTree(tree);

    printf("\nInorder of Miror tree: ");
    inorder(tree);
    return 0;
}