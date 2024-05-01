#pragma once
#include <iostream>
#include <stack>
using namespace std;

class clsMyString
{

private:
	string _value = " ";
	stack <string> _Undo;
	stack <string> _Redo;

public:
	
	void Set_Value(string value)
	{
		_Undo.push(_value);
		_value = value;
	}

	string Get_Value()
	{
		return _value;
	}

	_declspec(property(get = Get_Value, put = Set_Value))string value;

	void Undo()
	{
		_Redo.push(_value);
		_value = _Undo.top();
		_Undo.pop();
	}

	void Redo()
	{
		_Undo.push(_value);
		_value = _Redo.top();
		_Redo.pop();
	}
};

