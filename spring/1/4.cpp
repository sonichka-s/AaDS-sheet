//
// Created by sonichka on 21.04.22.
//
#include "iostream"

using namespace std;

struct User {
    int id;
    int visits;
};

struct VisitsComparator {
    bool operator() (const User& l, const User& r){
        return l.visits < r.visits;
    }
};

template<class T, class Comparator=VisitsComparator>
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
        if(!isEmpty()) {
            T temp = arr[0];
            arr[0] = arr[size - 1];
            size--;
            if (!isEmpty())
                sift_down(0);
            return temp;
        }
    }

    bool isEmpty() const{
        return size == 0;
    }

    void printHeap() {
        for (int i = 0; i < size; ++i) {
            std::cout << i << ". " << arr[i].visits << '\n';
        }
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

void MostVisits(int k, Heap<User> heap){
    User* arr = new User[k];
    for (int i = 0; i < k; ++i) {
        arr[i] = heap.pop();
    }
    for (int i = k - 1; i >=0; --i) {
        std::cout << arr[i].id <<' ';
    }
}

//int main(){
//    int n, k;
//    Heap<User> h = Heap<User>();
//
//    cin >> n >> k;
//
//    for (int i = 0; i < n; ++i) {
//        User user;
//        cin >> user.id >> user.visits;
//        h.push(user);
//    }
//
////    h.printHeap();
//    MostVisits(k, h);
//};

