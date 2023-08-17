#pragma once
#include <iostream>

template<typename T>
class my_vector
{
	T* ptr = nullptr;
	int Size = 0;
	int capacity = 0;
public:
	my_vector() = default;
	my_vector(int S) {
		if (S >= 0)
		{
			capacity = S;
			ptr = new T[capacity];
		}
		else {
			std::cout << "Error: vector creation with 0 and less size is impossible" << std::endl;
		}
	}
	my_vector(const my_vector& obj) {
		this->Size = obj.Size;
		this->capacity = obj.capacity;
		this->ptr = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			this->ptr[i] = obj.ptr[i];
		}
	}
	my_vector& operator = (const my_vector& obj) {
		if (this != &obj)
		{
			delete[] this->ptr;
			if (this->Size != obj.Size)
			{
				this->Size = obj.Size;
				this->capacity = obj.capacity;
			}
			this->ptr = new T[capacity];
			for (int i = 0; i < capacity; i++)
			{
				this->ptr[i] = obj.ptr[i];
			}
		}
		return *this;
	}
	T& operator [] (int i) {
		return *(ptr + i);
	}
	my_vector(my_vector&& obj) {
		this->Size = obj.Size;
		this->capacity = obj.capacity;
		this->ptr = obj.ptr;
		obj.Size = 0;
		obj.capacity = 0;
		obj.ptr = nullptr;
	}
	my_vector& operator = (my_vector&& obj) {
		if (this != &obj)
		{
			this->ptr = obj.ptr;
			this->Size = obj.Size;
			this->capacity = obj.capacity;
			obj.Size = 0;
			obj.capacity = 0;
			obj.ptr = nullptr;
		}
		return *this;
	}
	~my_vector() {
		delete[] ptr;
	}
public:
	int get_element(int element) {
		if (element >= Size)
		{
			std::cout << "Error: max size of array is: " << Size << " last element: " << Size - 1 << "so you can't get element: " << element << std::endl;
			return {};
		}
		else if (element < 0) {
			std::cout << "Error: you cant get element less than 0" << std::endl;
			return {};
		}
		else {
			return ptr[element];
		}
	}
	void print() {
		for (int i = 0; i < Size; i++)
		{
			std::cout << ptr[i] << ' ' << std::endl;
		}
		std::cout << std::endl;
	}

	int size() {
		return Size;
	}
	int max_size() {
		return capacity;
	}
	void resize(int i) {
		if (i > 0)
		{
			if (Size > 0)
			{
				T* temp = new T[i];
				for (int j = 0; j < i; j++) {
					temp[j] = ptr[j];
				}
				Size = i;
				ptr = temp;
			}
			else
			{
				Size = i;
			}
		}
	}
	void push_back(const T& obj) {
		if (Size == capacity) {
			if (capacity == 0)
				capacity = 1;
			else
				capacity = 2 * capacity;

			T* temp = new T[capacity];
			for (int i = 0; i < Size; i++) {
				temp[i] = ptr[i];
			}
			delete[] ptr;
			ptr = temp;
		}

		ptr[Size] = obj;
		Size++;
	}
	void push_back(T&& obj) {
		if (Size == capacity) {
			if (capacity == 0)
				capacity = 1;
			else
				capacity = 2 * capacity;

			T* temp = new T[capacity];
			for (int i = 0; i < Size; i++) {
				temp[i] = ptr[i];
			}
			delete[] ptr;
			ptr = temp;
		}

		ptr[Size] = obj;
		Size++;
	}
	void pop_back() {
		if (Size > 0) {
			Size--;
			if (Size == 0) {
				delete[] ptr;
				ptr = nullptr;
				capacity = 0;
			}
			else if (Size < capacity / 2) {
				capacity = capacity / 2;
				T* temp = new T[capacity];
				for (int i = 0; i < Size; i++) {
					temp[i] = ptr[i];
				}
				delete[] ptr;
				ptr = temp;
			}
		}
	}
	void swap(int pos1, int pos2) {
		ptr[pos1] = ptr[pos1] + ptr[pos2];
		ptr[pos2] = ptr[pos1] - ptr[pos2];
		ptr[pos1] = ptr[pos1] - ptr[pos2];
	}
	void erase(int pos) {
		if (pos < Size - 1)
		{
			if (1 == Size)
			{
				delete[] ptr;
				ptr = nullptr;
				capacity = 0;
				Size = 0;
			}
			else if (Size == 2) {
				if (pos == 0)
				{
					swap(ptr[0], ptr[1]);
				}
				pop_back();
			}
			else {
				for (int i = pos; i < Size - 1; i++) {
					swap(ptr[i], ptr[i + 1]);
				}
				pop_back();
			}
		}
		else if (pos == Size - 1) {
			pop_back();
		}
	}
	void insert(int pos, const T& value) {
		if (pos > Size) {
			std::cout << "Error: Position is out of range." << std::endl;
			return;
		}

		if (Size == capacity) {
			capacity = 2 * (Size + 1);
			T* temp = new T[capacity];
			for (int i = 0; i < Size; i++) {
				temp[i] = ptr[i];
			}
			delete[] ptr;
			ptr = temp;
		}

		for (int i = Size; i > pos; i--) {
			ptr[i] = ptr[i - 1];
		}

		ptr[pos] = value;
		Size++;
	}
	T* begin() { return ptr; }
	T* end() { return ptr + Size; }
};