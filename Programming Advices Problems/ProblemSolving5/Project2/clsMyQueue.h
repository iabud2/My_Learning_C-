#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList <T> _MyList;
public:

	void push(T item)
	{
		_MyList.InsertAtEnd(item);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	int Size()
	{
		return _MyList.Size();
	}

	T Front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	void Print()
	{
		_MyList.PrintList();
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	bool UpdateItem(int Index, T value)
	{
		if (_MyList.UpdateItem(Index, value))
			return true;
		else
			return false;
	}
	
	bool InsertAfter(int Index, T value)//By Item Index
	{
		if (_MyList.InsertAfter(Index, value))
			return true;
		else
			return false;
	}

	void InsertAtFront(T value)
	{
		_MyList.InsertAtBeginning(value);
	}
	
	void InsertAtBack(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	void Clear()
	{
		_MyList.Clear();
	}
	
	
};

