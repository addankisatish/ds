#include<iostream>
#include<memory>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void middleElement(Node *headRef)
{
    if(headRef == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }
    Node *slow_ptr = headRef;
    Node *fast_ptr = headRef;
    while(fast_ptr && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    cout << "The middle element is: " << slow_ptr->data << endl;
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
    insert(&list, 0);

    printList(list);
    middleElement(list);

    insert(&list, 10);
    printList(list);
    middleElement(list);

    return 0;
}

