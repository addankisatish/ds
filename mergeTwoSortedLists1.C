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

Node *mergeTwoSortedLists(Node *first_list, Node *second_list)
{
    Node *merged_list = NULL;

    if(first_list == NULL)
        return second_list;

    if(second_list == NULL)
        return first_list;

    if(first_list->data <= second_list->data)
    {
        merged_list = first_list;
        merged_list->next = mergeTwoSortedLists(first_list->next, second_list);
    }
    else
    {
        merged_list = second_list;
        merged_list->next = mergeTwoSortedLists(first_list, second_list->next);
    }
    return merged_list;
}

int main()
{
    Node *first_list = NULL;
    insert(&first_list, 2);
    insert(&first_list, 4);
    insert(&first_list, 6);
    insert(&first_list, 8);
    insert(&first_list, 10);

    printList(first_list);

    Node *second_list = NULL;
    insert(&second_list, 1);
    insert(&second_list, 3);
    insert(&second_list, 5);
    insert(&second_list, 7);
    insert(&second_list, 9);

    printList(second_list);
    
    
    Node *third_list;
    third_list = mergeTwoSortedLists(first_list, second_list);
    printList(third_list);

    Node *flist = NULL;
    insert(&flist, 1);
    insert(&flist, 2);
    insert(&flist, 5);
    insert(&flist, 8);
    printList(flist);

    Node *slist = NULL;
    insert(&slist, 0);
    insert(&slist, 1);
    insert(&slist, 2);
    insert(&slist, 3);
    insert(&slist, 4);
    insert(&slist, 6);
    insert(&slist, 7);
    insert(&slist, 8);
    printList(slist);

    third_list = mergeTwoSortedLists(flist, slist);
    printList(third_list);
    return 0;
}
