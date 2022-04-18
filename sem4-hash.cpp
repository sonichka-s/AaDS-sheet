//
// Created by sonichka on 26.11.2021.
//
#include "iostream"
#include "vector"

using namespace std;

size_t str_hash(const std::string& data) {
    size_t hash = 0;
    for (char i : data)
        hash = hash * 13 + i;
    return hash;
}

template<class T> struct Hasher {
    size_t operator() (const T& key) const {
        return key;
    }
};

template<> struct Hasher<std::string> {
    size_t operator() (const std::string& key) const {
        return str_hash(key);
    }
};

template <class T>
struct DefaultEqual {
    bool operator() (const T& l, const T& r) const {
        return l == r;
    }
};

template<class Key, class Equal = DefaultEqual<Key>, class Hash = Hasher<Key>>
class HashSet {
    static constexpr int max_load_factor = 7;
    struct  HashNode {
        Key key;
        HashNode* next;

        HashNode(const Key& key, HashNode* next) : key(key){}
    };

public:
    HashSet(Hash hash = Hash(), Equal equal = Equal()) :
        buckets(8, nullptr),
        hash(hash),
        equal(equal),
        items_count(0)
    {
    }

    HashSet(const HashSet&) = delete;
    HashSet& operator=(const HashSet&) = delete;

    ~HashSet() {
        for (int i = 0; i < buckets.size(); ++i){
            HashNode* cur = buckets[i];
            while (cur) {
                HashNode* tmp = cur;
                cur = cur->next;
                delete tmp;
            }
        }
    }

    bool add(const Key& key) {
        if (has(key)) {
            return false;
        }

        if (items_count / buckets.size() > max_load_factor){
            grow();
        }

        size_t bucket_idx = hash(key) % buckets.size();
        HashNode* node = new HashNode(key, buckets[bucket_idx]);
        buckets[bucket_idx] = node;

        items_count++;
        return true;
    }
    bool has(const Key& key) const {
        size_t bucket_idx = hash(key) % buckets.size();
        HashNode* cur = buckets[bucket_idx];
        while (cur) {
            if (equal(cur->key, key)) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool del(const Key& key) {
        if (!has(key)) {
            return false;
        }
        size_t bucket_idx = hash(key) % buckets.size();
        HashNode* cur = buckets[bucket_idx];
        HashNode** prev_next = &buckets[bucket_idx];
        while (cur) {
            if (equal(cur->key, key)) {
                prev_next = &cur->next;
                delete cur;
                items_count--;
                return true;
            }
            prev_next = &(cur->next);
            cur = cur->next;
        }
        return false;
    }

private:
    void grow() {
        std::vector<HashNode*> new_buckets(buckets.size());
        for (int i = 0; i < buckets.size(); ++i) {
            HashNode* cur = buckets[i];
            while (cur) {
                HashNode *tmp = cur;
                cur = cur->next;

                size_t new_bucket_idx = hash(tmp->key) % new_buckets.size();
                tmp->next = new_buckets[new_bucket_idx];
                new_buckets[new_bucket_idx] = tmp;
            }
        }
        buckets = std::move(new_buckets);
    }

    std::vector<HashNode*> buckets;

    Hash hash;
    Equal equal;

    size_t items_count;
};

//int main() {
//    HashSet<std::string> set;
//    std::string  key;
//    char operation = '\0';
//    while(std::cin >> operation >> key) {
//        bool res = false;
//        switch (operation) {
//            case '+':
//                res = set.add(key);
//                break;
//            case '?':
//                res = set.has(key);
//                break;
//            case '-':
//                res = set.del(key);
//                break;
//            default:
//                break;
//        }
//
//        if (res) {
//            std:: cout << "OK" << std::endl;
//        }
//        else {
//            std::cout << "FAIL" << std::endl;
//        };
//    }
//    return  0;
//}