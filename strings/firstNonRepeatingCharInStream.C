#include<iostream>
using namespace std;

#define MAX_CHAR 256

struct Node
{
    char ch;
    Node *next, *prev;
};

void appendNode(Node **headRef, Node **tailRef, char x)
{
    Node *temp = new Node;
    temp->ch = x;
    temp->prev = temp->next = NULL;

    if(*headRef == NULL)
    {
        *headRef = *tailRef = temp;
        return;
    }
    (*tailRef)->next = temp;
    temp->prev = *tailRef;
    *tailRef = temp;
}

void removeNode(Node **headRef, Node **tailRef, Node *temp)
{
    if(*headRef == NULL)
        return;

    if(*headRef == temp)
        *headRef = (*headRef)->next;

    if(*tailRef == temp)
        *tailRef = (*tailRef)->prev;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
}

void firtsNonRepeating()
{
    Node *list[MAX_CHAR];
    bool repeated[MAX_CHAR];

    Node *head = NULL;
    Node *tail = NULL;

    for(int i = 0; i < MAX_CHAR; i++)
    {
        list[i] = NULL;
        repeated[i] = false;
    }

    char c;
    do
    {
        cout << "Enter char(0 to exit the loop): ";
        cin >> c;

        // Check if this character is repeated.
        if(!repeated[c])
        {
            if(list[c] == NULL)
            {
                appendNode(&head, &tail, c);
                list[c] = tail; // Update the address of the Node.
            }
            else
            {
                removeNode(&head, &tail, list[c]); // Pass the address of the Node to be deleted
                list[c] = NULL;
                repeated[c] = true;
            }
        }
        if(head != NULL)
        {
            cout << "The first non repeating character in the stream so far is: "<< head->ch << endl;
        }
    } while(c != '0');
}

int main()
{
   firtsNonRepeating();
   return 0;
}
