#ifndef __HASHTABLE__
#define __HASHTABLE__

#include <iostream>
#include <string>
#include <list>
#include <vector>

// class for hashing
class IntHash {
public:
    int operator()(const int &value) { return value; }
};
// class for comparing two keys
class IntCmp {
public:
    int operator()(const int &a, const int &b) { return a==b; }
};

// template of the hashtable class
template <class Tkey, class Tvalue, class Thash_fun, class Tcmp>

class HashTable {
    
    typedef std::pair<Tkey, Tvalue> HashPair;
    typedef std::list<HashPair> HashList;
    typedef std::vector<HashList> _HastTable;

    _HastTable hash_table;
    int capacity;
    Thash_fun hash_function;
    Tcmp cmp_function;

public:
    int size_hashtable;
    HashTable(int size):capacity(size) {
        hash_table.resize(size);
    }

    // function to find a key in hashtable
    Tvalue find(const Tkey &key) {
        int index = hash_function(key) % capacity;
        HashList &list = hash_table[index];
        auto it = list.begin();
        while (it != list.end()) {
            if (cmp_function(it->first, key)) {
                return it->second;
            }
            it++;
        }
        return 0;
    }

    // function to put pair key, value in hashtable
    void put(const Tkey &key, const Tvalue &value) {
        int index = hash_function(key) % capacity;
        
        HashList &list = hash_table[index];
        auto it = list.begin();
        while (it != list.end()) {
            if (cmp_function(it->first, key)) {
                it->second = value;
                return;
            }
            it++;
        }
        list.push_back(std::pair<Tkey, Tvalue>(key, value));
        this->size_hashtable++;
    }

    // function to calculate size of the hashtable
    int size() {
        return this->size_hashtable;
    }
};

#endif // __HASHTABLE__