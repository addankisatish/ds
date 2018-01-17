#include<iostream>
#include<memory>
using namespace std;

//
// The diameter of T is the largest of the following:
// 1. The diameter of T's left subtree.
// 2. The diameter of T's right subtree
// 3. The longest path between leaves that go through the root of T
//    (which can be computed from the heights of subtrees of T)

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

int max(int a, int b)
{
    return (a > b) ? a : b;
}  

int height(Node *root)
{
    if(root == NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    return 1 + max(lheight, rheight);
}

int diameter(Node *root)
{
    if(root == NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(lheight+rheight+1, max(ldiameter, rdiameter));
}

int optDiameter(Node *root, int& height)
{
    if(root == NULL)
    {
        height = 0;
        return 0;
    }
    int lheight = 0, rheight = 0;
    int ldiameter = 0, rdiameter = 0;

    ldiameter = optDiameter(root->left, lheight);
    rdiameter = optDiameter(root->right, rheight);

    height = max(lheight, rheight) + 1;

    return max(lheight+rheight+1, max(ldiameter, rdiameter));
}

int main()
{
    Node *root = allocateNode(1);
    root->left = allocateNode(2);
    root->right = allocateNode(3);
    root->left->left = allocateNode(4);
    root->left->right = allocateNode(5);
    root->right->left = allocateNode(6);
    root->right->right = allocateNode(7);
    root->left->left->left = allocateNode(8);

    cout << "Diameter : " << diameter(root) << endl;

    int height = 0;
    cout << "Diameter : " << optDiameter(root, height) << endl;

    return 0;
}

