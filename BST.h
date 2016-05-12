/*
Project: Sorting Part 1
Programmer: Rylan Wassem
Date: 11/5/2014
*/

#ifndef BST_HICKORY_H
#define BST_HICKORY_H

using namespace std;
#include <iomanip>      
#include <time.h>
#include <vector>
#include <iostream>
#include <cstdlib>

class BST{
private:

	struct node{
		int data;
		node* left;
		node* right;
	};

	node* root;
	void p_AddNode(int, node*);
	void p_InOrd_Print(node*);
	void p_InOrd_Asign(node*, vector<int>&);
	node* p_Ret_Node(int, node*);

public:

	BST();
	node* MakeNode(int);
	void AddNode(int);
	void InOrd_Print();
	void InOrd_Asign(vector<int>&);
	node* Ret_Node(int);
	int Ret_RootData();
	void KidsPrint(int);
};

#endif // !1