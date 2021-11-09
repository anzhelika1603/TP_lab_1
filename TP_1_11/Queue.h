#pragma once
#include "Element.h"
#include "helper.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

template <class T>
class Queue
{
protected:
	Element<T>* tail;
	int size;
public:
	Queue() : size(0), tail(nullptr) { cout << "Вызван конструктор Queue" << endl; }
	Queue(const Queue& queue);
	~Queue();
	void push_back(T data);
	T pop_front();
	void clear();
	bool isEmpty();
	void printToConsole();
	void printToFile(ofstream& out);
	void inputFromFile(ifstream& out);
	void merge(Queue& queue);
	void sort();

	void getSize() { return size; }

	Queue<T>& operator=(const Queue<T>&);
};

template <class T>
Queue<T>::Queue(const Queue<T>& queue)
{
	tail = nullptr;
	size = 0;
	for (int i = 0; i < queue.size; i++)
	{
		Element<T>* e = queue.tail;
		for (int j = 0; j < queue.size - i - 1; j++)
			e = e->prev;
		push_back(e->data);
	}
	cout << "Вызван конструктор копирования Queue" << endl;
}

template <class T>
Queue<T>::~Queue()
{
	cout << "Вызван деструктор копирования Queue" << endl;
	clear();
}

template <class T>
void Queue<T>::push_back(T data)
{
	Element<T>* e = new Element<T>;
	e->data = data;
	e->prev = tail;
	tail = e;
	size++;
}

template <class T>
T Queue<T>::pop_front() {
	string err = "Очередь пуста, нечего извлекать";
	if (isEmpty())
		throw err;
	T data;
	Element<T>* e = this->tail;
	if (size == 1)
	{
		data = e->data;
		delete e;
		this->tail = nullptr;
		this->size--;
		return data;
	}
	for (int j = 0; j < size - 2; j++)
		e = e->prev;
	data = e->prev->data;
	delete e->prev;
	e->prev = nullptr;
	this->size--;
	return data;
}

template <class T>
void Queue<T>::clear()
{
	for (int i = 0; i < size; i++)
	{
		Element<T>* e = tail;
		for (int j = 0; j < size - i - 1; j++)
			e = e->prev;
		delete e;
	}
	tail = nullptr;
	size = 0;
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& queue)
{
	if (this == &queue)
		return *this;
	tail = nullptr;
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

template <class T>
bool Queue<T>::isEmpty() {
	return size == 0;
}

template <class T>
void Queue<T>::printToConsole() {
	if (size == 0)
		cout << "Очередь пуста";
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

template <class T>
void Queue<T>::printToFile(ofstream& out) {
	out << size << endl;
	for (int i = 0; i < size; i++)
	{
		Element<T>* e = tail;
		for (int j = 0; j < size - 1 - i; j++)
			e = e->prev;
		out << e->data << endl;
	}
}

template <class T>
void Queue<T>::inputFromFile(ifstream& out) {
	string err = "Файл не может быть корректно прочитан";
	string tmpS;
	if (!getline(out, tmpS))
		throw err;
	int tmpSize = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	for (int i = 0; i < tmpSize; i++) {
		if (!getline(out, tmpS))
			throw err;
		push_back(checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	}
}

template <class T>
void Queue<T>::merge(Queue& queue) {
	Queue tmp(queue);
	for (int i = 0; i < tmp.size; i++) {
		Element<T>* e = tmp.tail;
		for (int j = 0; j < tmp.size - i - 1; j++)
			e = e->prev;
		push_back(e->data);
	}
}

template <class T>
void Queue<T>::sort() {
	for (int i = 1; i < size; i++) {
		Element<T>* e1 = tail;
		for (int j = 0; j < size - i; j++) {
			if (e1->prev->data > e1->data)
				swap(e1->prev->data, e1->data);
			e1 = e1->prev;
		}		
	}		
}