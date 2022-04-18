//
// Created by sonichka on 12.11.2021.
//

#include "iostream"
#include "string"

using namespace std;

template<typename T>
class Stack{
public:
    explicit Stack(): buffer(nullptr), size(0), bufferSize(0){}

    ~Stack(){
        delete[] buffer;
    }

    void Push(T elem){
        if(size + 1 >= bufferSize){
            if(bufferSize == 0) {
                bufferSize = 1;
                buffer = new T[bufferSize];
            } else {
                int newBufferSize = bufferSize * 2;
                T* temp = new T[newBufferSize];
                for (int i = 0; i < bufferSize; ++i) {
                    temp[i] = buffer[i];
                }
                delete[] buffer;
                buffer = temp;
                bufferSize = newBufferSize;
            }
        }
        buffer[size++] = elem;
    }

    T Pop(){
        if(isEmpty()){
            return -1;
        }

        return buffer[--size];
    }

    bool isEmpty(){
        return size == 0;
    }

private:
    T *buffer;
    int size;
    int bufferSize;
};

//bool bracket_check(string str){
//    Stack<char> s = Stack<char>();
//
//    for (int i = 0; i < str.size(); ++i) {
//        if(str[i] == '('){
//            s.Push(str[i]);
//        }
//
//        else if(str[i] == ')'){
//            if(!s.isEmpty()){
//                s.Pop();
//            } else {
//                return false;
//            }
//        }
//    }
//
//    if(!s.isEmpty()){
//        return false;
//    }
//
//    return true;
//}

bool stack_anagram(string first, string second){
    Stack<char> s = Stack<char>();
    char chars[first.size()];

    for (int i = 0; i < first.size(); ++i) {
        s.Push(first[i]);
    }

    for (int i = 0; i < first.size(); ++i) {
        chars[i] = s.Pop();
    }

    for (int i = 0; i < first.size(); ++i) {
        char temp = chars[first.size() - 1];
        for (int j = first.size() - 1; j >= 0; --j) {
            chars[j] = chars[j-1];
        }

        chars[0] = temp;

        string compare_str;
        for (int j = 0; j < first.size(); ++j) {
            compare_str += chars[j];
        }

        if(compare_str == second){
            return true;
        }
    }

    return false;
}

//int main() {
//
//    string s_first, s_second;
//    cin >> s_first >> s_second;
//
//    if(stack_anagram(s_first, s_second)){
//        cout << "YES";
//    } else {
//        cout << "NO";
//    }
//
//}
