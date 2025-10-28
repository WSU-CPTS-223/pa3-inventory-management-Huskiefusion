#pragma once
#include <iostream>
#include "linkedList.hpp"

// class K needs to have a definition for std::hash<K>  (eg: std::string, int, etc...)
template<class K, class V>
class HashTable{
private:
    std::hash<K> hashFunc;
    int size, capacity; // size is the actual number of items, capacity is the 'maximum' size 
    LinkedList<K, V> *table;
public:
    HashTable(int capacity=1){
        this->capacity=capacity;
        this->size = 0;
        table = new LinkedList<K, V>[capacity];
    }
    // TODO: Implement
    HashTable(const HashTable& obj){

    }
    // TODO: Implement
    ~HashTable(){

    }

    void insert(const K& key, const V& value){
        // hash the key
        int hashedKey = hashFunc(key)%capacity;
        // make the table insert the thing
        table[hashedKey].pushFront(key, value);
        ++size; 
    }

    bool find(const K& key, V& obj){
        // hash the key
        int hashedKey = hashFunc(key)%capacity;
        // linked list find()
        return table[hashedKey].find(key, obj);
    }

    bool remove(const K& key){
        // hash the key
        int hashedKey = hashFunc(key)%capacity;
        // make the list do the work for me :p
        return table[hashedKey].remove(key);
    }

};