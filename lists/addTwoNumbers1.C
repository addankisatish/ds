#include<iostream>
#include<stdlib.h>
using namespace std;

// Given two linked lists representing numbers.
//
// Input: (5->6->3) + (8->4->2)
// output: (1->4->0->5)
// 563 + 842 = 1402 

struct Node
{
    int data;
    Node *next;
   
    Node() : data(-1), next(nullptr) {} 
    Node(int val) : data(val), next(nullptr) {}
};

void push_front(Node **head_ref, int data)
{
    Node *temp = new Node(data);
    temp->next = *head_ref;
    (*head_ref) = temp; 
}

void push_back(Node **head_ref, int data)
{
    Node *temp = new Node(data);
    if(*head_ref == NULL)
    {
        (*head_ref) = temp;
    }
    else
    {
        Node *last_node = *head_ref;
        while(last_node->next != NULL)
            last_node = last_node->next;

        last_node->next = temp;
    }
}

void printList(Node *list)
{
    while(list != NULL)
    {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
}

int size(Node *head_ref)
{
    int len = 0;
    Node *temp = head_ref;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    cout << "The length of the list is: " << len << endl;
    return len;
}

Node *addSameSize(Node *list1, Node *list2, int *carry)
{
    if(list1 == nullptr)
        return nullptr;

    int sum;
    Node *result = new Node;
    
    //
    // Recursively add remaining nodes and get the carry.
    //
    result->next = addSameSize(list1->next, list2->next, carry);
    sum = list1->data + list2->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;

    result->data = sum;

    return result;
}

void addCarryToRemaining(Node* list, Node *cur, int *carry, Node **result)
{
    int sum;
    if(list != cur)
    {
        addCarryToRemaining(list->next, cur, carry, result);
        sum = list->data + *carry;
        *carry = sum / 10;
        sum = sum % 10;

        push_front(result, sum);        
    }
}

Node *addList(Node *list1, Node *list2)
{
    if(list1 == NULL && list2 == NULL)
        return NULL;

    if(list1 == NULL)
        return list2;

    if(list2 == NULL)
        return list1;

    int size1 = size(list1);
    int size2 = size(list2);

    int carry = 0;
    Node *result = NULL;

    if(size1 == size2)
    {
        result = addSameSize(list1, list2, &carry);
    }
    else
    {
        int diff = abs(size1 - size2);
        cout << "The diff is: " << diff << endl;
        if( size1 > size2)
        {
            Node *mod_list = list1;      
            while(diff > 0)
            {
                mod_list = mod_list->next;
                diff--;
            }
            result = addSameSize(mod_list, list2, &carry);
            addCarryToRemaining(list1, mod_list, &carry, &result);
        }
        else
        {
            Node *mod_list = list2;      
            while(diff > 0)
            {
                mod_list = mod_list->next;
                diff--;
            }
            result = addSameSize(list1, mod_list, &carry);
            addCarryToRemaining(list2, mod_list, &carry, &result);
        }
    }
    if(carry > 0)
    {
        push_front(&result, carry);
    }
    return result;
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;
    
    push_front(&list1, 3);   
    push_front(&list1, 6);   
    push_front(&list1, 5);   
    printList(list1);

    push_front(&list2, 1);   
    push_front(&list2, 2);   
    push_front(&list2, 4);   
    push_front(&list2, 8);   
    printList(list2);

    Node *result = addList(list1, list2);
    printList(result);
}

