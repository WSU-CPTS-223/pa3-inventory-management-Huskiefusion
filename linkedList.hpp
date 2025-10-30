#pragma once
#include <iostream>
#include "listNode.hpp"

template <class K, class V>
class LinkedList{
public:
    LinkedList() : pRoot(nullptr), length(0){};
    // insert
    void pushFront(const K& key, const V& value){
        ListNode<K, V>* pTmp = pRoot;
        pRoot = new ListNode<K, V>(key, value);
        pRoot->setNext(pTmp);
        ++length;
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

        --length;
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

    void print(void) const {
        ListNode<K, V>* pCur = pRoot;
        std::cout << "===== LIST START =====";
        while(pCur!=nullptr){
            std::cout << *pCur << std::endl;
            pCur=pCur->getNext();
        }
        std::cout << "===== LIST END =====" << std::endl;
        return;
    }

    ListNode<K,V>* operator[](const int& index){
        ListNode<K, V>* pCur = pRoot;
        for(int i=0; i< index; i++, pCur=pCur->getNext() ){
            if(pCur->getNext() == nullptr){
                perror("ERROR: INDEX OUT OF BOUNDS");
                return nullptr;
            }
        }
        return pCur;
    }
    int getLength(){ return length; }
private:
    ListNode<K, V>* pRoot;
    int length;
};

template <class K, class V>
std::ostream& operator<<(std::ostream& lhs, const LinkedList<K,V> rhs){
    rhs.print();
    return lhs;
}