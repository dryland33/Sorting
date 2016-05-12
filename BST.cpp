/*
Project: Sorting Part 1
Programmer: Rylan Wassem
Date: 11/5/2014
*/
#include "BST.h"

//the tree constructor
BST::BST(){
	root = nullptr;
}

//a tree node
BST::node* BST::MakeNode(int data){
	node* mine_ode = new node;
	mine_ode->data = data;
	mine_ode->left = nullptr;
	mine_ode->right = nullptr;
	return mine_ode;
}

//for encapsulation: 
//calls a private function that accesses the root
void BST::AddNode(int data){
	p_AddNode(data, root);
}

void BST::p_AddNode(int data, node* node_ptr){

	//no root, start a new tree
	if (!root)
		root = MakeNode(data);

	//data less than or equal to node case:
	else if (data <= node_ptr->data){

		//does this node already have a left member?
		if (node_ptr->left)
			//if so make a recursive call 
			//until no left member is found  
			p_AddNode(data, node_ptr->left);

		else
			//found an empty spot, make a node
			node_ptr->left = MakeNode(data);
	}
	
	//data greater than node case:
	else if (data > node_ptr->data){

		//does this node already have a right member?
		if (node_ptr->right)
			//if so make a recursive call 
			//until no right member is found  
			p_AddNode(data, node_ptr->right);
		
		else
			//found an empty spot, make a node
			node_ptr->right = MakeNode(data);
	}
}

//private function, calls InOrd_Print
void BST::InOrd_Print(){
	p_InOrd_Print(root);
}

//prints the node's data members in order
void BST::p_InOrd_Print(node* node_ptr){
	//do we have a root?
	if (root){
		//does it have a left node?
		if (node_ptr->left)
			//recursive left subtree call
			p_InOrd_Print(node_ptr->left);
		//print current data member
		cout << node_ptr->data << '\n';
		//is there a right member?
		if (node_ptr->right)
			//recursive right subtree call
			p_InOrd_Print(node_ptr->right);
	}
	//quit barking up my tree!
	else cout << "No hay manzanas en este arbol! \n";
}

//private function, calls InOrd_Assign
void BST::InOrd_Asign(vector<int>& my_vect){
	p_InOrd_Asign(root, my_vect);
}

//assings the node's data members to a vector in order
void BST::p_InOrd_Asign(node* node_ptr, vector<int>& my_vect){
	//do we have a root?
	if (root){
		//does it have a left node?
		if (node_ptr->left)
			//recursive left subtree call
			p_InOrd_Asign(node_ptr->left, my_vect);
		//assign current data member
		my_vect.push_back(node_ptr->data);
		//is there a right member?
		if (node_ptr->right)
			//recursive right subtree call
			p_InOrd_Asign(node_ptr->right, my_vect);
	}
}

//calls the function with root access
BST::node* BST::Ret_Node(int data){
	return p_Ret_Node(data, root);
}

//helper function that finds a node containg a specicic value
BST::node* BST::p_Ret_Node(int data, node* node_ptr){
	//check for a node
	if (node_ptr){ 
		//if this is what we need return it
		if (node_ptr->data == data)
			return node_ptr;
		//check the left tree recursively
		else if (data < node_ptr->data)
			return p_Ret_Node(data, node_ptr->left);
		//check the right tree recursively
		else return p_Ret_Node(data, node_ptr->right);
	}
	//give up and go home
	else return nullptr;
}

int BST::Ret_RootData(){
	if (root)
		return root->data;
	//arbitrary int for not found
	else return 0xFFFFFF;
}

void  BST::KidsPrint(int data){

	//find the node associated with the data
	node* node_ptr = Ret_Node(data);

	if (node_ptr){
		//print parent
		cout << "Parent: " << node_ptr->data << endl;
		//print left
		node_ptr->left ? cout << "Left Kid: " << node_ptr->left->data << endl : cout << "null left\n";
		//print right
		node_ptr->right ? cout << "Right Kid: " << node_ptr->right->data << endl : cout << "null right\n";
	}
	else cout << data << " not found\n";
}

