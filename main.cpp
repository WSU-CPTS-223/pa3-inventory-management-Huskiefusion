#include <iostream>
#include <string>
#include "inventoryManager.hpp"


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

void evalCommand(string line, AmazonInventoryManager& man)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        if(line.find(' ') != line.npos){
            string lookup = line.substr(line.find(' ')+1);
            man.find(lookup);
        }
        else{
            cout << "No ID provided!" << endl;
        }
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        if(line.find(' ') != line.npos){
            string lookup = line.substr(line.find(' ')+1);
            man.listCategory(lookup);
        }
        else{
            cout << "No category provided!" << endl;
        }
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
    AmazonInventoryManager amznInvManager;

    bootStrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line, amznInvManager);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
