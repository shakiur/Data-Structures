#ifndef BTNODE_H
#define BTNODE_H

class BTNode{
	int data;
	BTNode* left;
	BTNode* right;

	public:
		// Constructors
		BTNode(int d) : data(d), left(NULL), right(NULL) {}

		// Setters
		void setData(int d) { data = d; }
		void setLeft(BTNode* l) { left = l; }
		void setRight(BTNode* r) { right = r; }

		// Getters
		int getData() { return data; }
		BTNode* getLeft() { return left; }
		BTNode* getRight() { return right; }

		void push(int d){

			BTNode * n = new BTNode(d);
			BTNode * temp = this;

			while(temp){
				if(temp->getData() == d){
					// Node already exists
					delete n;
					return;
				}
				else if(d < temp->getData()){
					// Node is less current data, iterate left
					if(temp->getLeft()){
						temp = temp->getLeft();
					}
					else{
						temp->setLeft(n);
						return;
					}
				}
				else{
					// Node is greater than current data, iterate right if possible
					if(temp->getRight()){
						temp = temp->getRight();
					}
					else{
						temp->setRight(n);
						return;
					}
				}
			}
		}

};

#endif