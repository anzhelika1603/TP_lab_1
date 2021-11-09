#pragma once
#include "Queue.h"

template <class T>
class Stack : private Queue<T>
{
public:
	Stack() : Queue<T>() {};
	Stack(const Stack<T>& stack) : Queue<T>(stack) {};
	void push_back(T data) { Queue<T>::push_back(data); };
	T pop_back();
	void clear() { Queue<T>::clear(); };
	bool isEmpty() { return Queue<T>::isEmpty(); };
	void printToConsole();
	void printToFile(ofstream& out) { Queue<T>::printToFile(); };
	void inputFromFile(ifstream& out) { Queue<T>::inputFromFile(); };
	void inputFromConsole() { Queue<T>::inputFromConsole(); };
	void merge(Stack<T>& stack) { Queue<T>::merge(stack); }
	void getSize() { Queue<T>::getSize(); }

	Stack<T>& operator=(const Stack<T>& stack);
};

template <class T>
T Stack<T>::pop_back() {
	string err = "Стек пуст, нечего извлекать";
	if (isEmpty())
		throw err;
	T data = Queue<T>::tail->data;
	Stack<T> tmp;
	for (int i = 0; i < Queue<T>::size - 1; i++)
	{
		Element<T>* e = Queue<T>::tail;
		for (int j = 0; j < Queue<T>::size - 1 - i; j++)
			e = e->prev;
		tmp.push_back(e->data);
	}
	*this = tmp;
	return data;
}

template <class T>
void Stack<T>::printToConsole() {
	if (Queue<T>::size == 0)
		cout << "Стек пуст";
	else
		for (int i = 0; i < Queue<T>::size; i++)
		{
			Element<T>* e = Queue<T>::tail;
			for (int j = 0; j < Queue<T>::size - 1 - i; j++)
				e = e->prev;
			cout << e->data << " ";
		}
	cout << endl;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack)
{
	if (this == &stack)
		return *this;
	Queue<T>::tail = NULL;
	Queue<T>::size = 0;
	clear();
	for (int i = 0; i < stack.size; i++)
	{
		Element<T>* e = stack.tail;
		for (int j = 0; j < stack.size - i - 1; j++)
			e = e->prev;
		push_back(e->data);
	}
	return *this;
}