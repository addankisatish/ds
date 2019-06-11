#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int a)
    {
        data = a;
        left = right = NULL;
    }
};

void printInorder(Node *root)
{
    if(root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << "  ";
    printInorder(root->right);
}

void printInorderUsingStack(Node *root)
{
    if(root == NULL)
        return;

    stack<Node *> s;
    Node *current = root;

    while(current != NULL || !s.empty())
    {
        if(current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        else
        {
            current = s.top();
            cout << current->data << "  ";
            s.pop();

            current = current->right;
        }
    }
}

void morrisInorderTraversal(Node *root)
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
            // Find the inorder predessor for this node.
            Node *temp = current->left;
            while(temp->right != NULL && temp->right != current)
                temp = temp->right;

            if(temp->right == NULL)
            {
                temp->right = current;
                current = current->left;
            }
            else
            {
                temp->right = NULL;
                cout << current->data << "  ";
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

    cout << "Inorder traversal : " << endl;
    printInorder(root);
    cout << endl;

    cout << "Inorder traversal using stack: " << endl;
    printInorderUsingStack(root);
    cout << endl;

    cout << "Morris Inorder traversal without stack: " << endl;
    morrisInorderTraversal(root);
}