//
// Created by sonichka on 08.04.2022.
//
#include "iostream"

using namespace std;

int changeBitValue(int n, int k) {
    return ((n >> k) & 1) == 1 ? (n & ~(1 << k)) : (n ^ (1 << k));
}

//int main() {
//
//    int n, k, res;
//    cin >> n >> k;
//    res = changeBitValue(n, k);
//    cout << res;
//
//    return 0;
//}