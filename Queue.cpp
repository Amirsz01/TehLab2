#include </Users/Amirsz/source/repos/ТестовыйСтенд/ТестовыйСтенд2/Queue.h>
Queue::Queue(int size)
{
	this->head = nullptr;
	this->size = size;
	for (int i = 0; i < size; ++i)
	{
		if (!head)
		{
			this->head = new el;
			head->data = rand() % 20 + 1;
			head->next = nullptr;
			tail = head;
		}
		else
		{
			tail->next = new el;
			tail=tail->next;
			tail->data = rand() % 20 + 1;
			tail->next = nullptr;
		}
	}
}
void Queue::getPod(int need)
{
	el *ptr = head;
	if (!getSize())
	{
		cout << "В очереди нет элементов" << endl;
		return;
	}
	if (need > getSize())
	{
		cout << "В очереди нет столько элементов" << endl;
		return;
	}
	for (int i = 0; i < need; i++)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

int Queue::getSize()
{
	return size;
}
Queue::Queue(const Queue& other) 
{
	this->size = other.size;
	if (!other.size) {
		cout << "Объект: пуст" << endl;
		return;
	}
	el* current = other.head;
	this->head = new el;
	this->tail = this->head;
	this->tail->data = current->data;
	current = current->next;
	while (current)
	{
		this->tail->next = new el;
		this->tail = this->tail->next;
		this->tail->data = current->data;
		current = current->next;
	}
	this->tail->next = NULL;
}


Queue& Queue::operator++()
{
	el* ptr = this->head;
	while (ptr)
	{
		ptr->data++;
		ptr = ptr->next;
	}
	return *this;
}

Queue& Queue::operator++(int)
{
	Queue temp;
	temp = *this;
	el* ptr = this->head;
	while (ptr)
	{
		ptr->data++;
		ptr = ptr->next;
	}
	return temp;
}

Queue& Queue::operator--(int)
{
	Queue temp;
	temp = *this;
	el* ptr = this->head;
	while (ptr)
	{
		ptr->data--;
		ptr = ptr->next;
	}
	return temp;
}

Queue& Queue::operator--()
{
	el* ptr = this->head;
	while (ptr)
	{
		ptr->data--;
		ptr = ptr->next;
	}
	return *this;
}

Queue& Queue::operator /=(const Queue& op2)
{
	el *ptr = this->head, *ptr1 = op2.head;
	while (ptr)
	{
		ptr->data = ptr->data / ptr1->data;
		ptr = ptr->next;
		ptr1 = ptr1->next;
	}
	return *this;
}

bool Queue::operator >=(const Queue& op2) 
{
	int count = 0;
	el *ptr = this->head, *ptr1 = op2.head;
	while (ptr)
	{
		if (ptr->data >= ptr1->data)
		{
			cout << "Элемент под номером " << count + 1 << "больше или равно чем элемент в другой очереди" << endl;
			return true;
		}
		ptr = ptr->next;
		ptr1 = ptr1->next;
		count++;
	}
	cout << "Такого элемента нет" << endl;
	return false;
}

bool Queue::operator <=(const Queue& op2)
{
	int count = 0;
	el *ptr = this->head, *ptr1 = op2.head;
	while (ptr)
	{
		if (ptr->data <= ptr1->data)
		{
			cout << "Элемент под номером " << count + 1 << "меньше или равно чем элемент в другой очереди" << endl;
			return true;
		}
		ptr = ptr->next;
		ptr1 = ptr1->next;
		count++;
	}
	cout << "Такого элемента нет" << endl;
	return false;
}

Queue& Queue::operator +(int op1)
{
	Queue temp(*this);
	el* ptr = temp.head;
	while (ptr)
	{
		ptr->data = ptr->data + op1;
		ptr = ptr->next;
	}
	return temp;
}
Queue& Queue::operator = (const Queue& op2)
{
	this->size = op2.size;
	if (!op2.size) {
		this->head = NULL;
		this->tail = NULL;
		return *this;
	}
	el* current = op2.head;
	this->head = new el;
	this->tail = this->head;
	this->tail->data = current->data;
	current = current->next;
	while (current)
	{
		this->tail->next = new el;
		this->tail = this->tail->next;
		this->tail->data = current->data;
		current = current->next;
	}
	this->tail->next = NULL;
	return *this;
}

Queue& operator /(Queue& op2, int op1) {
	Queue temp(op2);
	el* ptr = temp.head;
	while (ptr)
	{
		ptr->data = ptr->data / op1;
		ptr = ptr->next;
	}
	return temp;
}


ostream &operator << (ostream &stream, const Queue& op2)
{
	el *ptr = op2.head;
	if (!ptr)
		stream << "Объект: пуст";
	else
	{
		stream << "Объект: ";
		while (ptr)
		{
			stream << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	cout << endl;
	return stream;
}
istream &operator >> (istream &stream, Queue& op2)
{
	cout << "Введите число >> ";
	el *ptr = op2.tail;
	if (!op2.head)
	{
		op2.head = new el;
		op2.tail = op2.head;
		ptr = op2.tail;
	}
	else
	{
		ptr->next = new el;
		ptr = ptr->next;
	}
	stream >> ptr->data;
	ptr->next = NULL;
	op2.tail = ptr;
	op2.size++;
	return stream;
}

bool operator  ==(const Queue& op1, const Queue& op2)
{
	el *ptr = op1.head, *ptr1 = op2.head;
	for (int i = 0; i < op1.size; ++i)
	{
		for (int j = 0; j < op2.size; ++j) {
			if (ptr->data == ptr1->data)
			{
				cout << "Есть одинаковые элементы: " << ptr->data << endl;
				return true;
			}

			ptr1 = ptr1->next;
		}
		ptr1 = op2.head;
		ptr = ptr->next;
	}
	cout << "Одинаковых элементов нет" << endl;
	return false;
}

bool operator  !=(const Queue& op1, const Queue& op2)
{
	el *ptr = op1.head, *ptr1 = op2.head;
	for (int i = 0; i < op1.size; ++i)
	{
		for (int j = 0; j < op2.size; ++j) {
			if (ptr->data != ptr1->data)
			{
				cout << "Есть неодинаковые элементы: " << ptr->data << endl;
				return true;
			}

			ptr1 = ptr1->next;
		}
		ptr1 = op2.head;
		ptr = ptr->next;
	}
	cout << "Неодинаковых элементов нет" << endl;
	return false;
}

bool operator  >(const Queue& op1, const Queue& op2)
{
	int count = 0;
	el *ptr = op1.head, *ptr1 = op2.head;
	while (ptr)
	{
		if (ptr->data > ptr1->data)
		{
			cout << "Элемент под номером " << count + 1 << "больше чем элемент в другой очереди" << endl;
			return true;
		}
		ptr = ptr->next;
		ptr1 = ptr1->next;
		count++;
	}
	cout << "Такого элемента нет" << endl;
	return false;
}

bool operator  <(const Queue& op1, const Queue& op2)
{
	int count = 0;
	el *ptr = op1.head, *ptr1 = op2.head;
	while (ptr)
	{
		if (ptr->data < ptr1->data)
		{
			cout << "Элемент под номером " << count + 1 << "меньше чем элемент в другой очереди";
			return true;
		}
		ptr = ptr->next;
		ptr1 = ptr1->next;
		count++;
	}
	cout << "Такого элемента нет" << endl;
	return false;
}

Queue& operator +=(Queue& op1, const Queue& op2)
{
	el *ptr = op1.head, *ptr1 = op2.head;
	while (ptr)
	{
		ptr->data = ptr->data + ptr1->data;
		ptr = ptr->next;
		ptr1 = ptr1->next;
	}
	return op1;
}

Queue& operator -=(Queue& op1, const Queue& op2)
{
	el *ptr = op1.head, *ptr1 = op2.head;
	while (ptr)
	{
		ptr->data = ptr->data - ptr1->data;
		ptr = ptr->next;
		ptr1 = ptr1->next;
	}
	return op1;
}