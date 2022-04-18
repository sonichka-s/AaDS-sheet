#include "iostream"

using namespace std;

template<typename T>
class Stack{
public:
    explicit Stack(): buffer(nullptr), size(0), bufferSize(0){}

    ~Stack(){
        delete[] buffer;
    }

    void Push(T elem){
        if(size + 1 >= bufferSize){
            if(bufferSize == 0) {
                bufferSize = 1;
                buffer = new T[bufferSize];
            } else {
                int newBufferSize = bufferSize * 2;
                T* temp = new T[newBufferSize];
                for (int i = 0; i < bufferSize; ++i) {
                    temp[i] = buffer[i];
                }
                delete[] buffer;
                buffer = temp;
                bufferSize = newBufferSize;
            }
        }
        buffer[size++] = elem;
    }

    T Pop(){
        if(isEmpty()){
            return -1;
        }

        return buffer[--size];
    }

    bool isEmpty(){
        return size == 0;
    }

private:
    T *buffer;
    int size;
    int bufferSize;
};

//int main() {
//    Stack<int> stack = Stack<int>();
//
//    for (int i = 0; i < 5; ++i) {
//        stack.Push(i);
//    }
//
//    for (int i = 0; i < 6; ++i) {
//        cout << stack.Pop() << endl;
//    }
//
//}