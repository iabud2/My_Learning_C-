#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
private:
	int _Size = 0;
public:
	class Node
	{
	public:
		T value;
		Node* prev;
		Node* next;
	};

	Node* head = NULL;

	void InsertAtBeginning(T value)
	{
		Node* NewNode = new Node();
		NewNode->value = value;
		NewNode->prev = NULL;
		NewNode->next = head;
		if (head != NULL)
		{
			head->prev = NewNode;
		}
		head = NewNode;
		_Size++;
	}


	void PrintList()
	{
		Node* Current = head;
		while (Current != NULL)
		{
			cout << Current->value << "  ";
			Current = Current->next;
		}
		delete Current;
	}

	Node* Find(T value)
	{
		Node* Current = head;
		while (Current != NULL)
		{
			if (Current->value == value)
			{
				return Current;
			}
			Current = Current->next;
		}
		return NULL;
	}

	void InsertAfter(Node* Current, T value)
	{
		Node* NewNode = new Node();
		NewNode->value = value;
		NewNode->prev = Current;
		NewNode->next = Current->next;

		if (Current->next != NULL)
		{
			Current->next->prev = NewNode;
		}
		Current->next = NewNode;
		_Size++;
	}

	//by index:
	bool InsertAfter(int index, T value)
	{
		Node* Current = GetNode(index);
		if (Current != NULL)
		{
			InsertAfter(Current, value);
			return true;
		}
		return false;
	}

	void InsertAtEnd(T value)
	{
		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = NULL;

		if (head == NULL)
		{
			new_node->prev = NULL;
			head = new_node;
		}
		else
		{
			Node* Current = head;
			while (Current->next != NULL)
			{
				Current = Current->next;
			}
			Current->next = new_node;
			new_node->prev = Current;
		}
		_Size++;
	}

	void DeleteNode(Node* NodeToBeDeleted)
	{
		if (head == NULL || NodeToBeDeleted == NULL)
		{
			return;
		}
		if (head == NodeToBeDeleted)
		{
			head = NodeToBeDeleted->next;
		}
		if (NodeToBeDeleted->next != NULL)
		{
			NodeToBeDeleted->next->prev = NodeToBeDeleted->prev;
		}
		if (NodeToBeDeleted->prev != NULL)
		{
			NodeToBeDeleted->prev->next = NodeToBeDeleted->next;
		}
		delete NodeToBeDeleted;
		_Size--;
	}

	void DeleteFirstNode()
	{
		if (head == NULL)
		{
			return;
		}

		head = head->next;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL)
		{
			return;
		}
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			return;
		}

		Node* Current = head;
		while (Current->next->next != NULL)
		{
			Current = Current->next;
		}
		Node* temp = Current->next;
		Current->next = NULL;
		delete temp;
		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return ((_Size == 0) ? true : false);
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* Current = head;
		Node* temp = nullptr;
		while (Current != nullptr)
		{
			temp = Current->prev;
			Current->prev = Current->next;
			Current->next = temp;
			Current = Current->prev;
		}

		if (temp != nullptr)
		{
			head = temp->prev;
		}
	}

	Node* GetNode(int index)
	{
		Node* Current = head;

		if (index > _Size - 1 || index < 0)
		{
			return NULL;
		}
		int counter = 0;

		while (Current != NULL && Current->next != NULL)
		{
			if (counter == index)
			{
				break;
			}
			Current = Current->next;
			counter++;
		}
		return Current;
	}

	T GetItem(int index)
	{
		Node* Item = GetNode(index);
		if (Item == NULL)
		{
			return NULL;
		}
		return (Item->value);
	}

	bool UpdateItem(int index, T Value)
	{
		Node* Item = GetNode(index);
		if (Item != NULL)
		{
			Item->value = Value;
			return true;
		}
		return false;
	}
};

