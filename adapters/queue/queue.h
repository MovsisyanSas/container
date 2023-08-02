#pragma once
#include "List.h"

template <typename T>
class queue : private List<T> {
public:
	queue() : List<T>() {}
	queue(int obj) : List<T>(obj) {}
	queue(const queue& obj) = default;
	queue& operator=(const queue& obj) = default;
	queue(queue&& obj) = default;
	queue& operator=(queue&& obj) = default;
public:
	void push(T obj) { List<T>::push_front(obj); }
	void pop() { List<T>::pop_back(); }
	T top() {
		return List<T>::back();
	}
	T down() {
		return List<T>::front();
	}
};