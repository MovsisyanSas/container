#pragma once
#include <iostream>
#include<stack>

template <typename T>
struct Node {
    T m_val;
    Node* next;
    Node(const T& value) : m_val(value), next(nullptr) {}
};

template <typename T>
class List {
private:
    Node<T>* head;

public:
    List() : head(nullptr) {}
    List(const Node<T>& obj) {
        head = new Node<T>(obj.m_val);
    }
    List(const List& obj) = default;
    List& operator=(const List& obj) = default;
    List(List&& obj) = default;
    List& operator=(List&& obj) = default;

    ~List() {
        clean();
    }

public:
    void print() {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot print." << std::endl;
            return;
        }

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
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot perform push_back." << std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(obj);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void pop_back() {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot perform pop_back." << std::endl;
            return;
        }

        if (head == nullptr) {
            return;
        }
        else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* previous = nullptr;
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                previous = temp;
                temp = temp->next;
            }
            delete temp;
            previous->next = nullptr;
        }
    }

    void insert(int pos, const T& obj) {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot perform insert." << std::endl;
            return;
        }

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
            temp->next = newNode;
        }
    }

    void erase(int pos) {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot perform erase." << std::endl;
            return;
        }

        if (pos == 0) {
            if (head != nullptr) {
                pop_front();
            }
        }
        else {
            Node<T>* temp = head;
            for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }

            if (temp == nullptr || temp->next == nullptr) {
                std::cout << "Invalid position for erasing." << std::endl;
                return;
            }

            Node<T>* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }
    }

    T front() {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot access front." << std::endl;
            return T();
        }

        if (head != nullptr) {
            return head->m_val;
        }
        else {
            std::cout << "List is empty" << std::endl;
            return T();
        }
    }

    T back() {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot access back." << std::endl;
            return T();
        }

        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return T();
        }
        else if (head->next == nullptr) {
            return head->m_val;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            return temp->m_val;
        }
    }

    void push_front(const T& obj) {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot perform push_front." << std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(obj);
        newNode->next = head;
        head = newNode;
    }

    void pop_front() {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot perform pop_front." << std::endl;
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }

    void clean() {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot perform clean." << std::endl;
            return;
        }

        while (head != nullptr) {
            Node<T>* temp2 = head;
            head = head->next;
            delete temp2;
            temp2 = nullptr;
        }
    }

    T n_th_from_end(int n) {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot perform n_th_from_end." << std::endl;
            return T();
        }

        Node<T>* temp1 = head;
        Node<T>* temp2 = nullptr;
        int x = 0;
        int y = x;
        while (temp1 != nullptr) {
            temp1 = temp1->next;
            if (x >= n) {
                y++;
                if (y == 1) {
                    temp2 = head;
                    temp2 = temp2->next;
                }
                else if (y >= 1) {
                    temp2 = temp2->next;
                }
            }
            x++;
        }
        if (temp2 == nullptr) {
            std::cout << "Invalid position" << std::endl;
            return T();
        }
        else {
            return temp2->m_val;
        }
    }

    void reverseList() {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot perform reverseList." << std::endl;
            return;
        }

        if (head == nullptr || head->next == nullptr) {
            std::cout << "List must include a minimum of 2 elements" << std::endl;
            return;
        }

        std::stack<Node<T>*> st;

        Node<T>* temp = head;
        while (temp != nullptr) {
            st.push(temp);
            temp = temp->next;
        }
        head = st.top();
        st.pop();
        temp = head;
        while (!st.empty()) {
            temp->next = st.top();
            st.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
    }

    void push_back(Node<T>* newNodePtr) {
        if (hasCycle()) {
            std::cout << "List has a cycle. Cannot perform push_back." << std::endl;
            return;
        }

        if (newNodePtr == nullptr) {
            std::cout << "Invalid node pointer" << std::endl;
            return;
        }

        newNodePtr->next = nullptr;

        if (head == nullptr) {
            head = newNodePtr;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNodePtr;
        }
    }

    bool hasCycle() {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        Node<T>* slow = head;
        Node<T>* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }

    void makeCycle(int pos) {
        if (pos <= 0 || head == nullptr) {
            return;
        }
        else {
            Node<T>* temp = head;
            for (int i = 0; i < pos && temp != nullptr; i++) {
                temp = temp->next;
            }
            push_back(temp);
        }
    }
};
