#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashEntry.cpp"

class HashMap{
	int size;
	HashEntry** table;

public:
	HashMap():size(128){
		table = new HashEntry*[size];

		for(int i = 0; i < size; i++){
			table[i] = NULL;
		}
	}

	~HashMap(){
		for(int i = 0; i < size; i++){
			HashEntry* temp = table[i];
			
			while(temp){
				HashEntry* prev = temp;
				temp = temp->getNext();
				delete prev;
			}

			delete [] table;

		}
	}

	int getHash(int k){
		return k % size;
	}

	void insert(int k, int v){
		HashEntry* new_entry = new HashEntry(k, v);
		int hash = getHash(k);

		if(table[hash]){
			HashEntry* temp = table[hash];
			HashEntry* prev;

			while(temp){

				if(temp->getKey() == k){
					temp->setValue(v);
					delete new_entry;
					return;
				}

				prev = temp;
				temp = temp->getNext();

			}

			prev->setNext(new_entry);
		}
		else{
			table[hash] = new_entry;
		}

	}

	HashEntry* get(int k){
		int hash = getHash(k);

		HashEntry* temp = table[hash];

		while(temp){

			if(temp->getKey() == k)
				return temp;

			temp = temp->getNext();
		}

		return NULL;
	}

	void display(){
		for(int i = 0; i < size; i++){
			std::cout << i << " | ";

			HashEntry* temp = table[i];

			while(temp){
				std::cout << "K" << temp->getKey() << "-" 
						  << "V" << temp->getValue() << " | ";

				temp = temp->getNext();
			}

			std::cout << std::endl;
		}
	}

};

#endif