#pragma once
#include <iostream>
#include "listNode.hpp"

template <class K, class V>
class LinkedList{
public:
    LinkedList() : pRoot(nullptr){};
    // insert
    void pushFront(const K& key, const V& value){
        ListNode<K, V>* pTmp = pRoot;
        pRoot = new ListNode<K, V>(key, value);
        pRoot->setNext(pTmp);
    }
    bool remove(const K& toRemove){
        ListNode<K, V>* pCur = pRoot, *pPrev=nullptr;
        while(pCur!=nullptr){
            if(pCur->getKey() == toRemove){
                if(pPrev!=nullptr){
                    pPrev->setNext(pCur->getNext());
                }
                else{
                    pRoot=nullptr;
                }
                delete pCur;
                return true;
            }
            pPrev = pCur;
            pCur=pCur->getNext();
        }

        return false;
    }
    bool find(const K& toFind, V& obj){
        ListNode<K, V>* pCur = pRoot;
        while(pCur!=nullptr){
            if(pCur->getKey() == toFind){
                obj = pCur->getValue();
                return true;
            }
            pCur=pCur->getNext();
        }

        return false;
    }

    void print(void){
        ListNode<K, V>* pCur = pRoot;
        std::cout << "{";
        while(pCur!=nullptr){
            std::cout << *pCur << ", ";
            pCur=pCur->getNext();
        }
        std::cout << "}" << std::endl;
        return;
    }
private:
    ListNode<K, V>* pRoot;
};
