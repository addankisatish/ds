#include<iostream>
#include<unordered_set>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *allocateNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void insert(Node **headRef, int data)
{
    Node *temp = allocateNode(data);
    Node *list = *headRef;
    if( list == NULL )
    {
        *headRef = temp;
        return;
    }
    while(list->next != NULL)
        list = list->next;

    list->next = temp;
}

void printList(Node *headRef)
{
    Node *temp = headRef;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void removeDuplicates(Node *headRef)
{
    Node *current = headRef;
    Node *prev = NULL;

    if(headRef == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    unordered_set<int> mySet;
    while(current != NULL)
    {
        //
        // The element is not duplicate
        //
        if(mySet.end() == mySet.find(current->data))
        {
            mySet.insert(current->data);
            prev = current;
            current = current->next;
        }
        else // duplicate entry. So delete the current node
        {
            Node *temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
        }
    }
}

int main()
{
    Node *list = NULL;
    insert(&list, 2);
    insert(&list, 4);
    insert(&list, 6);
    insert(&list, 4);
    insert(&list, 6);
    insert(&list, 7);
    insert(&list, 2);

    printList(list);
    removeDuplicates(list);
    printList(list);
    
    return 0;
}
