#pragma once
#include <iostream>
#include "listNode.hpp"

template <class T>
class LinkedList{
public:
    LinkedList() : pRoot(nullptr){};
    // insert
    void pushFront(T data){
        ListNode<T>* pTmp = pRoot;
        pRoot = new ListNode<T>(data);
        pRoot->setNext(pTmp);
    }

    bool remove(const T& toRemove){
        ListNode<T>* pCur = pRoot, *pPrev=nullptr;
        while(pCur!=nullptr){
            if(pCur->getData() == toRemove){
                pPrev->setNext(pCur->getNext());
                delete pCur;
                return true;
            }
            pPrev = pCur;
            pCur=pCur->getNext();
        }

        return false;
    }
    ListNode<T>* find(const T& toFind){
        ListNode<T>* pCur = pRoot;
        while(pCur!=nullptr){
            if(pCur->getData() == toFind){
                return true;
            }
            pCur=pCur->getNext();
        }

        return false;
    }
private:
    ListNode<T>* pRoot;
};