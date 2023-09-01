/* ASSUMPTIONS:
1. When a node must be split and has an odd number of keys, the extra key will go to the new right-hand node.
2. There will never be a duplicate key passed to insert.
*/

#include <vector>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

#ifndef DS_BPLUSTREE
#define DS_BPLUSTREE

///////////////////////////////////////////////////////////////////////////////
//DO NOT CHANGE THIS CODE
///////////////////////////////////////////////////////////////////////////////

//Do not implement the class here, this is a forward declaration. Implement at
//the bottom of the .h file
template <class T> class BPlusTree; 

template <class T>
class BPlusTreeNode{
public:
	BPlusTreeNode() : parent(NULL) {};
	bool is_leaf();
	bool contains(const T& key);

	//For grading only. This is bad practice to have, because
	//it exposes a private member variable.
	BPlusTreeNode* get_parent() { return parent; } 

	//We need this to let BPlusTree access private members
	friend class BPlusTree<T>; 
private:
	bool contains(const T& key,std::size_t low,std::size_t high);
	std::vector<T> keys;
	std::vector<BPlusTreeNode*> children;
	BPlusTreeNode* parent;
};

template <class T>
bool BPlusTreeNode<T>::is_leaf(){
	//return this->children.size() == 0;
	for(unsigned int i=0; i<this->children.size(); i++){
		if(this->children[i]){
			return false;
		}
	}
	return true;
}

template <class T>
bool BPlusTreeNode<T>::contains(const T& key){
	return contains(key,0,keys.size()-1);
}

//Private method takes advantage of the fact keys are sorted
template <class T>
bool BPlusTreeNode<T>::contains(const T& key,std::size_t low,std::size_t high){
	if(low>high){
		return false;
	}
	if(low==high){
		return key == keys[low];
	}
	std::size_t mid = (low+high)/2;
	if(key<=keys[mid]){
		return contains(key,0,mid);
	}
	else{
		return contains(key,mid+1,high);
	}
}

///////////////////////////////////////////////////////////////////////////////////////
//Your BPlusTree implementation goes below this point.
///////////////////////////////////////////////////////////////////////////////////////

template <class T> class BPlusTree; 


