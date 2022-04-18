//
// Created by sonichka on 18.04.22.
//
#include "iostream"

template<typename T>
class Queue{
public:
    explicit Queue(): buffer(nullptr), size(0), bufferSize(0), head(0){}

    ~Queue() {
        delete[] buffer;
    }

    void push_back(T elem) {
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
                delete[] buffer;
                buffer = temp;
                bufferSize = newBufferSize;
            }
        }
        buffer[(head + size) % bufferSize] = elem;
        size++;
    }

    void push_front(T elem) {
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

        if(head == 0) {
            if(isEmpty()) {
                buffer[head] = elem;
            }

            else {
                buffer[bufferSize] = elem;
                head = bufferSize;
            }
        }
        else {
            head--;
            buffer[head] = elem;
        }
        size++;
    }

    T pop_front() {
        if(isEmpty()){
            return -1;
        }

        int temp_head = buffer[head];
        size--;
        head = (head + 1) % bufferSize;
        return temp_head;
    }

    T pop_back() {
        if(isEmpty()){
            return -1;
        }

        return buffer[(head + size) % bufferSize];
        size--;
    }

    bool isEmpty() {
        return size == 0;
    }


private:
    T* buffer;
    int bufferSize;
    int size;
    int head;
};

int main(){
    Queue<int> q = Queue<int> ();
    int a = 0, b = 0, commands = 0;
    bool complete = true;

    std::cin >> commands;

    for (int i = 0; i < commands; ++i) {
        std::cin >> a >> b;
        switch (a) {
            case 1:
                q.push_front(b);
                break;
            case 2:
                if(q.pop_front() != b)
                    complete = false;
                break;
            case 3:
                q.push_back(b);
                break;
            case 4:
                if(q.pop_back() != b)
                    complete = false;
                break;
        }
    }

    if (complete)
        std::cout << "YES";
    else
        std::cout << "NO";

    return 0;
}