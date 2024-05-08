#pragma once

class Stack
{
private:
	class Data
	{
	public:
		Data(int value)
			:
			value(value)
		{
		}
		void Delete(Data* data)
		{
			delete data;
		}
	public:
		int value;
		Data* next = nullptr;
	};
public:
	Stack() = default;
	Stack(const Stack& other)
	{
		*this = other;
	}
	~Stack()
	{
		if (!Empty())
		{
			while (listNumElem > 0)
			{
				Pop();
			}
		}
	}
	Stack& operator=( Stack const& other)
	{
		if (!other.Empty())
		{
			Data* cur = other.Top;
			for (int i = 0; i < other.listNumElem; i++)
			{
				Push(cur->value);
				cur = cur->next;
			}
		}

		return *this;
	}
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	Data* Top = nullptr;
	Data* End = nullptr;
	int listNumElem = 0;
};