#include <iostream>
using namespace std;

class Node
{
public:
    int Value;
    Node *next;
};

void PrintLinkedList(Node *Head)
{
    while (Head != NULL)
    {
        cout << Head->Value << " \n";
        Head = Head->next;
    }
}

void InsertAtEnd(Node *&head, int value)
{
    Node *new_node = new Node();
    new_node->Value = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    Node *Last_Node = head;
    while (Last_Node->next != NULL)
    {
        Last_Node = Last_Node->next;
    }
    Last_Node->next = new_node;
}

void Delete_Node(Node *&head, int value)
{
    Node *Current = head, *prev = head;
    if (Current == NULL)
    {
        return;
    }

    if (Current->Value == value)
    {
        head = Current->next;
        delete Current;
        return;
    }

    while (Current != NULL && Current->Value != value)
    {
        prev = Current;
        Current = Current->next;
    }

    if (Current == NULL)
        return;

    prev->next = Current->next;
    delete Current;
    return;
}

int main()
{
    Node *head = NULL;
    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    cout << "List Before  using delete function : \n";
    PrintLinkedList(head);

    cout << "List After using delete function : \n";
    Delete_Node(head, 3);
    PrintLinkedList(head);

    system("pause>0");
    return 0;
}