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
		
};

#endif