#include<iostream>
#include<stack>
#include<memory>
using namespace std;

struct Node
{
    int data;
    Node * next;
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


bool isPalindrome(Node *headRef)
{
    Node *temp = headRef;
    stack<int> myStack;

    if(temp == NULL)
    {
        cout << "The list is empty." << endl;
        return true;
    }
    while( temp != NULL)
    {
        //
        // Push the elements to the stack.
        //
        myStack.push(temp->data);
        temp = temp->next;
    }
    //
    // Now traverse the list again to check for palindrome
    //
    temp = headRef;
    while(temp != NULL)
    {
        //
        // Pop the element from the stack
        //
        int data = myStack.top();
        myStack.pop();
        if(temp->data != data)
            return false;

        temp = temp->next;
    } 
    return true;
}

void reverse(Node **headRef)
{
    Node *current = *headRef;
    Node *prev = NULL;
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

bool compareLists(Node *first, Node *second)
{
    if(first == NULL && second == NULL)
        return true;

    if(first == NULL || second == NULL)
        return false;

    if(first->data != second->data)
        return false;

    return compareLists(first->next, second->next);
}

bool isPalindrome1(Node *headRef)
{
    Node *slow_ptr = headRef;
    Node *fast_ptr = headRef;
    Node *prev_slow_ptr = NULL;

    if((headRef == NULL) || (headRef->next == NULL))
        return true;

    printList(headRef);
    //
    // Find the middle node
    //
    while(fast_ptr && fast_ptr->next)
    {
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    //
    // Determine if the length of the list is odd or even.
    // Accordingly set the middle node
    //
    Node *midNode = NULL;
    if(fast_ptr && fast_ptr->next == NULL) // Odd number of elements
    {
        cout << "The list has odd numbr of elements." << endl;
        midNode = slow_ptr;
        slow_ptr = slow_ptr->next;
    }
    prev_slow_ptr->next = NULL;
    Node *second_list = slow_ptr;

    //
    // Now reverse the second list
    //
    printList(headRef);
    printList(second_list);
    reverse(&second_list);
    //
    // Now compare both the list
    //
    Node *first_list = headRef;
    bool areSame = compareLists(first_list, second_list);
    //
    // Construct the original list back
    //
    reverse(&second_list);
    if(midNode != NULL)
    {
        prev_slow_ptr->next = midNode;
        midNode->next = second_list;
    }
    else
    {
        prev_slow_ptr->next = second_list;
    }
    printList(headRef);
    return areSame;
}

int main()
{
    Node *list = NULL;
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 3);
    insert(&list, 2);
    insert(&list, 1);

    printList(list);

    cout << isPalindrome(list) << endl;
    cout << isPalindrome1(list) << endl;
    return 0;
}
