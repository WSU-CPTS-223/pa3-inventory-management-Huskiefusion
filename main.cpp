#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include "linkedList.hpp"
#include "hashTable.hpp"
#include "avlMap.hpp"
#include "listing.hpp"

using namespace std;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        cout << "YET TO IMPLEMENT!" << endl;
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        cout << "YET TO IMPLEMENT!" << endl;
    }
}

void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
}

int main(int argc, char const *argv[])
{
    string line;
    // make a hashmap with the uniqId as key, store product
    // make a hashmap with the category as key, store list of products
    //read the data set
    /*
        * 10007 is the nearest prime to 10002
        ...
        * After some testing, I am going to make the table 20021 'units' long. 
        * 10007 produced too many collisions.
    */
    ifstream dataFile("lib/data.csv");
    HashTable<string, ItemListing> listingTable(20021); // for the find function
    // I could implement a vector-like class but LinkedList works well enough and is the same speed for what we're doing :)
    AVLMap<string, LinkedList<string, ItemListing>> itemsByCategory; // for the category function
    LinkedList<int, string> egg;

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
    
    LinkedList<string, ItemListing> toys;
    itemsByCategory.find("Toys & Games", toys);
    toys.print();
    // ItemListing it;
    // listingTable.find("688395bec3dd1797d15119b5b14a631c", it);
    // cout << it.productName << endl;

    return 0;
    bootStrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
