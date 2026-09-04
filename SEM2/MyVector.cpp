

class MyVector {
    private:
        int* data;
        int sz; //elementos actuales
        int cap; //espacio disponible

        void redimensionar(int nuevaCap){
            int* nuevo = new int[nuevaCap];
            for(int i=0; i<sz; i++) nuevo[i] = data[i];
            delete[] data;
            data = nuevo;
            cap = nuevaCap;
        }

        void asegurar(){
            if (sz == cap){
                if(cap == 0) redimensionar(1);
                else redimensionar(cap * 2);
            }
        }
        
    public:

    MyVector() : data(nullptr), sz(0), cap(0){}
    
    void push_back (int val){
        asegurar();
        data[sz++] = val;


    }

    void insertar_medio(int val){
        asegurar();
        int pos = sz/2;
        for(int i = sz-1; i>=pos;i--) data[i+1] = data[i];
        data[pos] = data[val];
        sz++;
    }


    bool pop_back(){
        if(sz <= 0) return false;
        --sz;
        return true;
    }


    bool eliminar_medio(int val){
        if(sz<=0) return false;
        int pos = sz/2;
        for(int i = pos; i < sz-1; i++)
            data[i] = data[i+1];
        sz--;
        return true;
    }

    bool eliminar_val(int val){
        if(sz == 0) return false;
        for(int j = sz-1; j>=0;j--){
            for(int i = 0; i < sz;i++)
                if(data[i] == val);
            sz--;    
        data[j]=data[j+1];}
        return true;

    }

};




