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
    if(first_list == NULL && second_list == NULL)
    {
        cout << "Both the list are empty." << endl;
        return NULL;
    }
    
    Node *current = NULL;
    Node *temp = NULL;
    while(first_list != NULL && second_list != NULL)
    {
        if(first_list->data <= second_list->data)
        {
            temp = allocateNode(first_list->data);
            first_list = first_list->next;
        }
        else 
        {
            temp = allocateNode(second_list->data);
            second_list = second_list->next;
        }

        if(merged_list == NULL)
        {
            merged_list = current = temp;
        }
        else
        {
            current->next = temp;
            current = temp;
        }      
    }
    while(first_list != NULL)
    {
        temp = allocateNode(first_list->data);
        first_list = first_list->next;
         if(merged_list == NULL)
        {
            merged_list = current = temp;
        }
        else
        {
            current->next = temp;
            current = temp;
        }
    }
    while(second_list != NULL)
    {
        temp = allocateNode(second_list->data);
        second_list = second_list->next;
         if(merged_list == NULL)
        {
            merged_list = current = temp;
        }
        else
        {
            current->next = temp;
            current = temp;
        }
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

    Node *empty_list = NULL;
    third_list = mergeTwoSortedLists(first_list, empty_list);
    printList(third_list);
    
    third_list = mergeTwoSortedLists(empty_list, second_list);
    printList(third_list);

    Node *list = NULL;
    insert(&list, 1);
    insert(&list, 3);
    insert(&list, 5);
    third_list = mergeTwoSortedLists(first_list, list);
    printList(third_list);

    Node *flist = NULL;
    insert(&flist, 1);
    insert(&flist, 2);
    insert(&flist, 5);
    insert(&flist, 8);

    Node *slist = NULL;
    insert(&slist, 1);
    insert(&slist, 2);
    insert(&slist, 3);
    insert(&slist, 4);
    insert(&slist, 6);
    insert(&slist, 7);
    insert(&slist, 8);
    third_list = mergeTwoSortedLists(flist, slist);
    printList(third_list);
    return 0;
}
