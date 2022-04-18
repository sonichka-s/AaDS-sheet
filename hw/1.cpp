//
// Created by sonichka on 12.11.2021.
//
#include "iostream"

using namespace std;

int bit_value(int n, int k){


    if((n & (1 << k)) == 0){
        return 0;
    }

    return 1;
}

//int main(){
//
//    int n, k, res;
//    cin >> n >> k;
//    cout << bit_value(n, k);
//
//    return 0;
//}