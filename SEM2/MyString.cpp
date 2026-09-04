#include <iostream>
#include <cstring>

class Mistring {
private:
    char* data;

public:
    Mistring() : data(new char[1]) {
        data[0] = '\0';
    }

    Mistring(const char* str) {
        data = new char[strlen(str) + 1];
        int i = 0;
        for (i = 0; str[i] != '\0'; ++i) {
            data[i] = str[i];
        }
        data[i] = '\0';
    }

    Mistring(const Mistring& otro) {
        data = new char[strlen(otro.data) + 1];
        strcpy(data, otro.data);
    }

    Mistring& operator=(const Mistring& otro) {
        if (this == &otro) return *this;   
        delete[] data;                      
        data = new char[strlen(otro.data) + 1];
        strcpy(data, otro.data);
        return *this;
    }

    ~Mistring() {
        delete[] data;
    }

    int size() const { return strlen(data); }
    const char* c_str() const { return data; }
};

int main() {
    Mistring a("hola");
    Mistring b = a;
    std::cout << b.c_str() << " " << b.size() << "\n";
    return 0;
}