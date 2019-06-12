#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};

int maxElement(Node *root)
{
    // Find the max in the left subtree.
    // Find the max in the right subtree.
    // Compare with the root and return max of three.
    if(root == NULL)
    {
        return -1;
    }
    int lMax = maxElement(root->left);
    int rMax = maxElement(root->right);

    int max = (lMax > rMax) ? lMax : rMax;

    return (root->data > max) ? root->data : max;
}

int maxElementIterative(Node *root)
{
    if(root == NULL)
        return -1;

    queue<Node *> myQueue;
    Node *current = root;
    int max = current->data;

    myQueue.push(current);
    while(!myQueue.empty())
    {
        Node *temp = myQueue.front();
        myQueue.pop();

        max = (max > temp->data) ? max : temp->data;
        if(temp->left)
        {
            myQueue.push(temp->left);
        }
        if(temp->right)
        {
            myQueue.push(temp->right);
        }
    } 
    return max;
}

int main()
{
    Node *root = new Node(100);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(8);
    root->left->right = new Node(5);
    root->right->left = new Node(26);
    root->right->right = new Node(7);

    cout << "The max element in the tree is : " <<  maxElement(root) << endl;
    cout << "The max element in the tree is : " <<  maxElementIterative(root) << endl;
    return 0;
}