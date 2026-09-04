#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int k) : data(k), next(nullptr) {}
};

class MyStack {
private:
    Node* head;
    int tamaño;
    
public:
    MyStack() : head(nullptr), tamaño(0) {}
    
    void push(int x) {
        Node* nuevo = new Node(x);
        nuevo->next = head;
        head = nuevo;
        tamaño++;
    }
    
    bool pop() {
        if(head == nullptr) {
            return false;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;
        tamaño--;
        return true;
    }
    
    int top() {
        if(head == nullptr) {
            cout << "Stack vacío\n";
            return -1;
        }
        return head->data;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
    
    int size() {
        return tamaño;
    }
    
    void display() {
        if(head == nullptr) {
            cout << "Stack vacío\n";
            return;
        }
        
        cout << "Stack (tope → base): ";
        Node* actual = head;
        while(actual != nullptr) {
            cout << actual->data << " ";
            actual = actual->next;
        }
        cout << "\n";
    }
    
    ~MyStack() {
        while(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
