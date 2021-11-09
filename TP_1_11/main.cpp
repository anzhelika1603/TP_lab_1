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

	cout << "������ ����������� ������ �� �����?(1/0)" << endl;
	int method = safeInput(0, 1);
	if (method == 1)
		inputFromFile(queue, stack, deque, list);

	bool isExit = false;
	while (!isExit) {
		cout << "1. �������� � ��������" << endl;
		cout << "2. �������� �� ������" << endl;
		cout << "3. �������� � �����" << endl;
		cout << "4. �������� �� �������" << endl;
		cout << "5. ��������� � ����" << endl;
		cout << "0. �����" << endl;
		cout << "�������� ����� ����: ";
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
		cout << "������ � ��������" << endl;
		cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3. ������� �� �����" << endl;
		cout << "4. �������������" << endl;
		cout << "0. �����" << endl;
		cout << "�������� ����� ����: ";
		int method = safeInput(0, 4);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "������� �����, ������� ������ ��������: ";
			tmp = safeInput(0, INT32_MAX);
			queue.push_back(tmp);
			break;
		case 2:
			try {
				cout << "��������� �����: " << queue.pop_front() << endl;
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
		cout << "������ �� ������" << endl;
		cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3. ������� �� �����" << endl;
		cout << "4. �������������" << endl;
		cout << "0. �����" << endl;
		cout << "�������� ����� ����: ";
		int method = safeInput(0, 4);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "������� �����, ������� ������ ��������: ";
			tmp = safeInput(0, INT32_MAX);
			stack.push_back(tmp);
			break;
		case 2:
			try {
				cout << "��������� �����: " << stack.pop_back() << endl;
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
		cout << "������ � �����" << endl;
		cout << "1. �������� ������� � ������" << endl;
		cout << "2. �������� ������� � �����" << endl;
		cout << "3. ������� ������� � ������" << endl;
		cout << "4. ������� ������� � �����" << endl;
		cout << "5. ������� �� �����" << endl;
		cout << "6. �������������" << endl;
		cout << "0. �����" << endl;
		cout << "�������� ����� ����: ";
		int method = safeInput(0, 6);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "������� �����, ������� ������ ��������: ";
			tmp = safeInput(0, INT32_MAX);
			deque.push_font(tmp);
			break;
		case 2:
			cout << "������� �����, ������� ������ ��������: ";
			tmp = safeInput(0, INT32_MAX);
			deque.push_back(tmp);
			break;
		case 3:
			try {
				cout << "��������� �����: " << deque.pop_front() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 4:
			try {
				cout << "��������� �����: " << deque.pop_back() << endl;
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
		cout << "������ � �����" << endl;
		cout << "1. �������� ������� � ������" << endl;
		cout << "2. �������� ������� � �����" << endl;
		cout << "3. ������� ������� � ������" << endl;
		cout << "4. ������� ������� � �����" << endl;
		cout << "5. �������� ������� �� �������" << endl;
		cout << "6. ������� �� �����" << endl;
		cout << "7. �������������" << endl;
		cout << "0. �����" << endl;
		cout << "�������� ����� ����: ";
		int method = safeInput(0, 6);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "������� �����, ������� ������ ��������: ";
			tmp = safeInput(0, INT32_MAX);
			list.push_font(tmp);
			break;
		case 2:
			cout << "������� �����, ������� ������ ��������: ";
			tmp = safeInput(0, INT32_MAX);
			list.push_back(tmp);
			break;
		case 3:
			try {
				cout << "��������� �����: " << list.pop_front() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 4:
			try {
				cout << "��������� �����: " << list.pop_back() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 5:
			cout << "������� ������: ";
			tmp = safeInput(0, INT32_MAX);
			try {
				cout << "�� ������� " << tmp << " ����� �����: " << list[tmp] << endl;
			}
			catch (int err) {
				cout << "������ " << err  << " ����������" << endl;
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