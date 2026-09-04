#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int k) : data(k), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
    
public:
    CircularLinkedList() : head(nullptr) {}
    
    CircularLinkedList(const CircularLinkedList& otra) {
        if(otra.head == nullptr) {
            head = nullptr;
            return;
        }
        
        head = new Node(otra.head->data);
        Node* actual = head;
        Node* original = otra.head->next;
        
        while(original != otra.head) {
            actual->next = new Node(original->data);
            actual = actual->next;
            original = original->next;
        }
        actual->next = head;
    }
    
    CircularLinkedList(initializer_list<int> valores) {
        head = nullptr;
        
        for(int valor : valores) {
            if(head == nullptr) {
                head = new Node(valor);
                head->next = head;
            } else {
                Node* actual = head;
                while(actual->next != head) {
                    actual = actual->next;
                }
                Node* nuevo = new Node(valor);
                actual->next = nuevo;
                nuevo->next = head;
            }
        }
    }
    
    ~CircularLinkedList() {
        if(head == nullptr) return;
        
        Node* actual = head;
        while(actual->next != head) {
            Node* temp = actual;
            actual = actual->next;
            delete temp;
        }
        delete actual;
    }
    
    void push_front(int x) {
        Node* nuevo = new Node(x);
        
        if(head == nullptr) {
            head = nuevo;
            head->next = head;
        } else {
            Node* actual = head;
            while(actual->next != head) {
                actual = actual->next;
            }
            nuevo->next = head;
            actual->next = nuevo;
            head = nuevo;
        }
    }
    
    bool pop_front() {
        if(head == nullptr) {
            return false;
        }
        
        if(head->next == head) {
            delete head;
            head = nullptr;
            return true;
        }
        
        Node* actual = head;
        while(actual->next != head) {
            actual = actual->next;
        }
        
        Node* temp = head;
        head = head->next;
        actual->next = head;
        delete temp;
        return true;
    }
    
    void push_back(int x) {
        Node* nuevo = new Node(x);
        
        if(head == nullptr) {
            head = nuevo;
            head->next = head;
        } else {
            Node* actual = head;
            while(actual->next != head) {
                actual = actual->next;
            }
            actual->next = nuevo;
            nuevo->next = head;
        }
    }
    
    bool pop_back() {
        if(head == nullptr) {
            return false;
        }
        
        if(head->next == head) {
            delete head;
            head = nullptr;
            return true;
        }
        
        Node* actual = head;
        while(actual->next->next != head) {
            actual = actual->next;
        }
        
        delete actual->next;
        actual->next = head;
        return true;
    }
    
    bool search(int x) {
        if(head == nullptr) {
            return false;
        }
        
        Node* actual = head;
        do {
            if(actual->data == x) {
                return true;
            }
            actual = actual->next;
        } while(actual != head);
        
        return false;
    }
    
    bool remove(int x) {
        if(head == nullptr) {
            return false;
        }
        
        if(head->data == x) {
            if(head->next == head) {
                delete head;
                head = nullptr;
                return true;
            }
            
            Node* actual = head;
            while(actual->next != head) {
                actual = actual->next;
            }
            
            Node* temp = head;
            head = head->next;
            actual->next = head;
            delete temp;
            return true;
        }
        
        Node* actual = head;
        do {
            if(actual->next->data == x) {
                Node* temp = actual->next;
                actual->next = actual->next->next;
                delete temp;
                return true;
            }
            actual = actual->next;
        } while(actual != head);
        
        return false;
    }
    
    bool insert(int ref, int x) {
        if(head == nullptr) {
            return false;
        }
        
        Node* actual = head;
        do {
            if(actual->data == ref) {
                Node* nuevo = new Node(x);
                nuevo->next = actual->next;
                actual->next = nuevo;
                return true;
            }
            actual = actual->next;
        } while(actual != head);
        
        return false;
    }
    
    void reverse() {
        if(head == nullptr || head->next == head) {
            return;
        }
        
        Node* prev = nullptr;
        Node* actual = head;
        Node* siguiente = nullptr;
        
        do {
            siguiente = actual->next;
            actual->next = prev;
            prev = actual;
            actual = siguiente;
        } while(actual != head);
        
        head->next = prev;
        head = prev;
    }
    
    void join(CircularLinkedList& otra) {
        if(head == nullptr) {
            head = otra.head;
            return;
        }
        
        if(otra.head == nullptr) {
            return;
        }
        
        Node* ultimo_this = head;
        while(ultimo_this->next != head) {
            ultimo_this = ultimo_this->next;
        }
        
        Node* ultimo_otra = otra.head;
        while(ultimo_otra->next != otra.head) {
            ultimo_otra = ultimo_otra->next;
        }
        
        ultimo_this->next = otra.head;
        ultimo_otra->next = head;
    }
    

    void display() {
    if(head == nullptr) {
        cout << "Lista vacía\n";
        return;
    }
    
    Node* actual = head;
    do {
        cout << actual->data;
        actual = actual->next;
        if(actual != head) {
            cout << " → ";
        }
    } while(actual != head);
    cout << " → (back to " << head->data << ")\n";
    }
};