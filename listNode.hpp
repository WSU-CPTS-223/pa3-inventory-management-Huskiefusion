#pragma once
#include <iostream>

template <class K, class V>
class ListNode{
public:
    ListNode(K key=K(), V value=V()) : key(key), value(value) {}
    //getters
    V getValue() const { return value; }
    K getKey() const { return key; }
    ListNode* getNext() const { return pNext; }
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
std::ostream& operator<<(std::ostream& lhs, const ListNode<K, V>& rhs){
    lhs << "(K: " << rhs.getKey() << ",V: "  <<  rhs.getValue() << ")";
    return lhs;
}