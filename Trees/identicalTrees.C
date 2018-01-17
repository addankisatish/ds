#include<iostream>
#include<memory>
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

bool areIdentical(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;

    if(root1 == NULL || root2 == NULL)
        return false;

    if(root1->data != root2->data)
        return false;

    return (areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right) );
}

//
// The idea is to do level order traversal and compare
//
bool iterativeIdentical(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;

    if(root1 == NULL || root2 == NULL)
        return false;

    queue<Node *> q1;
    queue<Node *> q2;
    
    q1.push(root1);
    q2.push(root2);

    while(!q1.empty() && !q2.empty())
    {
        Node *temp1 = q1.front();
        Node *temp2 = q2.front();

        q1.pop();
        q2.pop();

        if(temp1->data != temp2->data)
            return false;

        if(temp1->left && temp2->left)
        {
            q1.push(temp1->left);
            q2.push(temp2->left);
        }
        else if(temp1->left || temp2->left)
            return false;

        if(temp1->right && temp2->right)
        {
            q1.push(temp1->right);
            q2.push(temp2->right);
        }
        else if(temp1->right || temp2->right)
            return false; 
    }
    return true;
}

int main()
{
    Node *root1 = allocateNode(1);
    root1->left = allocateNode(2);
    root1->right = allocateNode(3);
    root1->left->left  = allocateNode(4);
    root1->left->right = allocateNode(5); 
    root1->right->left  = allocateNode(6);
 
    Node *root2 = allocateNode(1);
    root2->left = allocateNode(2);
    root2->right = allocateNode(3);
    root2->left->left = allocateNode(4);
    root2->left->right = allocateNode(5); 
    root2->right->right = allocateNode(5); 
 
    if(areIdentical(root1, root2))
        cout << "Both tree are identical." << endl;
    else
        cout << "Trees are not identical." << endl;
 
    if(iterativeIdentical(root1, root2))
        cout << "Both tree are identical." << endl;
    else
        cout << "Trees are not identical." << endl;
    return 0;
}
