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

Node *Find(Node *Head, int Value)
{
    while (Head != NULL)
    {
        if (Head->Value == Value)
        {
            return Head;
        }
        Head = Head->next;
    }
    return NULL;
}

void InsertAfter(Node *&prev_node, int value)
{
    if (prev_node == NULL)
    {
        cout << "the given previous node can't be 'NULL' !";
        return;
    }
    Node *New_Node = new Node();
    New_Node->Value = value;
    New_Node->next = prev_node->next;
    prev_node->next = New_Node;
}

int main()
{
    Node *Head = NULL;
    InsertAtBeginning(Head, 10);
    InsertAtBeginning(Head, 20);
    InsertAtBeginning(Head, 30);
    InsertAtBeginning(Head, 40);
    InsertAtBeginning(Head, 50);
    InsertAtBeginning(Head, 60);
    PrintLinkedList(Head);

    Node *Item = Find(Head, 20);
    InsertAfter(Item, 15);

    cout << "List After adding new item : \n";
    PrintLinkedList(Head);
    system("pause>0");

    return 0;
}
