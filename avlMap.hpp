#pragma once
#include <iostream>
#include "avlNode.hpp"
#include <math.h>


template <class _Key, class _Value>
class AVLMap{
public:
    AVLMap(){
        pRoot = nullptr;
    }
    AVLNode<_Key, _Value>* getRoot(void){
        return pRoot;
    }
    void setRoot(AVLNode<_Key, _Value>* newRoot){
        pRoot = newRoot;
    }

    void insert(const _Key &key, const _Value &value){
        if(pRoot==nullptr){
            pRoot = new AVLNode<_Key, _Value>(key, value);
            return;
        }

        pRoot = insert(key, value, pRoot);
    }
    
    void erase(const _Key &key){
        if(pRoot==nullptr){
            std::cout << "Error: Deleting from empty tree!" << std::endl;
            return;
        }
        erase(key, this->pRoot);

    }
    void inorderTraversal(){
        inorderTraversal(pRoot);
    }
    bool find(const _Key& key, _Value& obj){
        return find(key, obj, pRoot);
    }
    AVLNode<_Key,_Value>* findNode(const _Key& key){
        return findNode(key, pRoot);
    }
    

private:  


    AVLNode<_Key, _Value>* insert(const _Key &key, const _Value &value, AVLNode<_Key, _Value>* pRoot){
        if(pRoot == nullptr){ return new AVLNode<_Key, _Value>(key, value); }
        
        // Insert the value
        if(key < pRoot->getKey()){
            pRoot->setLeft( insert(key, value, pRoot->getLeft()) );
        }
        else if(key > pRoot->getKey()){
            pRoot->setRight( insert(key, value, pRoot->getRight()) );
        }
        else { return pRoot; }

        // Only here if on the path back from insertion
        // So update height
        pRoot->setHeight(std::max(node_height(pRoot->getLeft()), node_height(pRoot->getRight())) + 1 );
        
        
        int balance = node_balance(pRoot);
        // do rotations (LL LR RR RL)
        // LL 
        if (balance > 1 && pRoot && pRoot->getLeft() && key < pRoot->getLeft()->getKey()){
            return rightRotate(pRoot);
        }
        // LR
        if(balance > 1 && pRoot && pRoot->getLeft() && key > pRoot->getLeft()->getKey()){
            pRoot->setLeft(leftRotate( pRoot->getLeft() ));
            return rightRotate(pRoot);
        }
        // RR
        if (balance < -1 && pRoot && pRoot->getRight() && key > pRoot->getRight()->getKey()){
            return leftRotate(pRoot);
        }
        //RL
        if(balance < -1 && pRoot && pRoot->getRight() && key < pRoot->getRight()->getKey()){
            pRoot->setRight(rightRotate( pRoot->getRight() ));
            return leftRotate(pRoot);
        }


        return pRoot;
    }
    
    AVLNode<_Key, _Value>* erase(const _Key& key, AVLNode<_Key, _Value>* pRoot){
        if(pRoot==nullptr){
            return nullptr;
        }

        //std::cout << pRoot << std::endl; 
        if(key < pRoot->getKey()){
            pRoot->setLeft( erase(key, pRoot->getLeft()) );
        }
        else if(key > pRoot->getKey() ){
            pRoot->setRight( erase(key, pRoot->getRight()) );
        }
        else{
            // Key is equal, delete.
            // Leaf node, nothing to move
            if(!pRoot->getLeft() && !pRoot->getRight()){
                pRoot = nullptr;
            }
            // If only one child, move it
            else if(pRoot->getLeft() && !pRoot->getRight()){
                AVLNode<_Key,_Value>* temp = pRoot->getLeft();
                delete pRoot;
                return temp;
            }
            else if(pRoot->getRight() && !pRoot->getLeft()){
                AVLNode<_Key,_Value>* temp = pRoot->getRight();
                delete pRoot;
                return temp;
            }

            // Two children
            else{
                AVLNode<_Key,_Value>* tmp = getSmallestKey(pRoot->getRight());
                pRoot->setKey(tmp->getKey());
                pRoot->setRight(erase(tmp->getKey(), pRoot->getRight() ));
            }

        }

        if(pRoot==nullptr) return nullptr;

        pRoot->setHeight(1 + std::max(node_height(pRoot->getLeft()), node_height(pRoot->getRight())));

        int balance = node_balance(pRoot);
        // rotation time
        // LL
        if(balance > 1 && node_balance(pRoot->getLeft()) >= 0){
            return rightRotate(pRoot);
        }
        // LR
        if(balance > 1 && node_balance(pRoot->getLeft()) < 0){
            pRoot->setLeft(leftRotate(pRoot->getLeft()));
            return rightRotate(pRoot);
        }
        // RR
        if(balance < -1 && node_balance(pRoot->getRight()) <= 0 ){
            return leftRotate(pRoot);
        }
        // RL
        if(balance < -1 && node_balance(pRoot->getRight()) > 0 ){
            pRoot->setRight(rightRotate(pRoot->getRight()));
            return leftRotate(pRoot);
        }

        return pRoot;
    }

