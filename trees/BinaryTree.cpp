/*
 * BinaryTree.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: johngarcia
 */


#include <iostream>
#include <stdlib.h>
#include <time.h>


struct node
{
	int key_value;
	node *left;
	node *right;
};


class BinaryTree {

public:
	BinaryTree();
	~BinaryTree();
    void insert(int key);
    void preOrder();
    void postOrder();
    void inOrder();
    void rebalanceTree();
    void findElement(int key);
    void getRootValue();
    void commonAncestor(int key1, int key2);


private:
	void addNode(int key, node *leaf);
	void postOrder(node *root);
	void preOrder(node *root);
	void printTree(node *leaf);
	void inOrder(node *root);
  void reBalanceTree(node *root);
  void findElement(int key, node *root);
	void destroy_tree(node *root);
  void commonAncestor(int key1, int key2, node *root);

	node *root;

};

BinaryTree::BinaryTree(){
	root = NULL;
}

BinaryTree::~BinaryTree(){

std::cout << "[*] Destroying tree...calling destructor" << std::endl;
     this->destroy_tree(root);


}

void BinaryTree::findElement(int key){

    this->findElement(key,root);

}



void BinaryTree::findElement(int key, node *root){

    if(root == NULL){
          return;
    } else {
       if( root->key_value == key){
            std::cout << "Found key: " << key << std::endl;
       } else {
              // We can reduce the search to n/2
              // because we will only search half the tree.
              if(key < root->key_value)
             findElement(key, root->left);

              if(key > root->key_value)
             findElement(key, root->right);

       }


   }


}


void BinaryTree::destroy_tree(node *root){
	if(root != NULL){

		destroy_tree(root->left);
		destroy_tree(root->right);
		delete(root);
	}
}

void BinaryTree::getRootValue(){
	std::cout << "The root value is: " <<root->key_value << std::endl;
}


void BinaryTree::commonAncestor(int key1, int key2, node *root){

   if( root == NULL ){
      return;
   } else {

       if( key1 > root->key_value && key2 < root->key_value ){
             std::cout << "Common ancestor is: " << root->key_value << std::endl;

       } else {
               commonAncestor(key1,key2, root->left);
               commonAncestor(key1,key2, root->right);

       }


   }

}

void BinaryTree::commonAncestor(int key1, int key2){

   this->commonAncestor(key1, key2, root);

}


void BinaryTree::inOrder(){
	this->inOrder(root);
}

void BinaryTree::inOrder(node *root){

	if(root != NULL){
		inOrder(root->left);
		std::cout << root->key_value << std::endl;
		inOrder(root->right);
	}

}

void BinaryTree::postOrder(node *root){


		if(root != NULL)
			postOrder(root->left);
		    postOrder(root->right);
		    std::cout << root->key_value << std::endl;

}

void BinaryTree::postOrder(){
	this->postOrder(root);
}
void BinaryTree::addNode(int key, node *leaf){

	if(key < leaf->key_value){
		if(leaf->left != NULL){
			addNode(key, leaf->left);
		} else {
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	} else if(key >= leaf->key_value){
		if(leaf->right != NULL)
			addNode(key, leaf->right);
		else {
		  leaf->right = new node;
		  leaf->right->key_value = key;
		  leaf->right->left  = NULL;
		  leaf->right->right = NULL;
		}
	}

}

void BinaryTree::insert(int key){
	if(root != NULL)
		this->addNode(key, root);
	else {
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void BinaryTree::preOrder(){


		this->preOrder(root);

}

void BinaryTree::preOrder(node *root){

	if(root != NULL){
		std::cout << root->key_value << std::endl;
		this->preOrder(root->left);
	    this->preOrder(root->right);
	}

}



void BinaryTree::printTree(node *leaf){

	if(root == NULL){
		return;
	} else {

	  if(leaf->left){
		  printTree(leaf->left);
	  }
	  if(leaf->right){
		  printTree(leaf->right);
	  }
	  std::cout << leaf->key_value << std::endl;


	}

}



int main(int argc, char **argv){

	BinaryTree *tree = new BinaryTree();



   std::cout << "[*] Creating tree and filling it" << std::endl;

   std::cout << "[*] Generating random integers" << std::endl;

   srand(time(NULL));


   std::cout << "[*] Finished" << std::endl;

   /**
    * insert data
    */


   for(int i = 0; i < 100; i++){

         tree->insert( rand() % 100 + 1);

    }

    tree->findElement(31);
    tree->commonAncestor(20, 25);
    tree->inOrder();


    // tree->preOrder();

   //  tree->postOrder();
	delete(tree);


}
