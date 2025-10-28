#pragma once
#include <iostream>

template <class K, class V>
class ListNode{
public:
    ListNode(K key=K(), V value=V()) : key(key), value(value) {}
    //getters
    V getValue() { return value; }
    K getKey() { return key; }
    ListNode* getNext() { return pNext; }
    // setters
    void setValue(V value) { this->value = value; }
    void setKey(K key) { this->key = key; }
    void setNext(ListNode<K,V>* pNext) { this->pNext = pNext; }
private:
    K key;
    V value;
    ListNode<K, V>* pNext;
};

template <class K, class V>
std::ostream& operator<<(std::ostream& lhs, ListNode<K, V>& rhs){
    lhs << "(K: " << rhs.getKey() << ",V: "  <<  rhs.getValue() << ")";
    return lhs;
}