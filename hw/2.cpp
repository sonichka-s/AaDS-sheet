//
// Created by sonichka on 14.11.2021.
//
#include "iostream"

using namespace std;

int expSearch(int* arr, int size, int elem) {
    int i = 1;

    if (arr[0] == elem)
        return 0;

    while ((arr[i] <= elem) && i < size) {
        i *= 2;
    }

    return i;
}

//int BinarySearch(int* arr, int count, int elem){
//    int first = 0;
//    int last = count;
//    while(first < last) {
//        int mid = (first + last)/2;
//        if(arr[mid] < elem){
//            first = mid + 1;
//        }
//
//        else {
//            last = mid;
//        }
//    }
//
//    return first;
//}

//void next_element(int* arr1, int* arr2, int size1, int size2){
//    for (int i = 0; i < size2; ++i) {
//        int edge = expSearch(arr1, size1, arr2[i]);
//        cout << BinarySearch(arr1, edge, arr2[i]) << ' ';
//    }
//}

//int main(){
//
//    int size1, size2;
//    cin >> size1 >> size2;
//
//    int* arr1 = new int[size1];
//    int* arr2 = new int[size2];
//
//    for (int i = 0; i < size1; ++i) {
//        cin >> arr1[i];
//    }
//
//    for (int i = 0; i < size2; ++i) {
//        cin >> arr2[i];
//    }
//
//    next_element(arr1, arr2, size1, size2);
//
//    delete[] arr1;
//    delete[] arr2;
//    arr1 = nullptr;
//    arr2 = nullptr;
//    return 0;
//}
