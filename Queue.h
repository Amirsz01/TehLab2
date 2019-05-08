#pragma once
#include <iostream>
#include </Users/Amirsz/source/repos/ТестовыйСтенд/ТестовыйСтенд2/el.h>

using namespace std;
class Queue {
private:
	el *head, *tail;
	int size;
public:
	Queue() { head = NULL; tail = NULL; size = 0; }
	Queue(int size);
	~Queue()
	{
		el *current = head->next;
		el *buf;
		delete head;
		while (current)
		{
			buf = current->next;
			delete current;
			current = buf;
		}
		system("pause");
	}
	int getSize();
	void getPod(int size);
	explicit Queue(const Queue& other); //Конструктор копирования
	Queue& operator /=(const Queue& op2);
	Queue& operator /=(int op1);
	Queue& operator +(const Queue& op2);
	Queue& operator +(int op1);
	Queue& operator = (const Queue& op2);
	Queue& operator++();
	Queue& operator--();
	Queue& operator++(int);
	Queue& operator--(int);
	bool operator >=(const Queue& op2);
	bool operator <=(const Queue& op2);
	friend Queue& operator /(Queue& op2, int op1);
	friend Queue& operator /(Queue& op2, Queue& op1);
	friend ostream& operator << (ostream &stream, const Queue& op2);
	friend istream& operator >> (istream &stream, Queue& op2);
	friend bool operator ==(const Queue& op1, const Queue& op2);
	friend bool operator ==(const Queue& op1, int op2);
	friend bool operator !=(const Queue& op1, const Queue& op2);
	friend bool operator !=(const Queue& op1, int op2);
	friend Queue& operator +=(Queue& op1, const Queue& op2);
	friend Queue& operator +=(Queue& op1, int op2);
	friend Queue& operator -=(Queue& op1, const Queue& op2);
	friend Queue& operator -=(Queue& op1, int op2);
	friend bool operator >(const Queue& op1, const Queue& op2);
	friend bool operator >(const Queue& op1, int op2);
	friend bool operator <(const Queue& op1, const Queue& op2);
	friend bool operator <(const Queue& op1, int op2);
};
