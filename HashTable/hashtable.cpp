#include "hashtable.hpp"

int main(void) {
    
    HashTable <char, int, IntHash, IntCmp> hashtable(100);
    
    hashtable.put('a',2);
    hashtable.put('b',2);
    std::cout << hashtable.find('a') << "\n";
    std::cout << hashtable.find('d') << "\n";

    std::cout << hashtable.size();

    return 0;
}