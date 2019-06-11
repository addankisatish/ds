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

void PostorderTraversal(Node *root)
{
    if(root == NULL)
        return;

    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << "  ";
}

void PostorderTraversalUsingTwoStacks(Node *root)
{
    if(root == NULL)
        return;

    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

    while(!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }

    while(!s2.empty())
    {
        Node *temp = s2.top();
        cout << temp->data << "  ";
        s2.pop();
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

    cout << "Postorder traversal : " << endl;
    PostorderTraversal(root);
    cout << endl;

    cout << "Inorder traversal using stack: " << endl;
    PostorderTraversalUsingTwoStacks(root);
    cout << endl;
}
