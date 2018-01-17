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

void levelOrderTraversal(Node *root)
{
    if(root == NULL)
        return;

    cout << "Level Order traversal: ";
    queue<Node *> q;
    Node *temp = NULL;
    //
    // Push the root node into queue.
    //
    q.push(root);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        cout << temp->data << " ";
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

int height(Node *root)
{
    if(root == NULL)
        return 0;

    int lheight = height(root->left); // find height of left subtree
    int rheight = height(root->right); // find height of right subtree

    return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
}

void printGivenLevel(Node *root, int level)
{
    if(root == NULL)
        return;

    if(level == 1)
    {
        cout << root->data << " ";
    }
    else
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(Node * root)
{
    if(root == NULL)
        return;

    int h = height(root);
    //
    // Print each level of tree.
    //
    for(int level = 1; level <= h; level++)
    {
        printGivenLevel(root, level);
    }

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

    levelOrderTraversal(root);
    cout << endl;
    printLevelOrder(root);
    cout << endl;

    return 0;
}
