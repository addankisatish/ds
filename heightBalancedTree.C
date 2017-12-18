#include<iostream>
#include<memory>
#include<stdlib.h>
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

int height(Node *root)
{
    if(root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh) ? (lh+1) : (rh+1);
}

bool isHeightBalanced(Node *root)
{
    if(root == NULL)
        return true;

    int lheight = height(root->left);
    int rheight = height(root->right);

    if( (abs(lheight - rheight) <= 1) &&
        isHeightBalanced(root->left) && 
        isHeightBalanced(root->right) )
        return true;
    else
        return false;
}

bool isHeightBalancedOpt(Node *root, int &height)
{
    if(root == NULL)
    {
        height = 0;
        return true;
    }

    bool lbalanced = false;
    bool rbalanced = false;
    int lh = 0, rh = 0;

    lbalanced = isHeightBalancedOpt(root->left, lh);
    rbalanced = isHeightBalancedOpt(root->right, rh);

    height = ( lh > rh ) ? (lh + 1) : ( rh + 1);

    if( abs(lh - rh) > 1 )
        return false;
    else 
        return (lbalanced && rbalanced);
}

int main()
{
    Node *root = allocateNode(1);
    root->left = allocateNode(2);
    root->right = allocateNode(3);
    root->left->left = allocateNode(4);
    root->left->right = allocateNode(5);
    root->left->left->left = allocateNode(8);
 
    if(isHeightBalanced(root))
      cout << "Tree is balanced" << endl;
    else
      cout << "Tree is not balanced" << endl;
 
    return 0;
}
