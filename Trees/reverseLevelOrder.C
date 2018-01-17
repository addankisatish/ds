#include<iostream>
#include<memory>
#include<stack>
#include<queue>
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

void printReverseLevelOrder(Node *root)
{
    if(root == NULL)
        return;

    cout << "Reverse Level Order: " << endl;
    queue<Node *> q;
    stack<Node *> s;

    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        s.push(temp);
  
        if(temp->right != NULL)
            q.push(temp->right);

        if(temp->left != NULL)
            q.push(temp->left);
    }

    while(!s.empty())
    {
        Node *temp = s.top();
        s.pop();

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

    printReverseLevelOrder(root);

    return 0;
}
