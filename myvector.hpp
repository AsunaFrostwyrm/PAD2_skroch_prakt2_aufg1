#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <iostream>
#include <cstdlib>
#include <system_error>

template <class T>
class myVector {
    int sz;
    T* elem;
    int space;

public:

    myVector(); //Standardkonstruktor
    explicit myVector(int s)
    : sz{s}, space{s}, elem{new T[s]}
    {
    } // Konstruktor
    myVector(const myVector&); //Kopierkonstruktor
    myVector& operator=(const myVector& x); //Zuweisungsoperator
    ~myVector(); //Destruktor
    int size() const;
    int capacity() const;
    T& operator[](int n) const;
    const T& at(int p) const;
    T get(int m) const;
    void set(int n, T v);
    void reserve(int newspace); //Speicher reservieren
    void resize(int newsize); //Speicherbereich vergroessern
    void push_back(T d); //Wert anfuegen

};

template <class T>
myVector<T>::myVector() {
}

template <class T>
myVector<T>::myVector(const myVector& x) {
    int b = 0;
    sz = x.sz;
    space = x.space;
    for(size_t i{}; b<i; ++b) elem[b] = x.elem[b];
}

template <class T>
myVector<T>& myVector<T>::operator=(const myVector& a) {
    if (this == &a) return *this;
    if (a.sz <= space) {
        for (int i{}; i < a.sz; ++i) {
            elem[i] = a.elem[i];
        }

        sz = a.sz;
        return *this;
    }
    T * p{new T[a.sz]};
    for (int i{}; i < a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;
    elem = p;
    space = a.sz;
    sz = a.sz;
    return *this;
}

template <class T>
myVector<T>::~myVector() {
    delete[] elem;
}

template <class T>
int myVector<T>::size() const {
    return sz;
}

template <class T>
int myVector<T>::capacity() const {
    return space;
}

template <class T>
T& myVector<T>::operator[](int n) const {
    if (n < 0 || sz <= n) {
        std::cerr << "myVector::operator[](), bad index" << std::endl;
    }
    return elem[n];
}

template <class T>
const T& myVector<T>::at(int p) const {
    if (p < 0 || sz <= p) {
        std::cerr << "myVector::operator[](), bad index" << std::endl;
    } else {
        return elem[p];
    }
}

template <class T>
T myVector<T>::get(int m) const{
    return elem[m];
}

template <class T>
void myVector<T>::set(int n, T v){
    elem[n] = v;
}

template <class T>
void myVector<T>::reserve(int newspace) {
    if (newspace <= space) return;
    T * p{new T[newspace]};
    for (int i{}; i < sz; i++) p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newspace;
}

template <class T>
void myVector<T>::push_back(T d) {
    if (space == 0) {
        reserve(8);
    } else
        if (sz == space) {
        reserve(space * 2);
        elem[sz] = d;
        ++sz;
    }
}

template <class T>
void myVector<T>::resize(int newsize) {
    reserve(newsize);
    for (int i{sz}; i < newsize; ++i) {
        elem[i] = T{};
    }
    sz = newsize;
}
#endif /* MYVECTOR_HPP */