    AVLNode<_Key, _Value>* getSmallestKey(AVLNode<_Key, _Value>* pRoot){
        while(pRoot->getLeft()){
            pRoot=pRoot->getLeft();
        }
        return pRoot;
    }

    AVLNode<_Key,_Value>* leftRotate(AVLNode<_Key,_Value>* node) {
        AVLNode<_Key,_Value>* newRoot = node->getRight();
        AVLNode<_Key,_Value>* toMove = newRoot->getLeft();

        // Perform rotation
        newRoot->setLeft(node);
        node->setRight(toMove);

        // Update heights
        node->setHeight(1 + std::max(node_height(node->getLeft()), node_height(node->getRight())));
        newRoot->setHeight(1 + std::max(node_height(newRoot->getLeft()), node_height(newRoot->getRight())));

        // Return new root
        return newRoot;
    }

    AVLNode<_Key,_Value>* rightRotate(AVLNode<_Key,_Value>* node) {
        AVLNode<_Key,_Value>* newRoot = node->getLeft();
        AVLNode<_Key,_Value>* toMove = newRoot->getRight();

        // Perform rotation
        newRoot->setRight(node);
        node->setLeft(toMove);

        // Update heights
        node->setHeight(1 + std::max(node_height(node->getLeft()), node_height(node->getRight())));
        newRoot->setHeight(1 + std::max(node_height(newRoot->getLeft()), node_height(newRoot->getRight())));

        // Return new root
        return newRoot;
    }

    void inorderTraversal(AVLNode<_Key, _Value>* pRoot){
        if(pRoot==nullptr) return;
        inorderTraversal(pRoot->getLeft());
        //std::cout << pRoot << std::endl;
        std::cout << "K: " << pRoot->getKey() << ", V:" << pRoot->getValue() << std::endl;
        inorderTraversal(pRoot->getRight());
        
    }
    AVLNode<_Key, _Value>* pRoot;

    bool find(const _Key& key, _Value& obj, AVLNode<_Key, _Value>* pRoot){
        if(pRoot==nullptr) return false;
        if(pRoot->getKey() == key) {
            obj=pRoot->getValue();
            return true;
        }
        return find(key, obj, pRoot->getLeft()) || find(key, obj, pRoot->getRight());
    }
    
    AVLNode<_Key,_Value>* findNode(const _Key& key, AVLNode<_Key,_Value>* pRoot){
        if(pRoot==nullptr) return nullptr;
        if(pRoot->getKey() == key) {
            return pRoot;
        }
        AVLNode<_Key,_Value>* leftVal = findNode(key, pRoot->getLeft()), *rightVal = findNode(key, pRoot->getRight());
        return (leftVal) ? leftVal : rightVal;
    }

};

template <class _Key, class _Value>
int node_height(AVLNode<_Key, _Value>* node){
    return (node==nullptr) ? 0 : node->getHeight();
}

template <class _Key, class _Value>
int node_balance(AVLNode<_Key, _Value>* node){
    return node_height(node->getLeft()) - node_height(node->getRight());
}