#include "Queue.h"
#include "assert.h"

template<class T>
Node<T>::Node(T val)
{
	value = val;
	next = 0;
}

template<class T>
Node<T>::~Node()
{
}

template<class T>
int Queue<T>::length()
{
	return count;
}

template<class T>
T Queue<T>::Front()
{
	assert(count != 0);
	return front->value;
}

template<class T>
void Queue<T>::push(T val)
{
	Node<T>* n = new Node<T>(val);
	if (count == 0)
	{
		front = back = n;
	}
	else
	{
		back->next = n;
		back = n;
	}
	count++;

}

template<class T>
void Queue<T>::pop()
{
	assert(count != 0);
	if (count == 1)
	{
		delete front;
		front = back = 0;
	}
	else
	{
		Node<T>* tmp = front;
		tmp = tmp->next;
		delete front;
		front = tmp;
	}
	count--;
}

template<class T>
void Queue<T>::clear()
{
	while (count != 0)
		pop();
}

template<class T>
bool Queue<T>::Empty()
{
	return (count == 0);
}

template<class T>
Queue<T>::Queue()
{
	count = 0;
	front = 0;
	back = 0;
}

template<class T>
Queue<T>::~Queue()
{
	clear();
}
