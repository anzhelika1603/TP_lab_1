#include <iostream>
#include "Stack.h"
#include "Deque.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    Deque<int> a, b;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_font(4);
    try
    {
        a.merge(a);
        a.printToConsole();
        cout << a.pop_front() << endl;
        cout << a.pop_front() << endl;
        cout << a.pop_back() << endl;
        cout << a.pop_back() << endl;
        cout << a.pop_back() << endl;
    }
    catch (string err)
    {
        cout << err << endl;
    }
    b.printToConsole();
}