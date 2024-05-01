#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{

protected:

	clsDynamicArray <T> _MyList;

public:

	void push(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	void pop()
	{
		_MyList.DeleteFirstItem();
	}

	int Size()
	{
		return _MyList.Size();
	}

	void Print()
	{
		_MyList.PrintArray();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	void UpdateItem(int Index, T new_value)
	{
		_MyList.SetItem(Index, new_value);
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
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

