//
// Created by sonichka on 21.04.22.
//
#include "iostream"

struct Customer {
    int in;
    int out;
};

struct CustomersComparator {
    bool operator() (const Customer& l, const Customer& r){
        if (l.out < r.out) {
            return true;
        }
        else if (l.out == r.out) {
            if (l.in <= r.in)
                return true;
        }
        return false;
    }
};

template<class T, class Comparator=CustomersComparator>
void Merge(T* arr, int left, int right, int mid) {
    Comparator comp;

    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    T* leftArr = new T[leftSize];
    T* rightArr = new T[rightSize];

    for (int i = 0; i < leftSize; ++i) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < rightSize; ++i) {
        rightArr[i] = arr[mid + i + 1];
    }

    int leftIdx = 0;
    int rightIdx = 0;
    int mergedArrIdx = left;

    while (leftIdx < leftSize && rightIdx < rightSize) {
        if (comp(leftArr[leftIdx], rightArr[rightIdx])) {
            arr[mergedArrIdx] = leftArr[leftIdx];
            leftIdx++;
        }

        else {
            arr[mergedArrIdx] = rightArr[rightIdx];
            rightIdx++;
        }
        mergedArrIdx++;
    }

    while (leftIdx < leftSize) {
        arr[mergedArrIdx] = leftArr[leftIdx];
        leftIdx++;
        mergedArrIdx++;
    }

    while (rightIdx < rightSize) {
        arr[mergedArrIdx] = rightArr[rightIdx];
        rightIdx++;
        mergedArrIdx++;
    }
}

template<class T, class Comparator=CustomersComparator>
void MergeSort(T* arr, int left, int right) {
    if (right > left) {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        Merge(arr, left, right, mid);
    }
    else
        return;
}

void printArr(Customer* arr, int n){
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i].in << ' ' << arr[i].out << '\n';
    }
}

int minAdvertisingNumber(Customer* arr, int n) {
    int shown = 0;
    int firstShow = -1;
    int secondShow = -1;
    for (int i = 0; i < n; ++i) {
        Customer c = arr[i];

        if (c.in > secondShow) {
            shown += 2;
            firstShow = c.out - 1;
            secondShow = c.out;
        }

        else if (c.in == secondShow) {
            shown++;
            firstShow = secondShow;
            secondShow = c.out;
        }

        else if (c.in > firstShow && c.out >= secondShow) {
            shown++;
            firstShow = secondShow;
            secondShow = c.out;
        }

        else if (c.in > firstShow && c.out < secondShow) {
            shown++;
            firstShow = c.out;
        }
    }

    return shown;
}

//int main(){
//    int n;
//    std::cin >> n;
//
//    Customer* arr = new Customer[n];
//
//    for (int i = 0; i < n; ++i) {
//        std::cin >> arr[i].in >> arr[i].out;
//    }
//
//    MergeSort(arr, 0, n - 1);
////    printArr(arr, n);
//    std::cout << minAdvertisingNumber(arr, n);
//};