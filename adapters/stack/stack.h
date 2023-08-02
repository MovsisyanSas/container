#pragma once
#include "forwardlist.h"
#include "vector.h"

template<typename T>
class v_stack : private my_vector<T>{
public:
	v_stack() : my_vector<T>(0){}
	v_stack(int S) : my_vector<T>(S){}
	v_stack(const v_stack& obj) = default;
	v_stack& operator=(const v_stack& obj) = default;
	v_stack(v_stack&& obj) = default;
	v_stack& operator=(v_stack&& obj) = default;
public:
	void push(T obj) { my_vector<T>::push_back(obj); }
	void pop() { my_vector<T>::pop_back(); }
	T top() {
		return my_vector<T>::back();
	}
};

template<typename T>
class l_stack : private List<T> {
public:
	l_stack() : List<T>() {}
	l_stack(int obj) : List<T>(obj) {}
	l_stack(const l_stack& obj) = default;
	l_stack& operator=(const l_stack& obj) = default;
	l_stack(l_stack&& obj) = default;
	l_stack& operator=(l_stack&& obj) = default;
public:
	void push(T obj) { List<T>::push_back(obj); }
	void pop() { List<T>::pop_back(); }
	T top() {
		return List<T>::back();
	}
};