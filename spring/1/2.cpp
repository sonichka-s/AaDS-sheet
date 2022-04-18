//
// Created by sonichka on 17.04.22.
//
#include "iostream"

int expSearch(int* arr, int size) {
    int i = 1;

    if (arr[0] > arr[1])
        return 0;

    while (arr[i * 2] > arr[i * 2 - 1] && i < size) {
        i *= 2;
    }

    return i;
}

int BinarySearch(int* arr, int count, int size){
    int first = count;
    int last = size - 1;
    while(first < last) {
        int mid = (first + last)/2;
        if(arr[mid] < arr[mid + 1]){
            first = mid + 1;
        }

        else {
            last = mid;
        }
    }

    return first;
}

int borderElem(int* arr, int size) {
    int edge = expSearch(arr, size);
    return BinarySearch(arr, edge, size);
}

//int main(){
//
//    int size;
//    std::cin >> size;
//
//    int* arr = new int[size];
//
//    for (int i = 0; i < size; ++i) {
//        std::cin >> arr[i];
//    }
//
//    std::cout << borderElem(arr, size);
//
//    delete[] arr;
//    return 0;
//}