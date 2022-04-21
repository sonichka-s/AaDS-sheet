//
// Created by sonichka on 21.04.22.
//
#include "iostream"

template<typename T>
class Deque{
public:
    explicit Deque(): buffer(nullptr), size(0), bufferSize(0), head(0), tail(0) {}

    ~Deque() {
        delete[] buffer;
    }

    void push_back(T elem) {
        if (size == bufferSize) {
            grow();
        }

        if (tail == bufferSize + 1) {
            buffer[0] = elem;
            tail = 0;
        }

        if (head > tail)
            buffer[tail] = elem;

        else
            buffer[head + size] = elem;

        size++;
        tail++;

//        std::cout << '\n';
//        printDeque();
    }

    void push_front(T elem) {
        if (size == bufferSize) {
            grow();
        }

        if (head == 0) {
            if(isEmpty()) {
                buffer[head] = elem;
                tail++;
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

//        std::cout << '\n';
//        printDeque();
    }

    T pop_front() {
        if (isEmpty()){
            return -1;
        }

        int temp_head = buffer[head];

//        std::cout << '\n';
//        std::cout << temp_head << '\n';

        size--;
        if (head == bufferSize)
            head = 0;
        else
            head++;
        return temp_head;
    }

    T pop_back() {
        if (isEmpty()){
            return -1;
        }

        T temp = buffer[tail - 1];
        size--;
        tail--;
        if (tail == 0 && size != 0)
            tail = bufferSize + 1;

//        std::cout << '\n';
//        std::cout << temp << '\n';

        return temp;
    }

    bool isEmpty() {
        return size == 0;
    }

    void printDeque() {
        for (int i = 0; i <= bufferSize; ++i) {
            std::cout << i << ' ' << buffer[i] << '\n';
        }
    }

private:
    T* buffer;
    int bufferSize;
    int size;
    int head;
    int tail;

    void grow() {
        if (bufferSize == 0) {
            bufferSize = 1;
            buffer = new T[bufferSize];
        }
        else {
            int newBufferSize = bufferSize * 2;
            T* temp = new T[newBufferSize];
            if (head > tail) {
                for (int i = 0; i < (bufferSize - tail); ++i) {
                    temp[i] = buffer[head + i];
                    T t = buffer[(head + i)];
                    int u = 0;
                }

                for (int i = bufferSize - tail; i < size; ++i) {
                    temp[i] = buffer[i - (bufferSize - tail)];
                }
            }

            else if (head < tail) {
                for (int i = head; i < tail; ++i) {
                    temp[i - head] = buffer[i];
                }
            }

            else {
                for (int i = 0; i <=  size; ++i) {
                    temp[i] = buffer[i];
                }
            }
            head = 0;
            tail = size;
            delete[] buffer;
            buffer = temp;
            bufferSize = newBufferSize;
        }
    }
};