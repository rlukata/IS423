/**
* 1. find middle position of array
* 2. determine whether element searched is bigger, smaller, or equal than element found in middle three conditions
*	a. if equal, return position of middle
*	b. If bigger, element must reside in right half of array ==> take right half array
*	c. if smaller, element must reside in left half of array ==> take left half array
* 3. take chosen half, and repeat process
*
* This process can be made recursive, by making 2.b or 2.c call the function
*/

#include <iostream>

using namespace std;

//recursive function
int binarySearch(int arr[], int length, int position, int value) {
	// position can’t be negative
	if (position >= length) {
		// determine the position of middle
		int middle = length + (position - length)/2;

		// if the element is in the middle return the position middle
		if (arr[middle] == value) return middle;

		// if element is smaller than middle, then it’s in the left half
		if (arr[middle] > value) return binarySearch(arr, length, middle-1, value);
		
		// Else the element can only be present in right half
		return binarySearch(arr, middle+1, position, value);
	}
	// We reach here when element is not present in array
	return -1;
}

int main(void) { 
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
	int length = sizeof(arr)/ sizeof(arr[0]); 
	int value = 8; 
	int result = binarySearch(arr, 0, length-1, value); 
	if (result == -1) cout << "Element is not present in array" << endl;
	else cout << "Element is present at index " << result;
}