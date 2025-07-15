#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.insert(1, 15);

    cout << "Vector contents: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    v.erase(2);

    cout << "After erase: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    Vector<string> names;
    names.push_back("Alice");
    names.push_back("Bob");

    cout << "Names: ";
    for (const auto& name : names)
        cout << name << " ";
    cout << endl;

    return 0;
}
