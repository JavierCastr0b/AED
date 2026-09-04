#include <bits/stdc++.h>
using namespace std;

class NodeDoble {
public:
    int data;
    NodeDoble* next;
    NodeDoble* prev;
    NodeDoble(int k) : data(k), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
private:
    NodeDoble* head;
    NodeDoble* tail;
    
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}
    
    DoubleLinkedList(const DoubleLinkedList& otra) {
        if(otra.head == nullptr) {
            head = nullptr;
            tail = nullptr;
            return;
        }
        
        head = new NodeDoble(otra.head->data);
        tail = head;
        NodeDoble* original = otra.head->next;
        
        while(original != nullptr) {
            NodeDoble* nuevo = new NodeDoble(original->data);
            tail->next = nuevo;
            nuevo->prev = tail;
            tail = nuevo;
            original = original->next;
        }
    }
    
    DoubleLinkedList(initializer_list<int> valores) {
        head = nullptr;
        tail = nullptr;
        
        for(int valor : valores) {
            if(head == nullptr) {
                head = new NodeDoble(valor);
                tail = head;
            } else {
                NodeDoble* nuevo = new NodeDoble(valor);
                tail->next = nuevo;
                nuevo->prev = tail;
                tail = nuevo;
            }
        }
    }
    
    ~DoubleLinkedList() {
        NodeDoble* actual = head;
        while(actual != nullptr) {
            NodeDoble* temp = actual;
            actual = actual->next;
            delete temp;
        }
    }
    
    void push_front(int x) {
        NodeDoble* nuevo = new NodeDoble(x);
        
        if(head == nullptr) {
            head = nuevo;
            tail = nuevo;
        } else {
            nuevo->next = head;
            head->prev = nuevo;
            head = nuevo;
        }
    }
    
    bool pop_front() {
        if(head == nullptr) {
            return false;
        }
        
        if(head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return true;
        }
        
        NodeDoble* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return true;
    }
    
    void push_back(int x) {
        NodeDoble* nuevo = new NodeDoble(x);
        
        if(tail == nullptr) {
            head = nuevo;
            tail = nuevo;
        } else {
            tail->next = nuevo;
            nuevo->prev = tail;
            tail = nuevo;
        }
    }
    
    bool pop_back() {
        if(tail == nullptr) {
            return false;
        }
        
        if(head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return true;
        }
        
        NodeDoble* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        return true;
    }
    
    bool search(int x) {
        NodeDoble* actual = head;
        
        while(actual != nullptr) {
            if(actual->data == x) {
                return true;
            }
            actual = actual->next;
        }
        
        return false;
    }
    
    bool remove(int x) {
        if(head == nullptr) {
            return false;
        }
        
        if(head->data == x) {
            if(head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
                return true;
            }
            
            NodeDoble* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return true;
        }
        
        NodeDoble* actual = head;
        while(actual != nullptr) {
            if(actual->data == x) {
                if(actual == tail) {
                    tail = actual->prev;
                    tail->next = nullptr;
                } else {
                    actual->prev->next = actual->next;
                    actual->next->prev = actual->prev;
                }
                delete actual;
                return true;
            }
            actual = actual->next;
        }
        
        return false;
    }
    
    bool insert(int ref, int x) {
        NodeDoble* actual = head;
        
        while(actual != nullptr) {
            if(actual->data == ref) {
                NodeDoble* nuevo = new NodeDoble(x);
                nuevo->next = actual->next;
                nuevo->prev = actual;
                
                if(actual == tail) {
                    tail = nuevo;
                } else {
                    actual->next->prev = nuevo;
                }
                
                actual->next = nuevo;
                return true;
            }
            actual = actual->next;
        }
        
        return false;
    }
    
    void reverse() {
        NodeDoble* actual = head;
        NodeDoble* temp = nullptr;
        
        while(actual != nullptr) {
            temp = actual->prev;
            actual->prev = actual->next;
            actual->next = temp;
            actual = actual->prev;
        }
        
        temp = head;
        head = tail;
        tail = temp;
    }
    
    void join(DoubleLinkedList& otra) {
        if(head == nullptr) {
            head = otra.head;
            tail = otra.tail;
            otra.head = nullptr;
            otra.tail = nullptr;
            return;
        }
        
        if(otra.head == nullptr) {
            return;
        }
        
        tail->next = otra.head;
        otra.head->prev = tail;
        tail = otra.tail;
        otra.head = nullptr;
        otra.tail = nullptr;
    }


    void display() {
    if(head == nullptr) {
        cout << "Lista vacía\n";
        return;
    }
    
    NodeDoble* actual = head;
    while(actual != nullptr) {
        cout << actual->data;
        actual = actual->next;
        if(actual != nullptr) {
            cout << " ↔ ";
        }
    }
    cout << "\n";
    }
};
