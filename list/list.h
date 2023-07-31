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
    unsigned int size;
    Node<T>* head;
public:
    List() : head(nullptr),size(0)  {}
    List(const Node<T>& obj) {
        head = new Node<T>(obj.m_val);
        size = 1;
    }
    List(const List& obj) = default;
    List& operator=(const List& obj) = default;
    List(List&& obj) = default;
    List& operator=(List&& obj) = default;

    ~List() {
        
    }

public:
    int Size() {
        return size;
    }
    void print() {
        Node<T>* temp = head;
        for (int i = 0; i < size; i++){
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
            for (int i = 0; i < size - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
    void pop_back() {
        if (size == 0) {
            return; 
        }
        else if (size == 1) {
            delete head; 
            head = nullptr;
        }
        else {
            Node<T>* previous = nullptr;
            Node<T>* temp = head;
            for (int i = 0; i < size - 1; i++)
            {
                previous = temp;
                temp = temp->next;
            }
            delete temp;
            previous->next = nullptr;
        }
        size--;
    }
    void insert(int pos, const T& obj) {
        if (pos <= size) {
            Node<T>* newNode = new Node<T>(obj);
            if (pos == 0) {
                newNode->next = head;
                head = newNode;
            }
            else {
                Node<T>* temp = head;
                Node<T>* previous = nullptr;
                for (int i = 0; i < pos; i++) {
                    previous = temp;
                    temp = temp->next;
                }
                previous->next = newNode;
                newNode->next = temp;
            }
            size++;
        }
        else {
            std::cout << "Invalid position for insertion." << std::endl;
        }
    }
    void erase(int pos) {
        if (pos < size) {
            Node<T>* previous = nullptr;
            Node<T>* temp = head;

            if (pos == 0) {
                head = temp->next;
                delete temp;
            }
            else {
                for (int i = 0; i < pos; i++) {
                    previous = temp;
                    temp = temp->next;
                }
                previous->next = temp->next;
                delete temp;
            }
            size--;
        }
        else {
            std::cout << "Invalid position for erasing." << std::endl;
        }
    }

};
