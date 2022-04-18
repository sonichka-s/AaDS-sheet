//
// Created by sonichka on 20.12.2021.
//
#include "iostream"

using namespace std;

template<typename T>
class Queue{
public:
    explicit Queue(): buffer(nullptr), size(0), bufferSize(0), head(0){}

    ~Queue(){
        delete[] buffer;
    }

    void push_back(T elem){
        if(size + 1 >= bufferSize) {
            if (bufferSize == 0) {
                bufferSize = 1;
                buffer = new T[bufferSize];
            } else {
                int newBufferSize = bufferSize * 2;
                T* temp = new T[newBufferSize];
                for (int i = 0; i < bufferSize; ++i) {
                    temp[i] = buffer[(head + i) % bufferSize];
                }
                head = 0;
                delete[] buffer;
                buffer = temp;
                bufferSize = newBufferSize;
            }
        }
        buffer[(head + size) % bufferSize] = elem;
        size++;
    }

    T pop_front(){
        T temp_head = buffer[head];
        size--;
        head = (head + 1) % bufferSize;
        return temp_head;
    }



    bool isEmpty(){
        return size == 0;
    }


private:
    T* buffer;
    int bufferSize;
    int size;
    int head;
};


struct DefaultComparator {
public:
    bool operator()(const int &l, const int &r) {
        return l <= r;
    }
};


template<class Comparator=DefaultComparator>
class BinaryTree {
    struct BinaryNode {
        int Data;
        BinaryNode* l;
        BinaryNode* r;

        BinaryNode(int data) : Data(data), l(nullptr), r(nullptr) {}
    };

public:
    ~BinaryTree() {
        if (root == nullptr)
            return;

        Queue<BinaryNode*> q;

        q.push_back(root);
        while (!q.isEmpty()) {

            BinaryNode *temp = q.pop_front();

            if (temp->l != nullptr)
                q.push_back(temp->l);

            if (temp->r != nullptr)
                q.push_back(temp->r);

            delete temp;
        }
    }

    void add(int data) {

        if(root == nullptr) {
            root = new BinaryNode(data);
        }
        else {
            BinaryNode* cur = root;

            while(true) {

                if(comp(cur->Data, data)) {

                    if(cur->r == nullptr) {
                        cur->r = new BinaryNode(data);
                        break;
                    }
                    cur = cur->r;
                }
                else if(!comp(cur->Data, data)) {

                    if(cur->l == nullptr) {
                        cur->l = new BinaryNode(data);
                        break;
                    }
                    cur = cur->l;
                }
            }
        }
    }

    bool isEqual() {
        Queue<BinaryNode*> q;

        q.push_back(root);
        while (!q.isEmpty()) {

            BinaryNode *cur = q.pop_front();

            if (cur->l != root)
                return false;

            if (cur->r != root)
                return false;

            delete cur;
        }

        return true;
    }

    void levelOrder() {

        if (root == nullptr)
            return;

        Queue<BinaryNode*> q;

        q.push_back(root);

        while (!q.isEmpty()) {
            BinaryNode* temp = q.pop_front();
            cout << temp->Data << ' ';

            if (temp->l)
                q.push_back(temp->l);
            if (temp->r)
                q.push_back(temp->r);
        }
    }

private:
    BinaryNode* root = nullptr;
    Comparator comp;

};

//int main() {
//
//    BinaryTree<DefaultComparator> Btree;
//    int n;
//    int data;
//
//    cin >> n;
//
//    for(int i = 0; i < n; ++i) {
//        cin >> data;
//        Btree.add(data);
//    }
//
//    Btree.levelOrder();
//
//    return 0;
//}

