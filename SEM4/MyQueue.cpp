#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int k) : data(k), next(nullptr) {}
};

class MyQueue {
private:
    Node* head;
    Node* tail;
    int tamaño;
    
public:
    MyQueue() : head(nullptr), tail(nullptr), tamaño(0) {}
    
    void enqueue(int x) {
        Node* nuevo = new Node(x);
        
        if(tail == nullptr) {
            head = nuevo;
            tail = nuevo;
        } else {
            tail->next = nuevo;
            tail = nuevo;
        }
        tamaño++;
    }
    
    bool dequeue() {
        if(head == nullptr) {
            return false;
        }
        
        Node* temp = head;
        head = head->next;
        
        if(head == nullptr) {
            tail = nullptr;
        }
        
        delete temp;
        tamaño--;
        return true;
    }
    
    int front() {
        if(head == nullptr) {
            cout << "Queue vacía\n";
            return -1;
        }
        return head->data;
    }
    
    int back() {
        if(tail == nullptr) {
            cout << "Queue vacía\n";
            return -1;
        }
        return tail->data;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
    
    int size() {
        return tamaño;
    }
    
    void display() {
        if(head == nullptr) {
            cout << "Queue vacía\n";
            return;
        }
        
        cout << "Queue (inicio → fin): ";
        Node* actual = head;
        while(actual != nullptr) {
            cout << actual->data << " ";
            actual = actual->next;
        }
        cout << "\n";
    }
    
    ~MyQueue() {
        while(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
