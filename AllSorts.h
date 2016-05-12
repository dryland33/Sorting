/*
Project: Sorting Part 1
Programmer: Rylan Wassem
Date: 11/5/2014

Description:

Four sorting methods that take
a vector of unsorted integers
and return a vector of sorted integers

Methods:

Binary Search Tree
Merge Sort
Quick Sort
Heap Sort

A function that takes a sorted vector of ints and returns the median int

A test function to check if a vector is sorted
*/

#ifndef HAIRYSYPHLITICELEPHANTITISGOITERNUTSACK

#define HAIRYSYPHLITICELEPHANTITISGOITERNUTSACK

#include "BST.h"

namespace{

	void BST_sort(vector <int>&);

	void mergesort(vector <int>&, vector <int>, int, int);

	void quicksort(vector <int>&, int, int);
	int partition(vector <int>&, int, int);

	void heapsort(vector <int>&);
	void heapify(vector<int>&, int);
	void sift_down(vector<int>&, int, int);

	int median(vector <int>);
	bool is_sorted(vector <int>);

	void BST_sort(vector <int>& unsort){
		//make a binary search tree
		BST bs_tree;
		//add the unsorted vector's values to the  tree
		for (int i(0); i < unsort.size(); i++)
			bs_tree.AddNode(unsort[i]);
		//reassign an in order traversal to the vector
		vector <int> sorted;
		bs_tree.InOrd_Asign(sorted);
		unsort = sorted;
	}

	void mergesort(vector <int>& unsort, vector <int> temp, int left, int right){
		//base case: a single element
		if (left == right) return; 
		int middle = (left + right) / 2;

		//recursive call on left half
		mergesort(unsort, temp, left, middle);
		//recursive call on right half
		mergesort(unsort, temp, middle + 1, right);

		//copy to temp
		for (int i(left); i <= right; i++)
			temp[i] = unsort[i];

		//merging
		int m(left);
		int n(middle + 1);
		for (int i(left); i <= right; i++){
			if (m == middle + 1)//end of left list
				unsort[i] = temp[n++];
			else if (n > right)//end of right list
				unsort[i] = temp[m++];
			else if (temp[m] <= temp[n])
				unsort[i] = temp[m++];
			else unsort[i] = temp[n++];
		}
	}

	void quicksort(vector <int>& unsort, int front, int back){
		//if back is less than front nothing's left to sort
		if (front < back){
			//get the pivot
			int pivot_index = partition(unsort, front, back);
			// Sort left subarray
			quicksort(unsort, front, pivot_index - 1);
			// Sort right subarray
			quicksort(unsort, pivot_index + 1, back);
		}
		return;
	}

	int partition(vector <int>& unsort, int front, int back){
		//initalize pivot to last element
		int pivot = unsort[back];
		//compare starting at other end
		int curdex = front;
		for (int i(front); i < back; i++){
			//put the small things on the left
			if (unsort[i] <= pivot){
				swap(unsort[i], unsort[curdex]);
				++curdex;
			}
		}
		//pivot goes in the middle
		swap(unsort[curdex], unsort[back]);
		return curdex;
	}

	void heapsort(vector <int>& unsort){

		int count = unsort.size();

		//build the heap in unsort so that largest value is at the root 
		heapify(unsort, count);

		//start at last index
		int back = count - 1;

		while (back > 0){
			//unsort[0] is the root and largest value. 
			//swap() moves it in front of the sorted elements.
			swap(unsort[back], unsort[0]);
			//reduce heap size by one
			back--;
			//restore the heap 
			sift_down(unsort, 0, back);
		}
	}

	void heapify(vector<int>& unsort, int count){
		
		//the parent of the last element
		int start = (count - 2) / 2;

		while (start >= 0){
			sift_down(unsort, start, count - 1);
			//go to the next parent node
			start--;
		}
	}

	void sift_down(vector<int>& unsort, int front, int back){
		int root = front;
		//while the root has at least one child
		while (root * 2 + 1 <= back){
			//left child
			int child = (root * 2) + 1;
			//keeps track of child to swap with
			int swp = root;
			if (unsort[swp] < unsort[child])
				swp = child;
			//is a right child greater?
			if (child + 1 <= back && unsort[swp] < unsort[child + 1])
				swp = child + 1;
			if (swp != root){
				swap(unsort[root], unsort[swp]);
				root = swp;
			}
			else
				return;
		}
	}

	int median(vector <int> med_vec){
		//if there is no middle
		if (med_vec.size() % 2)
			//the sum of the two center elements divided by 2
			return (med_vec[med_vec.size() / 2] + med_vec[med_vec.size() / 2 + 1]) / 2;
		else
			return (med_vec[med_vec.size() / 2 + 1]); //the unique center
	}

	bool is_sorted(vector <int> test_vec){
		//compares each two consecutive indices
		for (int i(0); i < test_vec.size() - 1; i++){
			if (test_vec[i] > test_vec[i + 1])
				//if we find a bigger one on the left
				return false;
		}
		//all good
		return true;
	}

}

#endif // !HAIRYSYPHLITICELEPHANTITISGOITERNUTSACK