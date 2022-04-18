////
//// Created by sonichka on 12.11.2021.
////
//
//#include "iostream"
//
//using namespace std;
//
//int getIndex(int* arr, int n, int k) {
//    int left = 0;
//    int right = n - 1;
//
//    while(left < right) {
//        int mid = (left + right )/ 2;
//
//         if(arr[mid] <= arr[mid + 1] && arr[mid] <= arr[mid - 1]){
//             return mid;
//         }
//
//         if(arr[mid] < k) {
//             left = mid + 1;
//         }
//         else {
//             right = mid - 1;
//         }
//
//    }
//    return
//}
//
//int main() {
//    int n;
//    int k = 0;
//
//    cin >> n;
//    int* arr = new int[n];
//    for(int i = 0; i < n; ++i) {
//        cin >> arr[i];
//    }
//
//    cin >> k;
//    cout << getIndex(arr, n, k);
//}
//
