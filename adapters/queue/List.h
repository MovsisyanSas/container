#pragma once
#include <iostream>

template <typename T>
struct Node {
    T m_val;
    Node* next;
    Node* prev;
    Node(const T& value) : m_val(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* end;

protected:
    List() : head(nullptr), end(nullptr) {}
    List(const Node<T>& obj) {
        head = new Node<T>(obj.m_val);
        end = head;
    }
    List(const List& obj) = delete;
    List& operator=(const List& obj) = delete;
    List(List&& obj) = delete;
    List& operator=(List&& obj) = delete;

    ~List() {
        clean();
    }

protected:
    void print() {
        if (head != nullptr) {
            Node<T>* temp = head;
            while (temp != nullptr) {
                std::cout << temp->m_val << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "List is empty" << std::endl;
        }
    }

    void push_back(const T& obj) {
        Node<T>* newNode = new Node<T>(obj);
        if (head == nullptr) {
            head = newNode;
            end = head;
        }
        else {
            end->next = newNode;
            newNode->prev = end;
            end = newNode;
        }
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }
        else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            end = nullptr;
        }
        else {
            Node<T>* temp = end;
            end = end->prev;
            end->next = nullptr;
            delete temp;
        }
    }

    void insert(int pos, const T& obj) {
        if (pos == 0) {
            push_front(obj);
        }
        else {
            Node<T>* temp = head;
            for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                std::cout << "Invalid position for insertion." << std::endl;
                return;
            }

            Node<T>* newNode = new Node<T>(obj);
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }

    void erase(int pos) {
        if (pos == 0) {
            pop_front();
        }
        else {
            Node<T>* temp = head;
            for (int i = 0; i < pos && temp != nullptr; i++) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                std::cout << "Invalid position for erasing." << std::endl;
                return;
            }

            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }

            if (temp == head) {
                head = temp->next;
            }
            if (temp == end) {
                end = temp->prev;
            }

            delete temp;
        }
    }

    T front() {
        if (head != nullptr) {
            return head->m_val;
        }
        else {
            std::cout << "List is empty" << std::endl;
        }
    }

    T back() {
        if (end != nullptr) {
            return end->m_val;
        }
        else {
            std::cout << "List is empty" << std::endl;
        }
    }

    void push_front(const T& obj) {
        Node<T>* newNode = new Node<T>(obj);
        if (head != nullptr) {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else {
            head = newNode;
            end = newNode;
        }
    }

    void pop_front() {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                end = nullptr;
            }
            delete temp;
        }
    }

    void clean() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        end = nullptr;
    }
};