template <class T> class BPlusTree {
public:
	//need constructors
	BPlusTree<T>(int b) {
		degree = b; 
		root = NULL;
	}




	BPlusTree<T>(BPlusTree<T>& other) { //copy constructor
	degree = other.degree;
	root = NULL;
	for (unsigned int i = 0; i < other.insertorder.size(); i++) {
		insert(other.insertorder[i]);
		}
	}
 

 

	BPlusTree<T>& operator=(BPlusTree<T>& copytree) { //= operator  to copy a tree
		if (this != &copytree) {
			destroytree(root);
			degree = copytree.degree;
			root = NULL;
		for (unsigned int i = 0; i < copytree.insertorder.size(); i++) {			
			insert(copytree.insertorder[i]);
			}
		}
		return *this;
	} 




	~BPlusTree<T>() { //destructor
		//releases memory
		destroytree(root);
		return;
	}
	void destroytree(BPlusTreeNode<T>* node) { //helper function to destructor
		if (node == NULL) {
			return;
		}

		for (unsigned int i = 0; i < node->children.size(); i++) {
			destroytree(node->children[i]);
		}

		delete node;

	}




	BPlusTreeNode<T>* find(T key, BPlusTreeNode<T>* node) {	//helper function to find		
	// basecase1
	if (node == NULL) {
		return NULL;
	}
		
	// basecase2
	if (node->is_leaf()) {
		return node;
	}

	for (unsigned int i=0; i< node->keys.size(); i++) {				
		if (key < node->keys[i]) { 
			return find(key, node->children[i]);
		}
	}
	//if greater than the last element
	return find(key, node->children[node->children.size()-1]);
	}


	BPlusTreeNode<T>* find(T key) { //find function
		return find(key,root);
	}	





	void recursivesplit(BPlusTreeNode<T>* node) {
		if (node->keys.size() < degree) {
				return;
		}

		if (node->is_leaf()) {
			BPlusTreeNode<T>* new_node = new BPlusTreeNode<T>;
			for(int i = node->keys.size()/2; i < node->keys.size(); ++i){ //add new keys to new node
				new_node->keys.push_back(node->keys[i]);

			}
			typename std::vector<T>::value_type midpt = node->keys[node->keys.size() / 2];
			int size = node->keys.size();
			for (int i = size/2; i < size; i++){	//eliminate from old node keys
				node->keys.pop_back();
			}

			if (node != root) { 
				typename std::vector<BPlusTreeNode<T>*>::iterator it; //inserting into chlidren of parent
				it = std::find(node->parent->children.begin(), node->parent->children.end(), node);	 
				node->parent->children.insert(++it, new_node); //inserts new child
				new_node->parent = node->parent; //makes the parent of new node 
				unsigned int i = 0; //insert into the parent
				for (; i < node->parent->keys.size(); i++) {	//get position to insert in parent
					if (midpt < node->parent->keys[i]) { //addedparent inserting into parent 
						break;
					}
				}
				
				node->parent->keys.insert(node->parent->keys.begin() + i, midpt); //insert into parent
			}
			else {	//assign new parent if we split and is root/leaf
				BPlusTreeNode<T>* newroot = new BPlusTreeNode<T>;
				newroot->keys.push_back(midpt);
				newroot->children.push_back(node);
				newroot->children.push_back(new_node);
				root = newroot;
				node->parent = root;
				new_node->parent = root;

			}

		}
		else {

			BPlusTreeNode<T>* new_node = new BPlusTreeNode<T>;				//insert keys into new node
			for(int i = node->keys.size()/2+1; i < node->keys.size(); ++i){
				new_node->keys.push_back(node->keys[i]);

			}
			typename std::vector<T>::value_type midpt = node->keys[node->keys.size() / 2]; //remove keys from old node
			int size = node->keys.size();
			for (int i = size/2; i < size; i++){
				node->keys.pop_back();
			}

			std::vector<BPlusTreeNode<T>*>child = node->children; //copying the children of root node
			node->children.clear(); //clear old children to split into two nodes children
			for (unsigned int i = 0; i < child.size(); i++) { 
				if (i < node->keys.size()/2+2) {
					node->children.push_back(child[i]);
					node->children.back()->parent = node;
				}
				else {
					new_node->children.push_back(child[i]);
					new_node->children.back()->parent = new_node;
				}
			}
			if (node != root) {	
				typename std::vector<BPlusTreeNode<T>*>::iterator it;
				it = std::find(node->parent->children.begin(), node->parent->children.end(), node);
				node->parent->children.insert(++it, new_node);
				new_node->parent = node->parent;
				unsigned int i = 0; //insert into the parent
				for (; i < node->parent->keys.size(); i++) {
					if (midpt < node->keys[i]) {
						break;
					}
				}
				node->parent->keys.insert(node->parent->keys.begin() + i, midpt);
				if (node->parent->keys.size() == degree) {
					recursivesplit(node->parent);
				}
			}
			else {
				BPlusTreeNode<T>* newroot = new BPlusTreeNode<T>;
				newroot->keys.push_back(midpt);
				newroot->children.push_back(node);
				newroot->children.push_back(new_node);
				root = newroot;
				node->parent = root;
				new_node->parent = root;
			}
		}
	}	


		
	void insert(T key, BPlusTreeNode<T>*& node) { 
		insertorder.push_back(key); //gotta eliminate dupes

		if (node == NULL) { //basecase 1
			// if node is NULL, create a new node and make it the root
			node = new BPlusTreeNode<T>;
			node->keys.push_back(key);
			root = node;
			return;
		}

		if (node->is_leaf()) { //basecase 2 if node is a leaf, insert the key in sorted order
			unsigned int i = 0;
			for (; i < node->keys.size(); i++) { 
				if (key < node->keys[i]) {
					break;
				}
			}
			node->keys.insert(node->keys.begin() + i, key); //inserting into keys
			if (node->keys.size() == degree) {
				// if the leaf is full, split it
				recursivesplit(node);
				
			}
		} 
		else {
			// if node is not a leaf, recursively insert the key into the appropriate child node
			unsigned int i = 0;
			for (; i < node->keys.size(); i++) {
				if (key < node->keys[i]) {
					break;
				}
			}
			insert(key, node->children[i]);
			if (node->keys.size() == degree) { 
				recursivesplit(node);
			}
		}
	}

	void insert(T key) { //call from the main function
		insert(key, root);
	}

	void print_sideways(std::ofstream& outfile, BPlusTreeNode<T>* node, int level) {
		if (node) {
			for (unsigned int i = 0; i < node->children.size()/2;i++) {
      			print_sideways(outfile, node->children[i], level+1);
			}
    		for (int i=0; i<level; ++i) outfile << "\t";
				for (unsigned int i = 0; i < node->keys.size()-1; i++) {
					outfile<<node->keys[i]<<",";
				}
				outfile<<node->keys.back() <<std::endl;
			for (unsigned int i = node->children.size()/2; i < node->children.size(); i++ ) {
      			print_sideways(outfile, node->children[i], level+1);
			}
    	}
	}

	void print_sideways(std::ofstream& outfile) {
//print sideways like the lab
		if (root == NULL) {
			outfile<<"Tree is empty."<<std::endl;
		}
		else {
		print_sideways(outfile, root, 0);
		}
		return;
	}


void print_BFS(BPlusTreeNode<T>* node, std::ofstream& outfile) {
	std::vector<BPlusTreeNode<T>*>current;
	std::vector<BPlusTreeNode<T>*>next;
	current.push_back(node);

	while(!current.empty()){
		for(int i=0; i<current.size(); i++){

			for(int j=0; j<current[i]->children.size(); j++)
				next.push_back(current[i]->children[j]);
			
			for (unsigned int j = 0; j < current[i]->keys.size()-1;j++) {
				outfile<<current[i]->keys[j]<<",";
			}
			outfile<<current[i]->keys.back();
			if (i != current.size()-1){
				outfile<<"\t";
			}
			
		}
		outfile<<std::endl;

		current = next;
		next.clear();
	}
	
}

void print_BFS(std::ofstream& outfile) {
    if (root == nullptr) {
        outfile << "Tree is empty." << std::endl;
        return;
    }
	print_BFS(root, outfile);

}


private:
	int degree;
	BPlusTreeNode<T>* root;
	std::vector<T>insertorder;


};


#endif
