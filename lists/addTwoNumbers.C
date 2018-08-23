#include<iostream>
using namespace std;

// Given two linked lists representing numbers.
// The digits are stored in reverse order 
//
// Input: (2->4->3) + (5->6->4)
// output: (7->0->8)
// 342 + 465 = 807 

struct Node
{
    int data;
    Node *next;
    
    Node(int val) : data(val), next(nullptr) {}
};

void push_front(Node **head_ref, int data)
{
    Node *temp = new Node(data);
    temp->next = *head_ref;
    (*head_ref) = temp; 
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

Node* addTwoNumbers(Node* list1, Node *list2)
{
    cout << "Adding two lists ..." << endl;
    if(list1 == NULL && list2 == NULL)
        return NULL;

    if(list1 == NULL)
        return list2;

    if(list2 == NULL)
        return list1;

    Node *result = NULL;
    Node *last_node = NULL;
    int carry = 0;
    int sum;
    while(list1 != NULL || list2 != NULL)
    {
        sum = carry + ((list1 != NULL) ? list1->data : 0) + ((list2 != NULL) ? list2->data : 0);
        carry = sum / 10;
        sum = sum % 10;
        //
        // Create a new node.
        //
        Node *temp = new Node(sum);
        if(result == NULL)
        {
            result = temp;
            last_node = temp;
        }
        else
        {
            last_node->next = temp;
            last_node = temp;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    if(carry > 0)
    {
        Node *temp = new Node(carry);
        last_node ->next = temp;
    }

    return result;
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;
    
    push_front(&list1, 2);   
    push_front(&list1, 4);   
    push_front(&list1, 3);   
    printList(list1);

    push_front(&list2, 8);   
    push_front(&list2, 6);   
    push_front(&list2, 4);   
    printList(list2);

    Node *result = addTwoNumbers(list1, list2);
    printList(result);
}

