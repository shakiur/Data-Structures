#include <iostream>
#include "headers/BTNode.h"
#include "headers/Queue.h"

// Builds sample binary tree
BTNode* buildTree();

// Depth first traversals
void preOrder(BTNode*);
void inOrder(BTNode*);
void postOrder(BTNode*);

// Breadth first traversal
int getHeight(BTNode*);
void BFS(BTNode*);
void BFSLevel(BTNode*, int);

// Breadth first traversal with queue
void BFSQueue(BTNode*);
void BFSQueueLevel(BTNode*, Queue*);
int main(){

	BTNode * root = buildTree();

	std::cout << "Pre Order: ";
	preOrder(root);
	std::cout << std::endl;

	std::cout << "In Order: ";
	inOrder(root);
	std::cout << std::endl;

	std::cout << "Post Order: ";
	postOrder(root);
	std::cout << std::endl;

	std::cout << "Breadth First Traversal: ";
	BFS(root);
	std::cout << std::endl;

	std::cout << "Breadth First Traversal Queue: ";
	BFSQueue(root);
	std::cout << std::endl;

}

BTNode* buildTree(){
	BTNode * root = new BTNode(5);

	root->push(2);
	root->push(1);
	root->push(3);
	root->push(4);
	
	root->push(7);
	root->push(6);
	root->push(8);

	return root;
}

void preOrder(BTNode* root){
	if(root){
		std::cout << root->getData() << " ";
		preOrder(root->getLeft());
		preOrder(root->getRight());
	}
}

void inOrder(BTNode* root){
	if(root){
		inOrder(root->getLeft());
		std::cout << root->getData() << " ";
		inOrder(root->getRight());
	}
}

void postOrder(BTNode* root){
	if(root){
		postOrder(root->getLeft());
		postOrder(root->getRight());
		std::cout << root->getData() << " ";
	}
}

int getHeight(BTNode* root){
	if(root == NULL){
		return 0;
	}
	else{
		int left_h = getHeight(root->getLeft());
		int right_h = getHeight(root->getRight());

		if(left_h > right_h){
			return 1 + left_h;
		}
		else{
			return 1 + right_h;
		}
	}
}

void BFSLevel(BTNode* root, int level){
	if(root == NULL){
		return;
	}
	else if(level == 0){
		std::cout << root->getData() << " ";
	}
	else{
		BFSLevel(root->getLeft(), level-1);
		BFSLevel(root->getRight(), level-1);
	}
}

void BFS(BTNode* root){

	int height = getHeight(root);

	for(int i = 0; i < height; i++){
		BFSLevel(root, i);
	}

}

void BFSQueueLevel(BTNode* root, Queue* q){

	q->enqueue(root);

	if(!q->isEmpty()){
		LLNode * temp = q->dequeue();
		std::cout << temp->getData() << " ";
	}

	if(root->getLeft())
		BFSQueueLevel(root->getLeft(), q);

	if(root->getRight())
		BFSQueueLevel(root->getRight(), q);

}

void BFSQueue(BTNode* root){
	Queue * q = new Queue;
	q->enqueue(root);

	while(!q->isEmpty()){
		LLNode* temp = q->dequeue();
		std::cout << temp->getData()->getData() << " ";

		if(temp->getData()->getLeft())
			q->enqueue(temp->getData()->getLeft());

		if(temp->getData()->getRight())
			q->enqueue(temp->getData()->getRight());

	}
	
}