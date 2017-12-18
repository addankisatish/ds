#include<iostream>
#include<memory>
#include<vector>
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

bool findPath(Node *root, vector<int> &path, int element)
{
    if(root == NULL)
        return false;

    path.push_back(root->data);

    if(root->data == element)
        return true;

    if(findPath(root->left, path, element) ||
       findPath(root->right, path, element))
    {
        return true;
    }

    path.pop_back();

    return false;
}

int lca(Node *root, int n1, int n2)
{
    if(root == NULL)
        return -1;

    vector<int> path1, path2;
    if(!findPath(root, path1, n1) || !findPath(root, path2, n2))
    {
        cout << "Element missing in the tree." << endl;
        return -1;
    }

    cout << "The ancestors for " << n1 << " are: " << endl;    
    for(auto v : path1)
        cout << v << " ";
    cout << endl;


    cout << "The ancestors for " << n2 << " are: " << endl;    
    for(auto v : path2)
        cout << v << " ";
    cout << endl;

    int i = 0;
    for(i = 0; i < path1.size() && i < path2.size(); i++)
    {
        if(path1[i] != path2[i])
            break;
    }
    return path1[i-1];
}

Node *lcaUtil(Node *root, int n1, int n2, bool &v1, bool &v2)
{
    if(root == NULL)
        return NULL;

    if(root->data == n1)
    {
        v1 = true;
        return root;
    }
    if(root->data == n2)
    {
        v2 = true;
        return root;
    }

    Node *leftlca = lcaUtil(root->left, n1, n2, v1, v2);
    Node *rightlca = lcaUtil(root->right, n1, n2, v1, v2);

    if(leftlca && rightlca)
        return root;

    return (leftlca != NULL) ? leftlca : rightlca;
}

bool find(Node *root, int k)
{
    if (root == NULL)
        return false;
    //              
    // If key is present at root, or in left subtree or right subtree,
    // return true;
    if (root->data == k || find(root->left, k) ||  find(root->right, k))
        return true;
    return false;
}

int findLCA(Node *root, int n1, int n2)
{
    // Initialize n1 and n2 as not visited
    bool v1 = false, v2 = false;
    //      
    // Find lca of n1 and n2 using the technique discussed above
    Node *lca = lcaUtil(root, n1, n2, v1, v2);
    //               
    // Return LCA only if both n1 and n2 are present in tree
    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
        return lca->data;
    else
    {
        cout << "Element is missing in the tree. " << endl;
        return -1;
    }
}

int main()
{
    Node * root = allocateNode(1);
    root->left = allocateNode(2);
    root->right = allocateNode(3);
    root->left->left = allocateNode(4);
    root->left->right = allocateNode(5);
    root->right->left = allocateNode(6);
    root->right->right = allocateNode(7);
    cout << "LCA(4, 5) = " << lca(root, 4, 5) << endl;
    cout << "LCA(4, 6) = " << lca(root, 4, 6) << endl;
    cout << "LCA(3, 4) = " << lca(root, 3, 4) << endl;
    cout << "LCA(2, 4) = " << lca(root, 2, 4) << endl;
    cout << "LCA(2, 8) = " << lca(root, 2, 8) << endl;
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5) << endl;
    cout << "LCA(4, 6) = " << findLCA(root, 4, 6) << endl;
    cout << "LCA(3, 4) = " << findLCA(root, 3, 4) << endl;
    cout << "LCA(2, 4) = " << findLCA(root, 2, 4) << endl;
    cout << "LCA(2, 8) = " << findLCA(root, 2, 8) << endl;
    return 0;
}
