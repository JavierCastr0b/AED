#include <bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int k) : data(k), next(nullptr), prev(nullptr) {}
    
};



class LinkedList{
private:
    Node* head;

public: 
    LinkedList() : head(nullptr){}

    LinkedList(const LinkedList& otra){
        if(otra.head == nullptr){
            head = nullptr;
            return;
        }
        head = new Node(otra.head->data);
        
        Node* actual = head;
        Node* original = otra.head->next;

        while(original != nullptr){
            actual->next = new Node(original->data);
            actual = actual->next;
            original = original->next;
        }
    }

    LinkedList(initializer_list<int> valores){
        head = nullptr;        
        for(int valor : valores)
            if(head == nullptr){
                head == new Node(valor);
            } else {
                Node* actual = head;
                while(actual->next != nullptr){
                    actual = actual->next;
                }
                actual = new Node(valor);
            }
    }

    ~LinkedList() {
    Node* actual = head;
    while(actual != nullptr) {
        Node* temp = actual;
        actual = actual->next;
        delete temp; 
        }
    }

    void push_front(int x){
        Node* nuevo = new Node(x);
        nuevo->next = head;
        head = nuevo;
    }

    void push_back(int x){
        Node* nuevo = new Node(x);
        if(head == nullptr){
            head = nuevo;
            return;
        }
        Node* actual = head;
        while(actual->next != nullptr){
            actual = actual->next;
        }
        actual->next = nuevo;

    }

    bool pop_front(){
        if(head == nullptr){
            return false;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    bool pop_back(){
        if(head == nullptr){
            return false;
        }
        Node* actual = head;
        while(actual->next->next != nullptr){
            actual = actual->next;
        }

        delete actual->next;
        actual->next = nullptr;
        return true;
    }

    bool search(int x){
        Node* actual = head;
        
        while(actual != nullptr){
            if(actual->data == x){
                return true;
            }
            actual = actual->next;
        }
        
        return false;
    }



    bool remove(int x){
        if(head == nullptr){
            return false;
        }
        
        if(head->data == x){
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        
        Node* actual = head;
        while(actual->next != nullptr){
            if(actual->next->data == x){
                Node* temp = actual->next;
                actual->next = actual->next->next;
                delete temp;
                return true;
            }
            actual = actual->next;
        }
        
        return false;
    }

    bool insert(int ref, int x){
        Node* actual = head;
        
        while(actual != nullptr){
            if(actual->data == ref){
                Node* nuevo = new Node(x);
                nuevo->next = actual->next;
                actual->next = nuevo;
                return true;
            }
            actual = actual->next;
        }
        
        return false;
    }

    void reverse(){
        Node* prev = nullptr;
        Node* actual = head;
        
        while(actual != nullptr){
            Node* next = actual->next;
            actual->next = prev;
            prev = actual;
            actual = next;
        }
        
        head = prev;
    }


    void join(LinkedList& otra) {
    if(head == nullptr) {
        head = otra.head;
        otra.head = nullptr;
        return;
    }
    
    if(otra.head == nullptr) {
        return;
    }
    
    Node* actual = head;
    while(actual->next != nullptr) {
        actual = actual->next;
    }
    
    actual->next = otra.head;
    otra.head = nullptr; 
    }

    void display() {
    if(head == nullptr) {
        cout << "Lista vacía\n";
        return;
    }
    
    Node* actual = head;
    while(actual != nullptr) {
        cout << actual->data;
        actual = actual->next;
        if(actual != nullptr) {
            cout << " ";
        }
    }
    cout << "\n";
    }

     Node* getHead(){
        return head;
    };



};


int main(){
    int n;
    cin>>n;
    LinkedList lista;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        lista.push_back(x);
    }


    Node* actual = lista.getHead();
    Node* child = actual;
    while(actual != nullptr){
        actual = actual->next;
        


    }




}