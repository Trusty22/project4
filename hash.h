// ---------------------------------------------------- hash.h --------------------------------------------------------
// Jacob Pedersen, Mandeep Masoun | CSS343 B Au 23
// Creation Date: 11.27.2023
// Date of Last Modification: 12.12.2023
// --------------------------------------------------------------------------------------------------------------------
// Implementation file for hash table. 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This is the header file for the hash table being used for our program. We used several online resources to implement
// this hash table hence the basic structure. The use of functional allows us to use std::hash, and per the instructions, 
// we are allowed to use std library and the like. We also got help from the QSC. 
// --------------------------------------------------------------------------------------------------------------------
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <functional>

const int TABLE_SIZE = 200;

template <typename Key, typename Val>
class HashTable{
public:
    HashTable(){
        table = new HashNode *[TABLE_SIZE]();
    }

    ~HashTable(){
        delete[] table;
    }

    void insertItem(const Key &k, const Val &v){
        int hashVal = customHashFunction(k);
        HashNode *p = nullptr;
        HashNode *item = table[hashVal];
        while(item && item->getKey() != k){
            p = item;
            item = item->getNext();
        }
        if(!item) {
            item = new HashNode(k, v);
            if(!p){
                table[hashVal] = item;
            }else{
                p->setNext(item);
            }
        } else{
            item->setVal(v);
        }
    }










    bool findItem(const Key &k){
        int hashVal = customHashFunction(k);
        HashNode *item = table[hashVal];
        while (item){
            if(item->getKey() == k){
                return true;
            }
            item = item->getNext();
        }
        return false;
    }

    Val *retrieve(const Key &k){
        Val *val = nullptr;
        int hashVal = customHashFunction(k);
        HashNode *item = table[hashVal];
        while (item){
            if (item->getKey() == k){
                return val;
            }
            item = item->getNext();
        }
        return val;
    }

    //---------------------------- removeItem ---------------------------------
    // Removes given desired item from the hash table
    // Uses item key to find item first and then removes it
    // ------------------------------------------------------------------------
    void removeItem(const Key &k){
        int hashVal = customHashFunction(k);
        HashNode *p = nullptr;
        HashNode *item = table[hashVal];
        while(item && item->getKey() != k){
            p = item;
            item = item->getNext();
        }
        if(!item){
            return;
        }else{
            if(!p){
                table[hashVal] = item->getNext();
            }else{
                p->setNext(item->getNext());
            }
            delete item;
        }
    }

    //---------------------------- printAllData -------------------------------
    // Iterates through the table and prints all the vals stored
    // ------------------------------------------------------------------------
    void printAllData(){
        for(int i = 0; i < TABLE_SIZE; i++){
            HashNode *item = table[i];
            while(item){
                std::cout << item->getVal() << std::endl;
                item = item->getNext();
            }
        }
    }

private:
    class HashNode{
    public:
        HashNode(const Key &k, const Val &v) : key(k), val(v), next(nullptr) {}

        Key getKey() const { return key; }
        Val getVal() const { return val; }
        HashNode *getNext() const { return next; }
        void setNext(HashNode *n) { next = n; }
        void setVal(const Val &v) { val = v; }

/*         HashNode *getNext() const { return next; }
        void setNext(HashNode *n) { next = n; }
        void setVal(const Val &v) { val = v; } */



    private:
        Key key;
        Val val;
        HashNode *next;
    };

    HashNode **table;

    // Simple custom hash function (for demonstration purposes)
    int customHashFunction(const Key &k) {
        // This is just a simple example; in a real-world scenario, you'd want a better hash function.
        // This one assumes that Key can be cast to int.
        return static_cast<int>(k) % TABLE_SIZE;
    }
};

#endif 