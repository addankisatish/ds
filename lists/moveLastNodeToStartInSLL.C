#include<iostream>
#include<memory>
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

void moveLastNode(Node **headRef)
{
    Node *current = *headRef;
    Node *prev = NULL;

    if((current == NULL) || (current->next == NULL))
    {
        cout << "List is empty or contains a single node." << endl;
        return;
    }

    //
    // Go to the last node.
    //
    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    current->next = *headRef;
    *headRef = current;
}

int main()
{
    Node *list = NULL;
    insert(&list, 2);
    insert(&list, 4);
    insert(&list, 6);

    printList(list);
    moveLastNode(&list);
    printList(list);

    return 0;
} 
