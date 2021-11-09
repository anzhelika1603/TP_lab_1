#pragma once
#include "Element.h"
#include "helper.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

template <typename T>
class Queue
{
protected:
	Element<T>* tail;
	int size;
public:
	Queue() : size(0), tail(NULL) {};
	Queue(const Queue& queue);
	virtual ~Queue();
	void push_back(T data);
	T pop_front();
	void clear();
	bool isEmpty();
	void printToConsole();
	void printToFile(ofstream& out);
	void inputFromFile(ifstream& out);
	void inputFromConsole();
	void merge(Queue& queue);

	void getSize() { return size; }

	Queue<T>& operator=(const Queue<T>&);
};

template <typename T>
Queue<T>::Queue(const Queue<T>& queue)
{
	tail = NULL;
	size = 0;
	for (int i = 0; i < queue.size; i++)
	{
		Element<T>* e = queue.tail;
		for (int j = 0; j < queue.size - i - 1; j++)
			e = e->prev;
		push_back(e->data);
	}
}

template <typename T>
Queue<T>::~Queue()
{
	clear();
}

template <typename T>
void Queue<T>::push_back(T data)
{
	Element<T>* e = new Element<T>;
	e->data = data;
	e->prev = tail;
	tail = e;
	size++;
}

template <typename T>
T Queue<T>::pop_front() {
	string err = "ќчередь пуста, нечего извлекать";
	if (isEmpty())
		throw err;
	T data;
	Element<T>* e = this->tail;
	if (size == 1)
	{
		data = e->data;
		delete e;
		this->tail = NULL;
		this->size--;
		return data;
	}
	for (int j = 0; j < size - 2; j++)
		e = e->prev;
	data = e->prev->data;
	delete e->prev;
	e->prev = NULL;
	this->size--;
	return data;
}

template <typename T>
void Queue<T>::clear()
{
	for (int i = 0; i < size; i++)
	{
		Element<T>* e = tail;
		for (int j = 0; j < size - i - 1; j++)
			e = e->prev;
		delete e;
	}
	tail = NULL;
	size = 0;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& queue)
{
	if (this == &queue)
		return *this;
	tail = NULL;
	size = 0;
	clear();
	for (int i = 0; i < queue.size; i++)
	{
		Element<T>* e = queue.tail;
		for (int j = 0; j < queue.size - i - 1; j++)
			e = e->prev;
		push_back(e->data);
	}
	return *this;
}

template <typename T>
bool Queue<T>::isEmpty() {
	return size == 0;
}

template <typename T>
void Queue<T>::printToConsole() {
	if (size == 0)
		cout << "ќчередь пуста";
	else
		for (int i = 0; i < size; i++)
		{
			Element<T>* e = tail;
			for (int j = 0; j < size - 1 - i; j++)
				e = e->prev;
			cout << e->data << " ";
		}
	cout << endl;
}

template <typename T>
void Queue<T>::printToFile(ofstream& out) {
	out << size << endl;
	for (int i = 0; i < size; i++)
	{
		Element<T>* e = tail;
		for (int j = 0; j < size - 1 - i; j++)
			e = e->prev;
		cout << e->data << endl;
	}
}

template <typename T>
void Queue<T>::inputFromConsole() {
	clear();
	cout << "¬ведите размер очереди: ";
	size = safeInput(T(0), T(INT32_MAX));
	for (int i = 0; i < size; i++) {
		T tmp;
		cout << "¬ведите " << i + 1 << " элемент очереди: ";
		tmp = safeInput(T(0), T(INT32_MAX));
		push_back(tmp);
	}
}

template <typename T>
void Queue<T>::inputFromFile(ifstream& out) {
	string err = "‘айл не может быть корректно прочитан";
	string tmpS;
	if (!getline(out, tmpS))
		throw err;
	size = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	for (int i = 0; i < size; i++) {
		if (!getline(out, tmpS))
			throw err;
		push_back(checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	}
}

template <typename T>
void Queue<T>::merge(Queue& queue) {
	Queue tmp(queue);
	for (int i = 0; i < tmp.size; i++) {
		Element<T>* e = tmp.tail;
		for (int j = 0; j < tmp.size - i - 1; j++)
			e = e->prev;
		push_back(e->data);
	}
}