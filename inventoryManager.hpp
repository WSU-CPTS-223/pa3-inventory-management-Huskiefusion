#pragma once
#include <iostream>
#include <fstream>
#include "linkedList.hpp"
#include "hashTable.hpp"
#include "avlMap.hpp"
#include "listing.hpp"

using namespace std;

class AmazonInventoryManager{
private:
    HashTable<string, ItemListing> listingTable; // for the find function
    // I could implement a vector-like class but LinkedList works well enough and is the same speed for what we're doing :)
    AVLMap<string, LinkedList<string, ItemListing>> itemsByCategory; // for the category function

public:
    AmazonInventoryManager(): listingTable(20021) {
        ifstream dataFile("lib/data.csv");
        string line;
        getline(dataFile, line); // clear the info line
        while(getline(dataFile, line)){
            ItemListing item = ItemListing::fromString(line);
            listingTable.insert(item.uniqId, item);
            for(int i=0; i < item.categories.getLength(); i++){
                LinkedList<string, ItemListing> tmp;
                auto node = itemsByCategory.findNode(item.categories[i]->getKey());
                if (node){
                    tmp = node->getValue();
                    tmp.pushFront(item.uniqId, item);
                    node->setValue(tmp);
                    //cout << item.categories[i]->getKey() << endl;
                }
                else{
                    tmp.pushFront(item.uniqId, item);
                    itemsByCategory.insert(item.categories[i]->getKey(), tmp);
                }
            }
        }
        dataFile.close();
    }

    void find(string uniqId){
        ItemListing tmp;
        if(listingTable.find(uniqId, tmp)){
            cout << tmp << endl;
        }
        else{
            cout << "Item not found!" << endl;
        }
    }

    void listCategory(string category){
        LinkedList<string, ItemListing> tmp;
        if (itemsByCategory.find(category, tmp)){
            tmp.print();
        }
        else{
            cout << "CATEGORY NOT FOUND (WAS \"" << category << "\")" << endl;
        }
    }
};