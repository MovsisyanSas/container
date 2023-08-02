#pragma once

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
        }
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
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
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            if (temp->prev != nullptr) {
                temp->prev->next = nullptr;
            }
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
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
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
        Node<T>* newNode = new Node<T>(obj);
        if (head != nullptr) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    void pop_front() {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
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
    }
};
