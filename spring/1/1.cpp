//
// Created by sonichka on 08.04.2022.
//
#include "iostream"

using namespace std;

struct User {
    int id;
    int visits;
};

struct Comparator {
    bool operator() (const int& l, const int& r){
        return l < r;
    }
};

template<class User>
struct userComparator{
    bool operator() (const User& l, const User& r){
        return l.vists < r.visits;
    }
};

template<class T, class Comparator=userComparator<User>>
class Heap {
public:
    explicit Heap(): arr(nullptr), size(0), bufferSize(0){}
    ~Heap(){
        delete[] arr;
    };

//    Heap(const Heap&) = delete;
//    Heap(Heap&&) = delete;
//
//    Heap& operator= (const Heap&) = delete;
//    Heap& operator= (Heap&&) = delete;

    const T& top() const{
        return arr[0];
    }

    void push(T elem){
        if(size + 1 >= bufferSize){
            if (bufferSize == 0){
                bufferSize = 1;
                arr = new T[bufferSize];
            } else {
                int newBufferSize = bufferSize * 2;
                T* temp = new T[newBufferSize];
                for (size_t i = 0; i < size; ++i) {
                    temp[i] = arr[i];
                }
                delete[] arr;
                arr = temp;
                bufferSize = newBufferSize;
            }
        }
        arr[size++] = elem;
        sift_up(size - 1);
    }

    T pop(){
        if(isEmpty()){
            return -1;
        }

        T temp = arr[0];
        arr[0] = arr[size-1];
        size--;
        sift_down(0);
        cout << temp << ' ';
        return temp;
    };

    bool isEmpty() const{
        return size == 0;
    };

private:
    Comparator comp;

    T* arr;
    size_t size;
    size_t bufferSize;

    void sift_down(size_t index){
        size_t left = index * 2 + 1;
        size_t right = index * 2 + 2;

        size_t largest = index;
        if (left < size && comp(arr[index], arr[left]))
            largest = left;
        if (right < size && comp(arr[largest], arr[right]))
            largest = right;

        if (largest != index){
            std::swap(arr[index], arr[largest]);
            sift_down(largest);
        }
    };

    void sift_up(size_t index){
        while(index > 0) {
            size_t head = (index - 1) / 2;
            if (arr[index] <= arr[head])
                return;
            std::swap(arr[head], arr[index]);
            index = head;
        }
    }

    void heapify(){
        for (size_t i = size / 2 - 1; i < 0; --i) {
            sift_down(i);
        }
    }

    void mostVisit(int k) {
        
    }
};
