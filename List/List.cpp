#include <iostream>
#include <exception>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class List {
private:
    Node* head;
public:
    List() {
        head = nullptr;
    }
    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    void pop() {
        if (head == nullptr) {
            throw logic_error("Error: list is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void print() {
        if (head == nullptr) {
            throw logic_error("Error: list is empty");
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    try {
        List list1;
        list1.push(2);
        list1.push(3);
        list1.push(6);
        list1.push(8);
        list1.push(9);

        list1.print();

        list1.pop();
        list1.pop();
        list1.pop();

        list1.print();
    }
    catch (const logic_error& e) {
        cout << "Error - " << e.what() << endl;
    }
}