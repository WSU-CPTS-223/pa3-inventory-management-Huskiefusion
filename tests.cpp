#include <iostream>
#include <cassert>
#include "avlMap.hpp"
#include "linkedList.hpp"
#include "hashTable.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    char tmp; // this is used in multiple tests

    cout << "====== RUNNING AVL MAP TESTS ======" << endl;
    cout << "=== INSERTION TEST ===" << endl;
    AVLMap<int, char> map;
    map.insert(1, 'a');
    map.insert(2, 'b');
    assert(map.getRoot()->getKey() == 1);
    assert(map.getRoot()->getRight()->getKey() == 2);
    map.insert(3, 'c');
    assert(map.getRoot()->getKey() == 2 && map.getRoot()->getLeft()->getKey() == 1 && map.getRoot()->getRight()->getKey() == 3);
    cout << "=== INSERTION PASSED ===" << endl;

    cout << "=== FIND TEST ===" << endl;
    AVLMap<int, char> emptyMap;
    assert(map.find(1, tmp));
    assert(tmp=='a');
    assert(!map.find(4, tmp));
    cout << "=== FIND PASSED ===" << endl;
    
    cout << "=== FINDNODE TEST ===" << endl;
    assert(map.findNode(1) == map.getRoot()->getLeft());
    assert(map.findNode(3)->getValue()=='c');
    assert(!map.findNode(10));
    cout << "=== FINDNODE PASSED ===" << endl;

    cout << "====== FINISHED AVL MAP TESTS ======" << endl;

    cout << "====== RUNNING LINKED LIST TESTS ======" << endl;
    LinkedList<int, char> list;
    LinkedList<int, char> emptyList;
    cout << "=== PUSHFRONT TEST ===" << endl;
    list.pushFront(3, 'c');
    list.pushFront(2, 'b');
    list.pushFront(1, 'a');
    list.pushFront(3, 'd');
    assert(list[1]->getValue() == 'a');
    cout << "=== PUSHFRONT PASSED ===" << endl;
    assert(list.find(3, tmp));
    assert(tmp=='d');
    // The operator[] function throws an error on out of bounds so testing it doenst work here
    cout << "====== FINISHED LINKED LIST TESTS ======" << endl;

    cout << "====== RUNNING HASH TABLE TESTS ======" << endl;
    cout << "====== FINISHED HASH TABLE TESTS ======" << endl;
    cout << "============================" << endl << "*     ALL TESTS PASSED     *" << endl << "============================" << endl;
    
}