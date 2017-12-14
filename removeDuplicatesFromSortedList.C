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

void removeDuplicates(Node *headRef)
{
    if(headRef == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    Node *current = headRef;
    while(current->next != NULL)
    {
        Node *temp = current->next;
        if(current->data == temp->data)
        {
            current->next = temp->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{
    Node *list = NULL;
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 2);
    insert(&list, 2);
    insert(&list, 4);
    insert(&list, 6);
    insert(&list, 6);
    insert(&list, 7);
    insert(&list, 7);
    insert(&list, 7);

    printList(list);
    removeDuplicates(list);
    printList(list);
    
    return 0;
}
