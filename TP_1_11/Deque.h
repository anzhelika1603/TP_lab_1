#pragma once
#include "Queue.h"

template <class T>
class Deque : private Queue<T>
{
public:
	Deque() : Queue<T>() {};
	Deque(const Deque<T>& deque) : Queue<T>(deque) {}
	void push_font(T data);
	void push_back(T data) { Queue<T>::push_back(data); }
	T pop_front() { return Queue<T>::pop_front(); }
	T pop_back();
	void clear() { Queue<T>::clear(); }
	bool isEmpty() { return Queue<T>::isEmpty(); }
	void printToConsole();
	void printToFile(ofstream& out) { Queue<T>::printToFile(out); }
	void inputFromFile(ifstream& in) { Queue<T>::inputFromFile(in); }
	void inputFromConsole() { Queue<T>::inputFromConsole(); }
	void merge(Deque<T>& deque) { Queue<T>::merge(deque); }
	void getSize() { Queue<T>::getSize(); }
	void sort() { Queue<T>::sort(); }

	Deque<T>& operator=(const Deque<T>& deque);
};

template <class T>
void Deque<T>::push_font(T data) {
	Deque<T> tmp;
	tmp.push_back(data);
	tmp.merge(*this);
	*this = tmp;
}

template <class T>
T Deque<T>::pop_back() {
	string err = "Дек пуст, нечего извлекать";
	if (isEmpty())
		throw err;
	T data = Queue<T>::tail->data;
	Deque<T> tmp;
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
void Deque<T>::printToConsole() {
	if (Queue<T>::size == 0)
		cout << "Дек пуст";
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
Deque<T>& Deque<T>::operator=(const Deque<T>& deque)
{
	if (this == &deque)
		return *this;
	Queue<T>::tail = NULL;
	Queue<T>::size = 0;
	clear();
	for (int i = 0; i < deque.size; i++)
	{
		Element<T>* e = deque.tail;
		for (int j = 0; j < deque.size - i - 1; j++)
			e = e->prev;
		push_back(e->data);
	}
	return *this;
}