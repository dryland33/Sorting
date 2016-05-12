#include "AllSorts.h"
#include <cstdlib>
#include <iostream> 
#include <iomanip>  
#include <fstream> 
#include <sstream> 
#include <ctime> 
using namespace std;

int findMedian(vector<int>&, int);

clock_t start_time;
clock_t end_time;

//usage: (window size, sourcefile, destination file)
int main(/*int argc, char *argv[]*/) {
	int x[] = { 9, 9, 9, 9, 13, 13, 13, 13, 19, 19, 19, 19 };
	for (int run_times(0); run_times < 12; run_times++){

		int row(0), column(0), numb_rows(0), numb_cols(0), side_len(/*atoi(argv[1])*/x[run_times]);
		ifstream infile(/*argv[2]*/ "bears.pgm");
		string filename = "bears_file_" + to_string(run_times) + ".pgm";
		ofstream outfile(/*argv[3]*/filename);
		stringstream cuyahoga;
		string in_line("");

		//read and write "P2"
		getline(infile, in_line);
		outfile << in_line << endl;

		//read and write filename comment
		getline(infile, in_line);
		outfile << in_line << endl;

		//read, store, and write dimensions
		getline(infile, in_line);
		istringstream buffer(in_line);
		buffer >> numb_cols >> numb_rows;
		outfile << numb_cols << ' ' << numb_rows << endl;

		//read and write max grey value
		getline(infile, in_line);
		outfile << in_line << endl;

		//put everything else in this string stream
		cuyahoga << infile.rdbuf();

		//declare a 2D array to store the source values 
		int **array = new int*[numb_rows];
		for (int i = 0; i < numb_rows; ++i)
			array[i] = new int[numb_cols];

		//declare a 2D array to store the output values 
		int **new_array = new int*[numb_rows];
		for (int i = 0; i < numb_rows; ++i)
			new_array[i] = new int[numb_cols];

		//move the data from the stream to the source array
		for (row = 0; row < numb_rows; ++row)
			for (column = 0; column < numb_cols; ++column)
				cuyahoga >> array[row][column];

		vector<int> my_vect;
		const int radius = side_len / 2;

		start_time = clock();
		//populate the new_array with median values
		for (row = 0; row < numb_rows; ++row){
			for (column = 0; column < numb_cols; ++column){
				//add pixels to a vector
				for (int i = (row - radius); i <= (row + radius); ++i){
					for (int j = (column - radius); j <= (column + radius); ++j){
						if (i >= 0 && j >= 0 && i < numb_rows && j < numb_cols)
							my_vect.push_back(array[i][j]);
					}
				}

				new_array[row][column] = findMedian(my_vect, run_times % 3);
				my_vect.clear();
			}
		}
		end_time = clock();

		//write everything to the new file
		for (row = 0; row < numb_rows; ++row) {
			for (column = 0; column < numb_cols; ++column) {
				outfile << setw(3) << new_array[row][column] << " ";
			}
			outfile << endl;
		}

		switch (run_times % 4){
		case 0:
			cout << "bst sort: \n" << filename << endl;
			break;
		case 1:
			cout << "merge sort: \n" << filename << endl;
			break;
		case 2:
			cout << "quick sort: \n" << filename << endl;
			break;
		case 3:
			cout << "heap sort: \n" << filename << endl;
			break;
		}
		cout << (end_time - start_time) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl << endl;

		//call housekeeping
		infile.close();
		outfile.close();

		for (int i = 0; i < numb_rows; ++i) {
			delete[] array[i];
		}
		delete[] array;

		for (int i = 0; i < numb_rows; ++i) {
			delete[] new_array[i];
		}
		delete[] new_array;
	}
	cin.get();
}

/*returns the middle index in a sorted vector*/
int findMedian(vector<int>& rand_nums, int n){
	//arguments for merge sort
	vector<int> temp_nums;
	int l(0);
	int r(0);

	switch (n){
	case 0:
		BST_sort(rand_nums);
		break;
	case 1:
		temp_nums.resize(rand_nums.size());
		mergesort(rand_nums, temp_nums, l, r);
		break;
	case 2:
		quicksort(rand_nums, l, r);
		break;
	case 3:
		heapsort(rand_nums);
		break;
	}
	return rand_nums[rand_nums.size() / 2];
}

