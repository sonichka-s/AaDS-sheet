//
// Created by sonichka on 18.04.22.
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
    }

    T pop_front() {
        if (isEmpty()){
            return -1;
        }

        int temp_head = buffer[head];

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
//
//int main(){
//    Deque<int> q = Deque<int> ();
//    int a = 0, b = 0, commands = 0;
//    bool complete = true;
//
//    std::cin >> commands;
//
//    for (int i = 0; i < commands; ++i) {
//        std::cin >> a >> b;
//        switch (a) {
//            case 1:
//                q.push_front(b);
//                break;
//            case 2:
//                if(q.pop_front() != b)
//                    complete = false;
//                break;
//            case 3:
//                q.push_back(b);
//                break;
//            case 4:
//                if(q.pop_back() != b)
//                    complete = false;
//                break;
//            default:
//                break;
//        }
//    }
//
//    if (complete)
//        std::cout << "YES";
//    else
//        std::cout << "NO";
//
//    return 0;
//}

