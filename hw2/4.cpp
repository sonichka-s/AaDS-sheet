#include "iostream"
#include "vector"
#include "assert.h"

using namespace std;

template <class T>
struct defaultComparator {
    int operator() (const T& l, const T& r) {
        if (l < r)
            return -1;
        else if (l > r)
            return 1;
        return 0;
    }
};

template <class Key, class Comparator = defaultComparator<Key>>
class AVLTree {
    struct Node {
        Node* left;
        Node* right;

        Key key;
        uint8_t height;
        size_t count;

        Node(const Key& key) : left(nullptr), right(nullptr), key(key), height(1), count(1) {}

        ~Node() {
            delete left;
            delete right;
        }
    };
public:
    AVLTree(Comparator comp = Comparator()) : root(nullptr), comp(comp) {}

    ~AVLTree() {
        delete root;
    }

    bool has(const Key& key) const {
        return hasInternal(key, root);
    }

    void insert(const Key& key) {
        root = insertInternal(key, root);
    }

    void erase(const Key& key) {
        root = eraseInternal(key, root);
    }

    int KStat(size_t pos) {
        Node* temp = root;
        size_t curPos = 0;
        if (temp->left)
            curPos = temp->left->count;

        while (curPos != pos) {
            if (pos < curPos) {
                temp = temp->left;
                if (temp && temp->right)
                    curPos -= temp->right->count + 1;
                else
                    curPos--;
            }

            else {
                temp = temp->right;
                if (temp && temp->left)
                    curPos += temp->left->count + 1;
                else
                    curPos++;
            }
        }

        return temp->key;
    }

private:
    bool hasInternal(const Key& key, Node* node) {
        if (!node)
            return false;

        int cmp_res = comp(key, node->key);
        if (cmp_res == 0)
            return true;

        if (cmp_res == -1)
            return hasInternal(key, node->left);

        else
            return hasInternal(key, node->right);
    }

    Node* insertInternal(const Key& key, Node* node) {
        if (!node)
            return new Node(key);

        int cmp_res = comp(key, node->key);
        if (cmp_res == -1)
            node->left = insertInternal(key, node->left);

        else
            node->right = insertInternal(key, node->right);

        return balance(node);
    }

    Node* eraseInternal(const Key& key, Node* node) {
        if (!node)
            return nullptr;

        int cmp_res = comp(key, node->key);
        if (cmp_res == -1)
            node->left = eraseInternal(key, node->left);

        else if (cmp_res == 1)
            node->right = eraseInternal(key, node->right);

        else {
            Node* left = node->left;
            Node* right = node->right;

            node->left = nullptr;
            node->right = nullptr;

            delete node;

            if (!right)
                return left;

            Node* minNode = findMin(right);
            minNode->right = removeMin(right);
            minNode->left = left;

            return balance(minNode);
        }

        return balance(node);
    }

    Node* findMin (Node* node) {
        if (!node->left)
            return node;

        return findMin(node->left);
    }

    Node* removeMin(Node* node) {
        if (!node->left)
            return node->right;

        node->left = removeMin(node->left);
        return balance(node);
    }

    uint8_t height(Node* node) {
        if (!node)
            return 0;

        return node->height;
    }

    uint8_t bfactor(Node* node) {
        return height(node->right) - height(node->left);
    }

    void fixHeigh(Node* node) {
        if (!node)
            return;

        node->height = std::max(height(node->left), height(node->right)) + 1;
    }

    void fixCount(Node* node) {
        if (!node)
            return;
        node->count = 1;

        if(node->left)
            node->count += node->left->count;
        if(node->right)
            node->count += node->right->count;
    }

    Node* rotateRight(Node* node) {
        Node* root = node->left;
        Node *temp = root->right;

        root->right = node;
        node->left = temp;

        node->height = max(height(node->left),
                        height(node->right)) + 1;
        root->height = max(height(root->left),
                        height(root->right)) + 1;
        fixCount(node);
        fixCount(root);

        return root;
    }

    Node* rotateLeft(Node* node) {
        Node *root = node->right;
        Node *temp = root->left;

        root->left = node;
        node->right = temp;

        node->height = max(height(node->left),
                        height(node->right)) + 1;
        root->height = max(height(root->left),
                        height(root->right)) + 1;
        fixCount(node);
        fixCount(root);

        return root;
    }

    Node* balance(Node* node) {
        fixHeigh(node);
        fixCount(node);
        uint8_t bf = bfactor(node);
        if (bf == 2) {
            if(bfactor(node->right) < 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        else if (bf == -2) {
            if(bfactor(node->left) > 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        return node;
    }

    Node* root;
    Comparator comp;
};

//int main() {
//    size_t n;
//    AVLTree<int> tree = AVLTree<int>();
//    size_t k;
//
//    cin >> n;
//
//    for (size_t i = 0; i < n; ++i) {
//        int elem;
//        cin >> elem >> k;
//        if (elem > 0)
//            tree.insert(elem);
//
//        if (elem < 0)
//            tree.erase(elem * -1);
//
//        cout << tree.KStat(k) << endl;
//    }
//
//    return 0;
//}