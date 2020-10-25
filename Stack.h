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
            return nullptr; */
        T ob = OB[length - 1];
        return ob;
    }
    int size = 0;
    int length = 0;
    stack() {}
protected:
    T *OB;
private:
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
};

class rod : public stack<Disk> {
public:
    int order;
    Disk get(int i) {
        return OB[i];
    }
    rod() {};
    rod(int a) {
        order = a;
        OB = new Disk[5];
        size = 5;
    }
    ~rod() {
        delete OB;
    }
private:
};

class cmd : public stack<char *> {
public:
    cmd() {
        OB = new char*;
    }
    ~cmd() {
        for(int i = 0; i < length; i++) {
            delete OB[i];
        }
        delete OB;
    }
private:
};