//
// Created by sonichka on 16.11.2021.
//
#include "iostream"

using namespace std;

template<typename T>
class Queue{
public:
    explicit Queue(): buffer(nullptr), size(0), bufferSize(0), head(0){}

    ~Queue(){
        delete[] buffer;
    }

    void push_back(T elem){
        if(size + 1 >= bufferSize) {
            if (bufferSize == 0) {
                bufferSize = 1;
                buffer = new T[bufferSize];
            } else {
                int newBufferSize = bufferSize * 2;
                T* temp = new T[newBufferSize];
                for (int i = 0; i < bufferSize; ++i) {
                    temp[i] = buffer[(head + i) % bufferSize];
                }
                head = 0;
                delete[] buffer;
                buffer = temp;
                bufferSize = newBufferSize;
            }
        }
        buffer[(head + size) % bufferSize] = elem;
        size++;
    }

    T pop_front(){
        if(isEmpty()){
            return -1;
        }
        T temp = buffer[head];
        head = (head + 1) % bufferSize;
        size--;
        return temp;
    }

    bool isEmpty(){
        return size == 0;
    }


private:
    T* buffer;
    int bufferSize;
    int size;
    int head;
};

//int main(){
//    Queue<int> q = Queue<int>();
//
//    for (int i = 0; i < 5; ++i) {
//        q.push_back(i);
//    }
//
//    for (int i = 0; i < 6; ++i) {
//        cout << q.pop_front() << endl;
//    }
//}