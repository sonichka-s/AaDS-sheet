//
// Created by sonichka on 24.11.2021.
//

#include "iostream"

using  namespace std;

template<typename T>
size_t FindPivot(T* arr, size_t l, size_t r){
    T first = arr[l];
    T last = arr[r - 1];
    T mid = arr[((r + l) / 2)];

    if (((first > mid) && (first < last)) || ((first < mid) && (first > last)))
        return l;
    else if (((last > mid) && (last < first)) || ((last < mid) && (last > first)))
        return r - 1;
    else
        return (r + l) / 2;
}

template<typename T>
struct Comparator{
    bool operator() (const T& l, const T& r){
        return l > r;
    }
};

template<typename T>
size_t Partition(T* arr, size_t l, size_t r, Comparator<T> comp){
    size_t pivot_idx = FindPivot(arr,l, r);
    T pivot = arr[pivot_idx];

    size_t i = r - 1;
    size_t j = r - 1;
    std::swap(arr[pivot_idx], arr[l]);

    for ( ; j > l; --j) {
        if (comp(arr[j], pivot)) {
            swap(arr[i], arr[j]);
            i--;
        }
    }

    std::swap(arr[l], arr[i]);
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