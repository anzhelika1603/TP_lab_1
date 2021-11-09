#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    Queue<int> a,b;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    try
    {
        a.merge(a);
        /*a.printToConsole();
        cout << a.pop_front() << endl;
        cout << a.pop_front() << endl;
        cout << a.pop_front() << endl;
        cout << a.pop_front() << endl;
        cout << a.pop_front() << endl;*/
    }
    catch (string err)
    {
        cout << err << endl;
    }
    b.printToConsole();
}