#include <iostream>
#include "Stack.h"
#include "Deque.h"
#include "List.h"

using namespace std;
void workWithQueue(Queue<int>& queue);
void workWithStack(Stack<int>& stack);
void workWithDeque(Deque<int>& deque);
void workWithList(List<int>& list);
void inputFromFile(Queue<int>& queue, Stack<int>& stack, Deque<int>& deque, List<int>& list);
void printToFile(Queue<int>& queue, Stack<int>& stack, Deque<int>& deque, List<int>& list);

int main()
{
    setlocale(LC_ALL, "Rus");
	Queue<int> queue;
	Stack<int> stack;
	Deque<int> deque;
	List<int> list;

	cout << "Ввести изначальные данные из файла?(1/0)" << endl;
	int method = safeInput(0, 1);
	if (method == 1)
		inputFromFile(queue, stack, deque, list);

	bool isExit = false;
	while (!isExit) {
		cout << "1. Работать с очередью" << endl;
		cout << "2. Работать со стеком" << endl;
		cout << "3. Работать с деком" << endl;
		cout << "4. Работать со списком" << endl;
		cout << "5. Сохранить в файл" << endl;
		cout << "0. Выход" << endl;
		cout << "Выберете пункт меню: ";
		method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			workWithQueue(queue);
			break;
		case 2:
			workWithStack(stack);
			break;
		case 3:
			workWithDeque(deque);
			break;
		case 4:
			workWithList(list);
			break;
		case 5:
			printToFile(queue, stack, deque, list);
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void workWithQueue(Queue<int>& queue) {
	bool isExit = false;
	while (!isExit) {
		cout << "Работа с очередью" << endl;
		cout << "1. Добавить элемент" << endl;
		cout << "2. Извлечь элемент" << endl;
		cout << "3. Вывести на экран" << endl;
		cout << "4. Отсортировать" << endl;
		cout << "0. Назад" << endl;
		cout << "Выберете пункт меню: ";
		int method = safeInput(0, 4);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "Введите число, которое хотите добавить: ";
			tmp = safeInput(0, INT32_MAX);
			queue.push_back(tmp);
			break;
		case 2:
			try {
				cout << "Извлечено число: " << queue.pop_front() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 3:
			queue.printToConsole();
			break;
		case 4:
			queue.sort();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void workWithStack(Stack<int>& stack) {
	bool isExit = false;
	while (!isExit) {
		cout << "Работа со стеком" << endl;
		cout << "1. Добавить элемент" << endl;
		cout << "2. Извлечь элемент" << endl;
		cout << "3. Вывести на экран" << endl;
		cout << "4. Отсортировать" << endl;
		cout << "0. Назад" << endl;
		cout << "Выберете пункт меню: ";
		int method = safeInput(0, 4);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "Введите число, которое хотите добавить: ";
			tmp = safeInput(0, INT32_MAX);
			stack.push_back(tmp);
			break;
		case 2:
			try {
				cout << "Извлечено число: " << stack.pop_back() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 3:
			stack.printToConsole();
			break;
		case 4:
			stack.sort();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void workWithDeque(Deque<int>& deque) {
	bool isExit = false;
	while (!isExit) {
		cout << "Работа с деком" << endl;
		cout << "1. Добавить элемент в начало" << endl;
		cout << "2. Добавить элемент в конец" << endl;
		cout << "3. Извлечь элемент с начала" << endl;
		cout << "4. Извлечь элемент с конца" << endl;
		cout << "5. Вывести на экран" << endl;
		cout << "6. Отсортировать" << endl;
		cout << "0. Назад" << endl;
		cout << "Выберете пункт меню: ";
		int method = safeInput(0, 6);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "Введите число, которое хотите добавить: ";
			tmp = safeInput(0, INT32_MAX);
			deque.push_font(tmp);
			break;
		case 2:
			cout << "Введите число, которое хотите добавить: ";
			tmp = safeInput(0, INT32_MAX);
			deque.push_back(tmp);
			break;
		case 3:
			try {
				cout << "Извлечено число: " << deque.pop_front() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 4:
			try {
				cout << "Извлечено число: " << deque.pop_back() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 5:
			deque.printToConsole();
			break;
		case 6:
			deque.sort();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void workWithList(List<int>& list) {
	bool isExit = false;
	while (!isExit) {
		cout << "Работа с деком" << endl;
		cout << "1. Добавить элемент в начало" << endl;
		cout << "2. Добавить элемент в конец" << endl;
		cout << "3. Извлечь элемент с начала" << endl;
		cout << "4. Извлечь элемент с конца" << endl;
		cout << "5. Получить элемент по индексу" << endl;
		cout << "6. Вывести на экран" << endl;
		cout << "7. Отсортировать" << endl;
		cout << "0. Назад" << endl;
		cout << "Выберете пункт меню: ";
		int method = safeInput(0, 6);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "Введите число, которое хотите добавить: ";
			tmp = safeInput(0, INT32_MAX);
			list.push_font(tmp);
			break;
		case 2:
			cout << "Введите число, которое хотите добавить: ";
			tmp = safeInput(0, INT32_MAX);
			list.push_back(tmp);
			break;
		case 3:
			try {
				cout << "Извлечено число: " << list.pop_front() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 4:
			try {
				cout << "Извлечено число: " << list.pop_back() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 5:
			cout << "Введите индекс: ";
			tmp = safeInput(0, INT32_MAX);
			try {
				cout << "По индексу " << tmp << " лежит число: " << list[tmp] << endl;
			}
			catch (int err) {
				cout << "Индекс " << err  << " недопустим" << endl;
			}
			break;
		case 6:
			list.printToConsole();
			break;
		case 7:
			list.sort();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void inputFromFile(Queue<int>& queue, Stack<int>& stack, Deque<int>& deque, List<int>& list) {
	string filename;
	if (InputInFileName(filename)) {
		ifstream in(filename);
		try
		{
			queue.inputFromFile(in);
			stack.inputFromFile(in);
			deque.inputFromFile(in);
			list.inputFromFile(in);
		}
		catch (string err)
		{
			cout << err << endl;
		}
		in.close();
	}	
}

void printToFile(Queue<int>& queue, Stack<int>& stack, Deque<int>& deque, List<int>& list) {
	string filename;
	InputOutFileName(filename);
	ofstream out(filename);
	queue.printToFile(out);
	stack.printToFile(out);
	deque.printToFile(out);
	list.printToFile(out);
	out.close();
}