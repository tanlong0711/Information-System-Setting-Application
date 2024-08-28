#include "list.h"

template <class T>
List<T>::List()
{
    this->index = 0;
}

template <typename T>
List<T>::~List(){}

template<class T>
void List<T>::add(T const& item)
{
    if (index < 100) {
        this->elements_[index] = item; // Lưu setting vào xe thứ index
       this-> index++;
    }
}

template<class T>
T List<T>::get(int pos)
{
    return this->elements_[pos];
}

template<class T>
int List<T>::size()
{
    return this->index;
}

template<class T>
void List<T>::swapObj(int i, int j) { //Swap objects
    T temp = elements_[i];
    elements_[i] = elements_[j];
    elements_[j] = temp;
}

