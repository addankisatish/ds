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

int height(Node *root)
{
    if(root == NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
}

int iterativeHeight(Node *root)
{
    if(root == NULL)
        return 0;

    queue<Node *> q;
    q.push(root); 
    q.push(NULL);

    int height = 0;
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            // 
            // Reached the end of level.
            //
            height++;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }  
        else
        {
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        } 
    }
    return height;
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
    
    cout << "The height of tree is: " << height(root) << endl;
    cout << "The iterative height is: " << iterativeHeight(root) << endl;
    return 0;
}    


