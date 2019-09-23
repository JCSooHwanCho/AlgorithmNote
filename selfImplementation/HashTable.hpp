#include<string>

#ifndef __HashTable__

#define __HashTable__

#endif

struct Bucket {
    std::pair<std::string,int> value;
    Bucket * next;
};

class HashTable { 
    public:
    bool empty();
    int count();
    bool insert(const std::string key, const int value);
    bool remove(const std::string key);
    int find(const std::string key); 
    HashTable();

    private:
        int hashKey(const std::string key) {
            
        }
        Bucket * values;
        int n;
        int capacity;
};