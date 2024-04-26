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

void Delete_First_Node(Node *&head)
{
    Node *Current = head;
    if (Current == NULL)
    {
        return;
    }
    head = Current->next;
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

    Delete_First_Node(head);
    Delete_First_Node(head);
    Delete_First_Node(head);
    cout << "List After Remove 1st Node 3 times : \n";
    PrintLinkedList(head);

    system("pause>0");
    return 0;
}