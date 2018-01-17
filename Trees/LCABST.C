#include<iostream>
#include<memory>
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

Node *lcaBST(Node *root, int n1, int n2)
{
    if(root == NULL)
        return NULL;

    // if both n1 and n2 are smaller than root.
    if( n1 < root->data && n2 < root->data )
        return lcaBST(root->left, n1, n2);

    if( n1 > root->data && n2 > root->data )
        return lcaBST(root->right, n1, n2);

    return root;
}

Node *lcaBSTIterative(Node *root, int n1, int n2)
{
    while(root != NULL)
    {
        if(n1 < root->data && n2 < root->data)
            root = root->left;
        else if(n1 > root->data && n2 > root->data)
            root = root->right;
        else
            break;
    }
 
    return root;  
}

int main()
{
    Node *root        = allocateNode(20);
    root->left               = allocateNode(8);
    root->right              = allocateNode(22);
    root->left->left         = allocateNode(4);
    root->left->right        = allocateNode(12);
    root->left->right->left  = allocateNode(10);
    root->left->right->right = allocateNode(14);
 
    int n1 = 10, n2 = 14;
    Node *temp = lcaBST(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is: " << temp->data << endl;
    temp = lcaBSTIterative(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is: " << temp->data << endl;
 
    n1 = 14, n2 = 8;
    temp = lcaBST(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is: " << temp->data << endl;
    temp = lcaBSTIterative(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is: " << temp->data << endl;
 
    n1 = 10, n2 = 22;
    temp = lcaBST(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is: " << temp->data << endl;
    temp = lcaBSTIterative(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is: " << temp->data << endl;
 
    return 0;
}

