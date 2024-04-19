//
// Created by sziha on 16/04/2024.
//

#ifndef NHF_VECTOR_H
#define NHF_VECTOR_H

#include <iostream>
#include <cstdlib>
#include <limits>
#include "memtrace.h"

class Edge;
class Node;

/**
 * Vector class.
 * @tparam T
 */
template<typename T>
class Vector  {
    T* data; /// Vector data
    size_t size; /// Vector size
public:
    /**
     * Vector constructor.
     */
    Vector() : data(new T[0]), size(0) {}
    /**
     * Vector constructor.
     * @param size
     */
    explicit Vector(size_t size) : data(new T[size]), size(size) {}
    /**
     * Vector constructor.
     * @param data
     * @param size
     */
    Vector(T* data, size_t size) : data(data), size(size) {}
    /**
     * Vector copy constructor.
     * @param other
     */
    Vector(const Vector& other);
    /**
     * Vector assignment operator.
     * @param other
     * @return Vector
     */
    Vector& operator=(const Vector& other);
    /**
     * Vector destructor.
     */
    ~Vector() { delete[] data;}

    /**
     * Vector index operator.
     * @param index
     * @return value
     * @throws std::out_of_range if index is greater than the vector size
     */
    T& operator[](size_t index);
    /**
     * Vector const index operator.
     * @param index
     * @return value
     * @throws std::out_of_range if index is greater than the vector size
     */
    const T& operator[](size_t index) const;
    /**
     * Returns the size of the vector.
     * @return size
     */
    size_t getSize() const;
    /**
     * Pushes a value to the end of the vector.
     * @param value
     */
    void push_back(T& value);
    /**
     * Pushes a value to the front of the vector.
     * @param value
     */
    void push_front(T& value);
    /**
     * Pops a value from the end of the vector.
     * @return value
     */
    T& pop_back();
    /**
     * Pops a value from the front of the vector.
     * @return value
     */
    T& pop_front();
    /**
     * Clears the vector.
     */
    void clear();
    /**
     * Prints the vector.
     */
    void print() const;
    /**
     * Returns the data of the vector.
     * @return data
     */
    T* getData() const;
    /**
     * Pop a value from the vector at the given index.
     * @param index
     * @return value
     * @throws std::out_of_range if index is greater than the vector size
     */
    T& pop(size_t index);
    /**
     * Removes a value from the vector.
     * @param value to be removed
     * @return the removed value
     * @throws std::invalid_argument if the value is not found
     */
    T& remove(T& value);
    /**
     * Inserts a value at the given index.
     * @param index
     * @param value
     * @throws std::out_of_range if index is greater than the vector size
     */
    void insert(size_t index, T& value);
    /**
     * Returns a sub vector.
     * @param start
     * @param end
     * @return Sub vector
     * @throws std::out_of_range if start is greater than end or start or end is greater than the vector size
     */
    Vector& getSubVector(size_t start, size_t end) const;
    /**
     * Finds a value in the vector.
     * @param value
     * @return the index of the value
     * @throws std::invalid_argument if the value is not found
     */
    size_t find(T& value) const;

    bool operator==(const Vector& other) const;
    void operator+=(const Vector& other);
    void operator+=(const T& other);

    
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector);

template<typename T>
std::istream& operator>>(std::istream& is, Vector<T>& vector);

typedef Vector<char> String;
#endif //NHF_VECTOR_H
