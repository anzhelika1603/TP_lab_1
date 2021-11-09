#pragma once
#include "Queue.h"

template <typename T>
class Stack : private Queue
{
public:
	Stack() : Queue() {};
	Stack(const Stack& stack) : Queue(stack) {};
	void push_back(T data) { Queue<T>::push_back(data); };
	T pop_back();
	void clear() { Queue<T>::clear(); };
	bool isEmpty() { return Queue<T>::isEmpty(); };
	void printToConsole() { Queue<T>::printToConsole(); };
	void printToFile(ofstream& out) { Queue<T>::printToFile(); };
	void inputFromFile(ifstream& out) { Queue<T>::inputFromFile(); };
	void inputFromConsole() { Queue<T>::inputFromConsole(); };

	void getSize() { Queue<T>::getSize(); }

	Stack<T>& operator=(const Stack<T>& stack) { Queue<T>::operaror=(stack); };
};

template <typename T>
T Stack<T>::pop_back() {
	T data = NULL;
	return data;
}