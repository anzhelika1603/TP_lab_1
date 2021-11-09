#pragma once
#include "Queue.h"

template <class T>
class List : private Queue<T>
{
public:
	List() : Queue<T>() {};
	List(const List<T>& list) : Queue<T>(list) {}
	void push_font(T data);
	void push_back(T data) { Queue<T>::push_back(data); }
	T pop_front() { return Queue<T>::pop_front(); }
	T pop_back();
	void clear() { Queue<T>::clear(); }
	bool isEmpty() { return Queue<T>::isEmpty(); }
	void printToConsole();
	void printToFile(ofstream& out) { Queue<T>::printToFile(); }
	void inputFromFile(ifstream& out) { Queue<T>::inputFromFile(); }
	void inputFromConsole() { Queue<T>::inputFromConsole(); }
	void merge(List<T>& list) { Queue<T>::merge(list); }
	void getSize() { Queue<T>::getSize(); }

	List<T>& operator=(const List<T>& list);
	T& operator[](int index);
};

template <class T>
void List<T>::push_font(T data) {
	List<T> tmp;
	tmp.push_back(data);
	tmp.merge(*this);
	*this = tmp;
}

template <class T>
T List<T>::pop_back() {
	string err = "Список пуст, нечего извлекать";
	if (isEmpty())
		throw err;
	T data = Queue<T>::tail->data;
	List<T> tmp;
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
void List<T>::printToConsole() {
	if (Queue<T>::size == 0)
		cout << "Список пуст";
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
List<T>& List<T>::operator=(const List<T>& list)
{
	if (this == &list)
		return *this;
	Queue<T>::tail = NULL;
	Queue<T>::size = 0;
	clear();
	for (int i = 0; i < list.size; i++)
	{
		Element<T>* e = list.tail;
		for (int j = 0; j < list.size - i - 1; j++)
			e = e->prev;
		push_back(e->data);
	}
	return *this;
}

template <class T>
T& List<T>::operator[](int index) {
	if (index < 0 || index >= Queue<T>::size)
		throw index;
	Element<T>* e = Queue<T>::tail;
	for (int i = 0; i < Queue<T>::size - 1 - index; i++)
		e = e->prev;
	return e->data;
}