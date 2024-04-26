#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Prev;
    Node *Next;
};

int main()
{
    Node *Head;
    Node *Node1 = NULL;
    Node *Node2 = NULL;
    Node *Node3 = NULL;

    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    Node1->value = 1;
    Node2->value = 2;
    Node3->value = 3;

    Node1->Prev = NULL;
    Node2->Prev = Node1;
    Node3->Prev = Node2;

    Node1->Next = Node2;
    Node2->Next = Node3;
    Node3->Next = NULL;

    Head = Node3;
    while (Head != NULL)
    {
        cout << Head->value;
        cout << endl;
        Head = Head->Prev;
    }
}