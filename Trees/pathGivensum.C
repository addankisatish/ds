#include<iostream>
#include<memory>
#include<vector>
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

bool hasPathSum(Node *root, int sum )
{
    if(root == NULL)
        return (sum == 0);

    int remainingSum = sum - root->data;
    if(root->left == NULL && root->right == NULL)
    {
        if(remainingSum == 0)
        {
            return true;
        }
        return false;
    }
    else
    {
        return(hasPathSum(root->left, remainingSum) ||
               hasPathSum(root->right, remainingSum));
    }
}

int main()
{
  Node *root = allocateNode(10);
  root->left        = allocateNode(8);
  root->right       = allocateNode(2);
  root->left->left  = allocateNode(3);
  root->left->right = allocateNode(5);
  root->right->left = allocateNode(2);
 
  int sum = 25;
  if(hasPathSum(root, sum))
  {
    cout << "There is a root-to-leaf path with sum : " << sum << endl;
  }
  else
  {
    cout << "There is no root-to-leaf path with sum : " << sum << endl;
  }
 
  return 0;
}
