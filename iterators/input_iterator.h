#pragma once
#include "vector.h"
#include <iostream>

template<typename T>
class input_iterator {
    T* m_ptr;
public:
    input_iterator() : m_ptr(nullptr) {}
    input_iterator(T* obj) : m_ptr(obj) {}
    ~input_iterator() { m_ptr = nullptr; delete m_ptr;  }
    input_iterator& operator=(const input_iterator& obj) { m_ptr = obj.m_ptr; return *this; }
    bool operator==(const input_iterator& obj) { return m_ptr == obj.m_ptr; }
    bool operator!=(const input_iterator& obj) { return m_ptr != obj.m_ptr; }
    input_iterator& operator++() { ++m_ptr; return *this; }
    input_iterator operator++(int) { input_iterator temp(*this); ++m_ptr; return temp; }
    T* operator->() { return m_ptr; }
    T operator*() { return *m_ptr; }
};
