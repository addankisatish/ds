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

int sum(Node *root)
{
    // Find the max in the left subtree.
    // Find the max in the right subtree.
    // Compare with the root and return max of three.
    if(root == NULL)
    {
        return 0;
    }
    return sum(root->left) + sum(root->right) + root->data;
}

int sumIterative(Node *root)
{
    if(root == NULL)
        return 0;

    queue<Node *> myQueue;
    Node *current = root;
    int sum = 0;

    myQueue.push(current);
    while(!myQueue.empty())
    {
        Node *temp = myQueue.front();
        myQueue.pop();

        sum =  sum + temp->data;
        if(temp->left)
        {
            myQueue.push(temp->left);
        }
        if(temp->right)
        {
            myQueue.push(temp->right);
        }
    } 
    return sum;
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

    cout << "The sum of the tree is : " <<  sum(root) << endl;
    cout << "The sum of the tree is : " <<  sumIterative(root) << endl;
    return 0;
}
