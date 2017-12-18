#include<iostream>
#include<memory>
#include<stack>
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

void printSpiral(Node *root)
{
    if(root == NULL)
        return;

    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

     while(!s1.empty() || !s2.empty())
     {
         while(!s1.empty())
         {
             Node *temp = s1.top();
             s1.pop();
             cout << temp->data << " ";

             if(temp->right != NULL)
                 s2.push(temp->right);

             if(temp->left != NULL)
                 s2.push(temp->left);

         }
         while(!s2.empty())
         {
             Node *temp = s2.top();
             s2.pop();
             cout << temp->data << " ";

             if(temp->left != NULL)
                 s1.push(temp->left);

             if(temp->right != NULL)
                 s1.push(temp->right);
         }
    }
}

int main()
{
    Node *root = allocateNode(1);
    root->left        = allocateNode(2);
    root->right       = allocateNode(3);
    root->left->left  = allocateNode(7);
    root->left->right = allocateNode(6);
    root->right->left  = allocateNode(5);
    root->right->right = allocateNode(4);
    cout << "Spiral Order traversal of binary tree is: \n";
    printSpiral(root);
 
    return 0;
}
