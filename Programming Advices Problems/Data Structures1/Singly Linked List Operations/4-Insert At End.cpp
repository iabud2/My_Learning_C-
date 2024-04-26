#include <iostream>
using namespace std;

class Node
{
public:
    int Value;
    Node *next;
};

void InsertAtBeginning(Node *&Head, int value)
{
    Node *New_Node = new Node();
    New_Node->Value = value;
    New_Node->next = Head;
    Head = New_Node;
}

void PrintLinkedList(Node *Head)
{
    while (Head != NULL)
    {
        cout << Head->Value << " \n";
        Head = Head->next;
    }
}

void InsertAtEnd(Node* &head, int value)
{
    Node *new_node = new Node();
    new_node->Value = value;
    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
        return;
    }

    Node* Last_Node = head;
    while (Last_Node->next != NULL)
    {
        Last_Node = Last_Node->next;
    }
    Last_Node->next = new_node;
}


int main()
{
    Node *head = NULL;
    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtBeginning(head, 0);
    InsertAtBeginning(head, -1);
    PrintLinkedList(head);
    system("pause>0");
    return 0;
}