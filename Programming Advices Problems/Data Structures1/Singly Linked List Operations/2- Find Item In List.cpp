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

    Node *Item = Find(Head, 50);
    if (Item != NULL)
    {
        cout << "Node Found.";
    }
    else
    {
        cout << "Node Not Found.";
    }

    system("pause>0");

    return 0;
}
