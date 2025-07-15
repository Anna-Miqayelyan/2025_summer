#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <algorithm>

template <typename T>
class Vector {
private:
    T* arr;
    int cap;
    int sz;

    void resize();

public:
    Vector();                                  // Default constructor
    ~Vector();                                 // Destructor

    Vector(const Vector<T>& other);            // Copy constructor
    Vector<T>& operator=(const Vector<T>& other); // Copy assignment

    Vector(Vector<T>&& other) noexcept;        // Move constructor
    Vector<T>& operator=(Vector<T>&& other) noexcept; // Move assignment

    void push_back(const T& val);
    void pop_back();
    void insert(int index, const T& value);
    void erase(int index);

    T& operator[](int idx);
    const T& operator[](int idx) const;

    int size() const;
    int capacity() const;
    bool empty() const;
    void clear();

    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
};

// ------------------ IMPLEMENTATION ------------------

template <typename T>
Vector<T>::Vector() {
    cap = 2;
    sz = 0;
    arr = new T[cap];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
    cap = other.cap;
    sz = other.sz;
    arr = new T[cap];
    std::copy(other.arr, other.arr + sz, arr);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        delete[] arr;
        cap = other.cap;
        sz = other.sz;
        arr = new T[cap];
        std::copy(other.arr, other.arr + sz, arr);
    }
    return *this;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept {
    arr = other.arr;
    cap = other.cap;
    sz = other.sz;
    other.arr = nullptr;
    other.cap = 0;
    other.sz = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
    if (this != &other) {
        delete[] arr;
        arr = other.arr;
        cap = other.cap;
        sz = other.sz;
        other.arr = nullptr;
        other.cap = 0;
        other.sz = 0;
    }
    return *this;
}

template <typename T>
void Vector<T>::resize() {
    cap *= 2;
    T* temp = new T[cap];
    for (int i = 0; i < sz; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

template <typename T>
void Vector<T>::push_back(const T& val) {
    if (sz == cap)
        resize();
    arr[sz++] = val;
}

template <typename T>
void Vector<T>::pop_back() {
    if (sz == 0)
        throw std::underflow_error("Vector is empty");
    sz--;
}

template <typename T>
void Vector<T>::insert(int index, const T& value) {
    if (index < 0 || index > sz)
        throw std::out_of_range("Insert index out of range");

    if (sz == cap)
        resize();

    for (int i = sz; i > index; i--)
        arr[i] = arr[i - 1];

    arr[index] = value;
    sz++;
}

template <typename T>
void Vector<T>::erase(int index) {
    if (index < 0 || index >= sz)
        throw std::out_of_range("Erase index out of range");

    for (int i = index; i < sz - 1; i++)
        arr[i] = arr[i + 1];

    sz--;
}

template <typename T>
T& Vector<T>::operator[](int idx) {
    if (idx < 0 || idx >= sz)
        throw std::out_of_range("Index out of bounds");
    return arr[idx];
}

template <typename T>
const T& Vector<T>::operator[](int idx) const {
    if (idx < 0 || idx >= sz)
        throw std::out_of_range("Index out of bounds");
    return arr[idx];
}

template <typename T>
int Vector<T>::size() const {
    return sz;
}

template <typename T>
int Vector<T>::capacity() const {
    return cap;
}

template <typename T>
bool Vector<T>::empty() const {
    return sz == 0;
}

template <typename T>
void Vector<T>::clear() {
    sz = 0;
}

template <typename T>
T* Vector<T>::begin() {
    return arr;
}

template <typename T>
T* Vector<T>::end() {
    return arr + sz;
}

template <typename T>
const T* Vector<T>::begin() const {
    return arr;
}

template <typename T>
const T* Vector<T>::end() const {
    return arr + sz;
}

#endif // VECTOR_H
