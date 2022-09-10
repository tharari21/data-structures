#include <iostream>
int main() {
	// Declare an array with fixed size
	int arr[5];
	// Assign values
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	
	// Declare an array with fixed length and assign values. All indices after 2 in this cass will be initialized at 0
	int arr2[10] = {2,4,5};
	// This is 0 since we didn't initialize it
	std::cout << arr2[5];
	// Declare and initialize an array. Length is still fixed but cpp takes the length of the passed array
	int arr3[] = {1,2,3,4,5};

	
}
