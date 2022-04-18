//
// Created by sonichka on 21.11.2021.
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

        int temp_head = buffer[head];
        size--;
        head = (head + 1) % bufferSize;
        return temp_head;
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
//    Queue<int> q = Queue<int> ();
//    int a = 0, b = 0, commands = 0;
//    bool complete = true;
//
//    cin >> commands;
//
//    for (int i = 0; i < commands; ++i) {
//        cin >> a >> b;
//        if (a == 2){
//            if(q.pop_front() != b) {
//               complete = false;
//            }
//        } else {
//            q.push_back(b);
//        }
//    }
//
//    if (complete)
//        cout << "YES";
//    else
//        cout << "NO";
//
//    return 0;
//}
