#pragma once

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
        Node<T>* temp1 = head;
        while (temp1 != nullptr) {
            Node<T>* temp2 = temp1;
            temp1 = temp1->next;
            delete temp2;
        }
    }


public:
    void print() {
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->m_val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
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
            Node<T>* newNode = new Node<T>(obj);
            newNode->next = head;
            head = newNode;
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
                Node<T>* temp = head;
                head = head->next;
                delete temp;
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
};
