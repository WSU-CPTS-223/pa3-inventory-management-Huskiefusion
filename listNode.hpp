#pragma once
#include <iostream>

template <class T>
class ListNode{
public:
    ListNode(T data=T()){ this->data=data; }
    T getData() { return data; }
    ListNode* getNext() { return pNext; }
    void setData(T data) { this->data = data; }
    void setNext(ListNode<T>* pNext) { this-pNext = pNext; }
private:
    T data;
    ListNode* pNext;
};