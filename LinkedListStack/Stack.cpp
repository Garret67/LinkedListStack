#include "Stack.h"

void Stack::Push(int val)
{
	if (Top)
	{
		End->next = new Data(val);
		End = End->next;
	}
	else
	{
		Top = new Data(val);
		End = Top;
	}
	listNumElem++;
}

int Stack::Pop()
{
	if (!Empty())
	{
		int val = End->value;
		listNumElem--;
		delete End;

		if (listNumElem == 0)
		{
			Top = nullptr;
			End = nullptr;
		}
		else
		{
			Data* cur = Top;
			for (int i = 0; i < listNumElem - 1; i++)
			{
				cur = cur->next;
			}
			cur->next = nullptr;
			End = cur;
		}

		return val;
	}
	return -1;
}

int Stack::Size() const
{
	return listNumElem;
}

bool Stack::Empty() const
{
	if (listNumElem > 0){
		return false;
	}
	else {
		return true;
	}
	
}
