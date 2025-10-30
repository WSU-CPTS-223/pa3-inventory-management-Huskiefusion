#pragma once
#include <iostream>

template <class _Key, class _Value>
class AVLNode{
public:
    AVLNode(const _Key &key = _Key(), const _Value &value = _Value()){
        this -> key = key;
        this -> value = value;
        pLeft = pRight = nullptr;
        height=1;
    }
    const _Key& getKey() const { return key;}
    const _Value& getValue() const { return value; }
    int getHeight() const {return height;}
    void setHeight (int height) { this->height = height; }
    AVLNode<_Key, _Value>* getLeft() const { return pLeft; }
    AVLNode<_Key, _Value>* getRight() const { return pRight; }
    void setKey(_Key key) { this->key = key; }
    void setValue(_Value value) { this->value = value; }
    void setLeft(AVLNode<_Key, _Value> *left){ this->pLeft = left; }
    void setRight(AVLNode<_Key, _Value> *right) { this->pRight = right; }
private:

    _Key key;
    _Value value;
    AVLNode<_Key, _Value> *pLeft, *pRight;
    int height;
};

template <class _Key, class _Value>
std::ostream& operator<<(std::ostream& lhs, AVLNode<_Key, _Value>* rhs){
    if(rhs==nullptr) {
        lhs << "nullptr";
    }
    else{
        lhs << "K: "<< rhs->getKey() << " V: " << rhs->getValue() << " H: " << rhs->getHeight() << 
            "\tL? " << (bool)rhs->getLeft(); 
        if(rhs->getLeft()) lhs << ", Key: " << rhs->getLeft()->getKey();
        lhs << " R? " << (bool)rhs ->getRight();
        if(rhs->getRight()) lhs << ", Key: " << rhs->getRight()->getKey();
    }
    return lhs;
}