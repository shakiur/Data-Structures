#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashEntry.cpp"

const int TABLE_SIZE = 10;

class HashMap {

    HashEntry** hash_table;
    int getHash(int key) { return key % TABLE_SIZE; }

    public:
        HashMap(){
            hash_table = new HashEntry*[128];

            // Initialize each entry to NULL
            for(int i = 0; i < 128; i++){
                hash_table[i] = NULL;
            }
        }

        void pushEntry(int newKey, int newVal) {

            int hash = getHash(newKey);

            // New hash entry to be potentially added
            HashEntry* newEntry = new HashEntry(newKey, newVal);

            if(hash_table[hash]){

                // Find same key to update, or create new entry
                HashEntry* temp = hash_table[hash];

                while(temp){
                    
                    // Key already, exists update value
                    if(temp->getKey() == newKey){
                        temp->setValue(newVal);
                        delete newEntry;
                        return;
                    }
                    
                    // Went through all hashEntries, not found so append new hashEntry
                    if(!temp->getNext()){
                        temp->setNext(newEntry);
                    }

                    temp = temp->getNext();
                }


            }
            else {
                // Add to current table
                hash_table[hash] = newEntry;
            }
        }

        void display(){

            for(int i = 0; i < TABLE_SIZE; i++){

                HashEntry* temp = hash_table[i];
                std::cout << i << "->";

                if(hash_table[i]){
                    
                    while(temp){
                        std::cout << "(" << temp->getKey() << "|" << temp->getValue() << ")->"; 

                        temp = temp->getNext();
                    }

                }

                std::cout << "NULL\n";

            }
        }
};

#endif