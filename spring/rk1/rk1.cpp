//
// Created by sonichka on 08.04.2022.
//
//
//template<typename T>
//class Stack{
//public:
//    explicit Stack(): buffer(nullptr), size(0), bufferSize(0){}
//
//    ~Stack(){
//        delete[] buffer;
//    }
//
//    void Push(T elem){
//        if(size + 1 >= bufferSize){
//            if(bufferSize == 0) {
//                bufferSize = 1;
//                buffer = new T[bufferSize];
//            } else {
//                int newBufferSize = bufferSize * 2;
//                T* temp = new T[newBufferSize];
//                for (int i = 0; i < bufferSize; ++i) {
//                    temp[i] = buffer[i];
//                }
//                delete[] buffer;
//                buffer = temp;
//                bufferSize = newBufferSize;
//            }
//        }
//        buffer[size++] = elem;
//    }
//
//    T getTop() {
//        if (!isEmpty()) {
//            return buffer[size - 1];
//        }
//    }
//
//    T Pop(){
//        if(isEmpty()){
//            return -1;
//        }
//
//        return buffer[--size];
//    }
//
//    bool isEmpty(){
//        return size == 0;
//    }
//
//private:
//    T *buffer;
//    int size;
//    int bufferSize;
//};
//
//bool isAnagram(std::string s1, std::string s2) {
//
//    Stack<char> stack = Stack<char>();
//    int index= 0;
//
//    for (int i = 0; i < s2.length(); ++i) {
//        stack.Push(s1[i]);
//
//
//        while(stack.getTop() == s2[index] && !stack.isEmpty()) {
//            stack.Pop();
//            index++;
//        }
//    }
//
//    if(stack.isEmpty())
//        return true;
//
//    return false;
//}


//#include "iostream"
//
//using  namespace std;
//
//template<typename T>
//struct Comparator{
//    bool operator() (const T& l, const T& r){
//        return l > r;
//    }
//};
//
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

//template<typename T>
//size_t FindPivot(T* arr, size_t l, size_t r){
//    T first = arr[l];
//    T last = arr[r - 1];
//    T mid = arr[((r + l) / 2)];
//
//    if (((first > mid) && (first < last)) || ((first < mid) && (first > last)))
//        return l;
//    else if (((last > mid) && (last < first)) || ((last < mid) && (last > first)))
//        return r - 1;
//    else
//        return (r + l) / 2;
//}

//template<typename T>
//size_t Partition(T* arr, size_t l, size_t r, size_t k, Comparator<T> comp){
//    size_t pivot_idx = BinarySearch(arr,r, k);
//    T pivot = arr[pivot_idx];
//
//    size_t i = r - 1;
//    size_t j = r - 1;
//    std::swap(arr[pivot_idx], arr[l]);
//
//    for ( ; j > l; --j) {
//        if (comp(arr[j], pivot)) {
//            swap(arr[i], arr[j]);
//            i--;
//        }
//    }
//
//    std::swap(arr[l], arr[i]);
//    return i;
//}



//template<class T>
//T kth_stat(T* arr, size_t l, size_t r, size_t k, Comparator<T> comp) {
//
//    size_t part = 0;
//
//    while (l < r) {
//        part = BinarySearch(arr, r, k);
//        if (part == k) {
//            return arr[part];
//        }
//
//        else if (part < k) {
//            l = part + 1;
//        }
//
//        else {
//            r = part;
//        }
//    }
//
//    return arr[part];
//}

//int main(){
//
//    int size = 0;
//    int k = 0;
//    Comparator<int> comp;
//    cin >> size;
//    int* arr = new int[size];
//
//    for (int i = 0; i < size; ++i) {
//        cin >> arr[i];
//    }
//
//    cin >> k;
//
//    cout << kth_stat(arr, 0, size, size, k, comp) << endl;
//
//    delete[] arr;
//    return 0;
//}