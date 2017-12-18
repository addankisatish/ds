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

bool areMirrorTrees(Node *root1, Node *root2)
{
   if(root1 == NULL && root2 == NULL)
       return true;

   if(root1 == NULL || root2 == NULL)
       return false;

   if(root1->data != root2->data)
       return false;

   return (areMirrorTrees(root1->left, root2->right) &&
           areMirrorTrees(root1->right, root2->left) ); 
    
}

void constructMirrorTree(Node *root)
{
    if(root == NULL)
        return;

    constructMirrorTree(root->left);
    constructMirrorTree(root->right);

    //
    // Swap the links
    //
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    return;
}

void printInOrder(Node *root)
{
    if(root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main()
{
  Node *root = allocateNode(1);
  root->left  = allocateNode(2);
  root->right = allocateNode(3);
  root->left->left  = allocateNode(4);
  root->left->right = allocateNode(5); 
   
  cout << "Inorder traversal of the constructed tree is ";
  printInOrder(root);
  cout << endl;
   
  // Convert tree to its mirror 
  constructMirrorTree(root); 
   
  cout << "Inorder traversal of the mirror tree is " ;  
  printInOrder(root);
  cout << endl;
   
  return 0;  
}
