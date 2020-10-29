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
    T pop() {
        T ob = OB[length - 1];
        length--;
        return ob;
    }
    T getTop() {
        T ob = OB[length - 1];
        return ob;
    }
    int size = 0;
    int length = 0;
    stack() {}
protected:
    T *OB;
    void doubleSize() {
        if (size == 0) size++;
        T *ob;
        ob = new T[2*size];
        for (int i = 0; i < size; i++) {
            ob[i] = OB[i];
        }
        delete []OB;
        OB = new T[2*size];
        for (int i = 0; i <size; i++) {
            OB[i] = ob[i];
        }
        size *= 2;
        delete []ob;
    }
private:
};

class rod : public stack<Disk> {
public:
    int order;
    Disk &get(int i) {
        return OB[i];
    }
    rod() {}
    rod(int a) {
        order = a;
        OB = new Disk[5];
        size = 5;
    }
    ~rod() {
        delete OB;
    }
    int getTopSize() {
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
    }
    void resetstack(){
        delete []OB;
        OB = new int*[size];  
    }
    void push(int * ob) {
        if (length == size)
            doubleSize();
        length++;
        OB[length - 1] = ob;
    }
    int * pop() {
        int * ob;
        ob = OB[length - 1];
        length--;
        return ob;
    }
private:
};