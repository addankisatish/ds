#include<iostream>
#include<memory>
#include <limits.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *allocateNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printInOrder(Node *root)
{
    if(root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

bool isBSTUtil(Node *root, int min, int max)
{
    if(root == NULL)
        return true;

    if(root->data < min || root->data > max)
        return false;

    return (isBSTUtil(root->left, min, root->data-1) &&
            isBSTUtil(root->right, root->data+1, max));
}

bool isBST(Node *root)
{
    if(root == NULL)
        return true;
    else
        return isBSTUtil(root, INT_MIN, INT_MAX);
}

bool isBST(Node *root, Node *prev)
{
    if(root)
    {
        if(!isBST(root->left, prev))
            return false;

        if(prev != NULL && prev->data <= root->data)
            return false;
        
        prev = root;

        if(!isBST(root->right, prev))
            return false;
    }
    return true;
}

int main()
{
    Node *root = allocateNode(3);
    root->left        = allocateNode(2);
    root->right       = allocateNode(5);
    root->left->left  = allocateNode(1);
    root->left->right = allocateNode(4);

     
    if (isBST(root))
        cout << "Is BST" << endl;
    else
        cout << "Not a BST" << endl;

    Node *prev = NULL;
    if (isBST(root, prev))
        cout << "Is BST" << endl;
    else
        cout << "Not a BST" << endl;
 
    return 0;
}
