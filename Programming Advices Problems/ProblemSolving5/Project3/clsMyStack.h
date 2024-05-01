#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
#include "clsMyQueue.h"
using namespace std;

template <class T>

class clsMyStack:public clsMyQueue <T>
{

public:

	void push(T value)
	{
		clsMyStack <T>::_MyList.InsertAtBeginning(value);
	}

	T Top()
	{
		return clsMyQueue <T>::Front();
	}

	T Bottom()
	{
		return clsMyQueue <T>::back();
	}

};

