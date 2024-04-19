//
// Created by sziha on 16/04/2024.
//


#include "vector.h"

template<typename T>
Vector<T>::Vector(const Vector &other) {
    size = other.size;
    data = new T[size];
    for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector &other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new T[size];
        for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
    }
    return *this;
}

template<typename T>
T &Vector<T>::operator[](size_t index) {
    if (index >= size) throw std::out_of_range("Index out of range");
    return data[index];
}

template<typename T>
const T &Vector<T>::operator[](size_t index) const {
    if (index >= size) throw std::out_of_range("Index out of range");
    return data[index];
}

template<typename T>
size_t Vector<T>::getSize() const {
    return size;
}

template<typename T>
void Vector<T>::push_back(T &value) {
    T* newData = new T[size + 1];
    for (size_t i = 0; i < size; ++i) newData[i] = data[i];
    newData[size] = value;
    delete[] data;
    data = newData;
    ++size;
}

template<typename T>
void Vector<T>::push_front(T &value) {
    T* newData = new T[size + 1];
    newData[0] = value;
    for (size_t i = 1; i <= size; ++i) newData[i] = data[i-1];
    delete[] data;
    data = newData;
    ++size;
}

template<typename T>
T &Vector<T>::pop_back() {
    --size;
    return data[size];
}

template<typename T>
T &Vector<T>::pop_front() {
    T* newData = new T[size - 1];
    T value = data[0];
    for (size_t i = 0; i < size - 1; ++i) newData[i] = data[i + 1];
    delete[] data;
    data = newData;
    --size;
    return value;
}

template<typename T>
void Vector<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
    os << "[";
    for (int i = 0; i < vector.getSize(); ++i) {
        os << vector.getData()[i] << " ";
    }
    return os << "]";
}


std::ostream& operator<<(std::ostream& os, const String& vector) {
    for (size_t i = 0; i < vector.getSize(); ++i) {
        os << vector.getData()[i];
    }
    return os;
}

template<typename T>
void Vector<T>::print() const {
    std::cout << *this << std::endl;
}

template<typename T>
T* Vector<T>::getData() const {
    return data;
}

template<typename T>
bool Vector<T>::operator==(const Vector<T> &other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

template<typename T>
void Vector<T>::operator+=(const Vector<T> &other) {
    for (size_t i = 0; i < other.size; ++i) push_back(other.data[i]);
}

template<typename T>
void Vector<T>::operator+=(const T &other) {
    push_back(other);
}

template<typename T>
T &Vector<T>::pop(size_t index) {
    if (index >= size) throw std::out_of_range("Index out of range");
    T* newData = new T[size - 1];
    T value = data[index];
    for (size_t i = 0; i < index; ++i) newData[i] = data[i];
    for (size_t i = index; i < size - 1; ++i) newData[i] = data[i + 1];
    delete[] data;
    data = newData;
    --size;
    return value;
}

template<typename T>
T &Vector<T>::remove(T &value) {
    size_t index = -1;
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == value) {
            index = i;
            break;
        }
    }
    if (index == std::numeric_limits<size_t>::max()) throw std::invalid_argument("Value not found");
    return pop(index);
}

template<typename T>
void Vector<T>::insert(size_t index, T &value) {
    if (index > size) throw std::out_of_range("Index out of range");
    T* newData = new T[size + 1];
    for (size_t i = 0; i < index; ++i) newData[i] = data[i];
    newData[index] = value;
    for (size_t i = index; i < size; ++i) newData[i + 1] = data[i];
    delete[] data;
    data = newData;
    ++size;
}

template<typename T>
std::istream& operator>>(std::istream& is, Vector<T>& vector)
{
    T value;
    while (is >> value) {
        vector.push_back(value);
    }
    return is;
}

template<typename T>
Vector<T>& Vector<T>::getSubVector(size_t start, size_t end) const{
    if (end >= size || start > end) throw std::out_of_range("Index out of range");
    Vector<T> subVector(end - start + 1);
    for (size_t i = start; i <= end; ++i) subVector.data[i - start] = data[i];
    return subVector;
}

template<typename T>
size_t Vector<T>::find(T &value) const {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == value) {
            return i;
        }
    }
    throw std::invalid_argument("Value not found");
}