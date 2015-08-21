#ifndef BTNODE_H
#define BTNODE_H

class BTNode{
	int data;
	BTNode* left;
	BTNode* right;

	public:
		// Constructors
		BTNode(int d) : data(d), left(NULL), right(NULL){}
		
		// Getters
		int getData() { return data; }
		BTNode* getLeft() { return left; }
		BTNode* getRight() { return right; }

		// Setters
		void setData(int d) { data = d; }
		void setLeft(BTNode* l) { left = l; }
		void setRight(BTNode* r) { right = r; }

		// Add new node
		void add(int d){
			BTNode * temp = this;
			BTNode * add_node = new BTNode(d);

			while(temp){
				if(temp->getData() < d){
					if(temp->getLeft()){
						temp = temp->getLeft();
					}
					else{
						temp->setLeft(add_node);
						return;
					}
				}
				else if(temp->getData() > d){
					if(temp->getRight()){
						temp = temp->getRight();
					}
					else {
						temp->setRight(add_node);
						return;
					}
				}
				else {
					delete add_node;
					return;
				}
			}
		}
		
};

#endif