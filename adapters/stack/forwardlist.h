#pragma once

template <typename T>
struct Node {
    T m_val;
    Node* next;
    Node(const T& value) : m_val(value), next(nullptr) {}
};

template <typename T>
class List {
protected:
    Node<T>* head;
protected:
    List() : head(nullptr) {}
    List(const T& obj) {
        head = new Node<T>(obj);
    }
    List(const List& obj) = default;
    List& operator=(const List& obj) = default;
    List(List&& obj) = default;
    List& operator=(List&& obj) = default;

    ~List() {
        clean();
    }


protected:
    void print() {
        if (head != nullptr)
        {
            Node<T>* temp = head;
            while (temp != nullptr)
            {
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
        if (head == nullptr)
        {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void pop_back() {
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
            while (temp->next != nullptr)
            {
                previous = temp;
                temp = temp->next;
            }
            delete temp;
            previous->next = nullptr;
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
            temp->next = newNode;
        }
    }

    void erase(int pos) {
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
        if (head != nullptr)
        {
            return head->m_val;
        }
        else {
            std::cout << "List is empty" << std::endl;
        }
    }
    T back() {
        if (head == nullptr)
        {
            std::cout << "List is empty" << std::endl;
        }
        else if (head->next == nullptr) {
            return head->m_val;
        }
        else
        {
            Node<T>* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            return temp->m_val;
        }
    }
    void push_front(const T& obj) {
        Node<T>* newNode = new Node<T>(obj);
        newNode->next = head;
        head = newNode;
    }
    void pop_front() {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
    void clean() {
        while (head != nullptr) {
            Node<T>* temp2 = head;
            head = head->next;
            delete temp2;
            temp2 = nullptr;
        }
    }
};