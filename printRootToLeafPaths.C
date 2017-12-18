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

void printPaths(Node *root, vector<int> &nodes)
{
    if(root == NULL)
        return;

    // 
    // store the node data in the vector
    //
    nodes.push_back(root->data);
    if(root->left == NULL && root->right == NULL)
    {
        for(auto v : nodes)
            cout << v << " ";
 
         cout << endl;
         nodes.pop_back();
    }
    else
    {
        printPaths(root->left, nodes);
        printPaths(root->right, nodes);
        nodes.pop_back();
    }
}

void printInOrder(Node *root)
{
    if(root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPathsRecur(Node *root, int paths[], int pathLen)
{
    if(root == NULL)
        return;

    paths[pathLen] = root->data;
    pathLen++;

    if(root->left == NULL && root->right == NULL)
    {
        //
        // print the array
        //
        for(int i = 0; i < pathLen; i++)
        {
            cout << paths[i] << " ";
        }
        cout << endl;
    }
    else
    {
        printPathsRecur(root->left, paths, pathLen);
        printPathsRecur(root->right, paths, pathLen);
    }
}

int main()
{
  Node *root = allocateNode(1);
  root->left        = allocateNode(2);
  root->right       = allocateNode(3);
  root->left->left  = allocateNode(4);
  root->left->right = allocateNode(5); 
  root->right->left = allocateNode(6);
  root->right->right = allocateNode(7);
  root->left->right->left = allocateNode(8);
  root->right->right->left = allocateNode(9);
 
  // Print all root-to-leaf paths of the input tree
  printInOrder(root); 
  cout << endl;

  vector<int> nodes;
  printPaths(root, nodes);

  cout << endl;

  int paths[100];
  printPathsRecur(root, paths, 0);
  return 0;
}
