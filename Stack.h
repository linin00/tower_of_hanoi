#include "disk.h"
template <class T>
class stack {
public:
    void push(T ob) {
        if (length == size)
            doubleSize();
        length++;
        OB[length - 1] = ob;
    }
    T pop() {/* 
        if (length == 0) 
         return nullptr; */
        T ob = OB[length - 1];
        /* delete OB[length - 1]; */
        length--;
        return ob;
    }
    T getTop() {/*  
        if (length == 0) 
            exit(0);  */
        T ob = OB[length - 1];
        /* cout << 456; */
        return ob;
    }
    int size = 0;
    int length = 0;
    stack() {}
protected:
    T *OB;
    void doubleSize() {
        if (size == 0)
        size++;
        T *ob;
        ob = new T[2*size];
        for (int i = 0; i < size; i++) {
            ob[i] = OB[i];
        }
        delete OB;
        OB = new T[2*size];
        for (int i = 0; i <size; i++) {
            OB[i] = ob[i];
        }
        delete ob;
    }
private:
};

class rod : public stack<Disk> {
public:
    int order;
    Disk &get(int i) {
        return OB[i];
    }
    rod() {
        /* OB = new Disk[5];
        size = 5; */
    };
    rod(int a) {
        order = a;
        OB = new Disk[5];
        size = 5;
    }
    ~rod() {
        delete OB;
    }
    int getTopSize() {
        /* cout << 123; */
        if (length == 0)
            return INT_MAX;
        return getTop().size;
    }
private:
};

class cmd : public stack<int *> {
public:
    cmd() {
        OB = new int*[size];
        /* for (int i = 0; i < size; i++) {
            OB[i] = new int[2];
        } */
    }
    ~cmd() {
        delete OB;
    }
    void push(int * ob) {
        if (length == size)
            doubleSize();
        length++;/* 
        OB[length - 1] = new int[2]; */
        OB[length - 1] = ob;
    }
    int * pop() {
        /* int * ob = new int[2]; */
        int * ob;
        ob = OB[length - 1];
        /* delete []OB[length - 1]; */
        length--;
        return ob;
    }
private:
    /* void doubleSize() {
        if (size == 0)
        size++;
        int **ob;
        ob = new T[2*size];
        for (int i = 0; i < size; i++) {
            ob[i] = OB[i];
        }
        delete OB;
        OB = new T[2*size];
        for (int i = 0; i <size; i++) {
            OB[i] = ob[i];
        }
        delete ob; 
    } */
};