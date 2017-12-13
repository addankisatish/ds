#include<iostream>
#include<memory>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void reverseList(Node **headRef)
{
    if(*headRef == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    Node *prev = NULL;
    Node *current = *headRef;
    Node *next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}

void reverseListRecursive(Node **headRef)
{
    if(*headRef == NULL)
        return;

    Node *first = *headRef;
    Node *rest = first->next;

    if(rest == NULL)
        return;

    reverseListRecursive(&rest);
    first->next->next = first;

    first->next = NULL;

    *headRef = rest;
}

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

int main()
{
    Node *list = NULL;
    insert(&list, 2);
    insert(&list, 4);
    insert(&list, 6);
    insert(&list, 8);

    printList(list);
    reverseList(&list);
    printList(list);
    reverseListRecursive(&list);
    printList(list);
}


