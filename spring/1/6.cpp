//
// Created by sonichka on 22.04.22.
//
#include "iostream"
#include "cstdlib"

using  namespace std;

template<typename T>
struct Comparator{
    bool operator() (const T& l, const T& r){
        return l < r;
    }
};

template<typename T>
size_t Partition(T* arr, size_t l, size_t r, Comparator<T> comp) {
    size_t pivot_idx = l + (abs)(rand()) % (r - l);
    T pivot = arr[pivot_idx];

    size_t i = l;
    size_t j = l;
    std::swap(arr[pivot_idx], arr[r - 1]);

    for ( ; comp(j, r); j++) {
        if (comp(arr[j], pivot)) {
            std::swap(arr[j], arr[i++]);
        }
    }

    std::swap(arr[r - 1], arr[i]);
    return i;
}



template<class T>
T kth_stat(T* arr, size_t l, size_t r, size_t k, Comparator<T> comp) {

    size_t part = 0;

    while (l < r) {
        part = Partition(arr, l, r, comp);
        if (part == k) {
            return arr[part];
        }

        else if (part < k) {
            l = part + 1;
        }

        else {
            r = part;
        }
    }

    return arr[part];
}

//int main(){
//
//    int size = 0;
//    Comparator<int> comp;
//    cin >> size;
//    int* arr = new int[size];
//
//    for (int i = 0; i < size; ++i) {
//        cin >> arr[i];
//    }
//
//
//    cout << kth_stat(arr, 0, size, size * 0.1, comp) << endl;
//    cout << kth_stat(arr, 0, size, size * 0.5, comp) << endl;
//    cout << kth_stat(arr, 0, size, size * 0.9, comp) << endl;
//
//    delete[] arr;
//    return 0;
//}