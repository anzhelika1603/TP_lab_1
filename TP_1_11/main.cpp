#include <iostream>
#include "Stack.h"
#include "Deque.h"
#include "List.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    List<int> a, b;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_font(4);
    try
    {
        //a.merge(a);
        a.printToConsole();
        cout << a[0] << endl;
        cout << a[1] << endl;
        cout << a[2] << endl;
        cout << a[3] << endl;
        cout << a[4] << endl;
        cout << a.pop_front() << endl;
        cout << a.pop_back() << endl;
        cout << a.pop_back() << endl;
        cout << a.pop_back() << endl;
    }
    catch (string err)
    {
        cout << err << endl;
    }
    catch (int err)
    {
        cout << "dsfsdfsdf" << err << endl;
    }
    b.printToConsole();
}