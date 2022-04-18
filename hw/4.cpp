//
// Created by sonichka on 22.11.2021.
//
#include "iostream"

using namespace std;

struct Process{
    int P;
    int T;
    int t = 0;
};

struct ProcessValue{
    bool operator() (const Process& l, const Process& r){
        return l.P*(l.t + 1) > r.P*(r.t + 1);
    }
};



template<class T, class Comparator=ProcessValue>
class Heap {
public:
    explicit Heap(): arr(nullptr), size(0), bufferSize(0){}
//    ~Heap(){
//        delete[] arr;
//    }

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

        T temp = arr[0];
        arr[0] = arr[size-1];
        size--;
        sift_down(0);
        return temp;
    }

    bool isEmpty() const{
        return size == 0;
    }

private:
    Comparator comp;

    T* arr;
    size_t size;
    size_t bufferSize;

    void sift_down(size_t index){
        size_t left = index * 2 + 1;
        size_t right = index * 2 + 2;

        size_t lower = index;
        if (left < size && comp(arr[index], arr[left]))
            lower = left;
        if (right < size && comp(arr[lower], arr[right]))
            lower = right;

        if (lower != index){
            std::swap(arr[index], arr[lower]);
            sift_down(lower);
        }
    }

    void sift_up(size_t index){
        while(index > 0) {
            size_t head = (index - 1) / 2;
            if (comp(arr[index], arr[head]))
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
};

size_t ProcessPlanner(Heap<Process> heap){
    size_t process_counter = 0;
    while(!(heap.isEmpty())) {
        process_counter += 1;
        Process p = heap.pop();
        p.t += p.P;
        if (p.t >= p.T){
            continue;
        }
        heap.push(p);
    }
    return process_counter;
}

//int main(){
//    int process_num;
//    Heap<Process> h = Heap<Process>();
//
//    cin >> process_num;
//
//    for (int i = 0; i < process_num; ++i) {
//        Process p;
//        cin >> p.P >> p.T;
//        h.push(p);
//    }
//
//    cout << ProcessPlanner(h);
//};
