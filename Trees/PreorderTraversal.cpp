#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
  
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void printPreorder(Node *root)
{
    if(root == NULL)
        return;

    cout << root->data << "  ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPreorderUsingStack(Node *root)
{
    if(root == NULL)
        return;

    Node *current = root;
    stack< Node *> s;

    while(current != NULL || !s.empty())
    {
        if(current != NULL)
        {
            cout << current->data << "  ";
            if(current->right)
                s.push(current->right);

            current = current->left;
        }
        else
        {
            current = s.top();
            s.pop();
        }
        
    }
}

void MorrisPreorderTraversal(Node *root)
{
    if(root == NULL)
        return;

    Node *current = root;
    while(current != NULL)
    {
        if(current->left == NULL)
        {
            cout << current->data << "  ";
            current = current->right;
        }
        else
        {
            // find the inorder predecessor
            Node *temp = current->left;
            while(temp->right != NULL && temp->right != current)
                temp = temp->right;

            if(temp->right == NULL)
            {
                temp->right = current;
                cout << current->data << "  ";
                current = current->left;
            }
            else
            {
                temp->right = NULL;
                current = current->right;
            }
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Preorder traversal : " << endl;
    printPreorder(root);
    cout << endl;

    cout << "Preorder traversal using stack: " << endl;
    printPreorderUsingStack(root);
    cout << endl;

    cout << "MOrris Preorder traversal without stack: " << endl;
    MorrisPreorderTraversal(root);
}