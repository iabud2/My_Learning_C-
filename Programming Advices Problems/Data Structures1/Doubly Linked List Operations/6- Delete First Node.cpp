#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *prev;
    Node *next;
};

void InsertAtBeginning(Node *&head, int value)
{
    Node *NewNode = new Node();
    NewNode->value = value;
    NewNode->prev = NULL;
    NewNode->next = head;
    if (head != NULL)
    {
        head->prev = NewNode;
    }
    head = NewNode;
}

void PrintNodeDetails(Node *Head)
{
    if (Head->prev != NULL)
        cout << Head->prev->value;
    else
        cout << "NULL";
    cout << " <--> " << Head->value << " <--> ";
    if (Head->next != NULL)
    {
        cout << Head->next->value << "\n";
    }
    else
        cout << "NULL";
}

void PrintListDetails(Node *head)
{
    cout << "\n\n";
    while (head != NULL)
    {
        PrintNodeDetails(head);
        head = head->next;
    }
}

void PrintDoublyList(Node *head)
{
    cout << "NULL <--> ";
    while (head != NULL)
    {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";
}

Node *Find(Node *head, int value)
{
    while (head != NULL)
    {
        if (head->value == value)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void DeleteFirstNode(Node *&Head)
{
    if (Head == NULL)
    {
        return;
    }

    Node *temp = Head;
    Head = Head->next;
    if (Head != NULL)
    {
        Head->prev = NULL;
    }
    delete temp;
}

int main()
{
    Node *head = NULL;
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 0);

    cout << "\nDoubly Linked List :\n";
    PrintDoublyList(head);
    PrintListDetails(head);

    cout << "List After Delete First Node :\n";
    DeleteFirstNode(head);
    PrintDoublyList(head);
    system("pause>0");
    return 0;
}