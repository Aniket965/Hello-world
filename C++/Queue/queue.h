#pragma once


template<class T>
class Node
{
public:
	T value;
	Node<T>* next;

	Node(T);
	~Node();

};

template<class T>
class Queue
{
	int count;
	Node<T>* front;
	Node<T>* back;

public:
	int length();
	T Front();
	bool Empty();
	void push(T);
	void pop();
	void clear();
	Queue();
	~Queue();
};
