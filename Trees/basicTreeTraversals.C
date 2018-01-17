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

void printInOrder(Node *root)
{
    if(root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void iterativeInorder(Node * root)
{
    Node *current = root;
    stack<Node *> s;

    cout << "Iterative Inorder traversal: " ;
    while(!s.empty() || current != NULL)
    {
        if(current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        else
        {
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }    
    cout << endl;
}

void printPreOrder(Node *root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void iterativePreorder(Node *root)
{
    Node *current = root;
    stack<Node *> s;

    cout << "Iterative Preorder traversal: " ;
    while(!s.empty() || current != NULL)
    {
        if(current != NULL)
        {
            cout << current->data << " ";
            if(current->right != NULL)
                s.push(current->right);
            current = current->left;
        }
        else
        {
            current = s.top();
            s.pop();
        }
    }
    cout << endl;
}

void printPostOrder(Node *root)
{
    if(root == NULL)
        return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " " ;
}

void iterativePostOrder(Node *root)
{
    if(root == NULL)
        return;

    stack<Node *> s1;
    stack<Node *> s2;

    cout << "Iterative post order travesal: " ;
    s1.push(root);
    while(!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();

        s2.push(temp);

        if(temp->left != NULL)
            s1.push(temp->left);

        if(temp->right != NULL)
            s1.push(temp->right);
    }

    while(!s2.empty())
    {
        Node *temp = s2.top();
        s2.pop();

        cout << temp->data << " ";
    }
    cout << endl;

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

    cout << "Inorder traversal: " ;
    printInOrder(root);
    cout << endl;
    iterativeInorder(root);
    cout << "Preorder traversal: " ;
    printPreOrder(root);
    cout << endl;
    iterativePreorder(root);
    cout << "Postorder traversal: " ;
    printPostOrder(root);
    cout << endl;
    iterativePostOrder(root);
 
    return 0;
} 
