#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
public:
    SinglyLinkedList() : head(nullptr) {}
    void insertFirst(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAfter(const T& prevData, const T& data) {
        Node<T>* current = head;
        while (current && current->data != prevData) {
            current = current->next;
        }
        if (current) {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void insertLast(const T& data) {
        Node<T>* newNode = new Node<T>(data);

        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = newNode;
    }

    bool removeFirst() {
        if (!head) {
            return false;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    bool removeAfter(const T& prevData) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current && current->data != prevData) {
            prev = current;
            current = current->next;
        }
        if (!current) {
            return false;
        }

        prev->next = current->next;
        delete current;
        return true;
    }
    bool removeLast() {
        if (!head) {
            return false;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return true;
        }
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current->next) {
            prev = current;
            current = current->next;
        }

        prev->next = nullptr;
        delete current;
        return true;
    }

    bool find(const T& data) const {
        Node<T>* current = head;
        while (current && current->data != data) {
            current = current->next;
        }

        return current != nullptr;
    }

    void printList() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

private:
    Node<T>* head;
};

int main() {
    SinglyLinkedList<int> list;

    list.insertFirst(10);
    list.insertFirst(5);
    list.insertLast(20);

    list.printList(); // Output: 5 10 20

    std::cout << "Found 10: " << list.find(10) << std::endl; // Output: Found 10: true
    std::cout << "Found 30: " << list.find(30) << std::endl; // Output: Found 30: false

    list.removeFirst();
    list.printList(); // Output will be: 10 20

    list.removeLast();
    list.printList(); // Output: 10

    list.removeAfter(10);
    list.printList(); // Output: 10

    return 0;
}
