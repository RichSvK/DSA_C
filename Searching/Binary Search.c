#include <stdio.h>

int binary_Search(int array[], int left, int right, int find);
int binarySearch(int array[], int left, int right, int find);

int main() {
	int array[] = {1, 3, 4, 5, 7, 9, 11};
	int nElement = sizeof(array) / sizeof(array[0]);
	
	int find = 4;
	printf("Index of number %d is %d\n", find, binary_Search(array, 0, nElement - 1, find));
	
	find = 7;
	printf("Index of number %d is %d\n", find, binarySearch(array, 0, nElement - 1, find));
	return 0;
}

// Binary Search Using Recursion
int binary_Search(int array[], int left, int right, int find){
	int mid = left + (right - 1) / 2;
	if(left > right) return -1;
	if(array[mid] == find) return mid;
	else if(array[mid] > find) return binary_Search(array, left, mid - 1, find);
	else return binary_Search(array, mid + 1, right, find);
}

// Binary Search Using Loop (More efficient because no need to call more function to memory stack)
int binarySearch(int array[], int left, int right, int find){
	int mid;
	while(left <= right){
		mid = left + (right - left) / 2;
		if(array[mid] == find) return mid;
		else if(array[mid] > find) right = mid - 1;
		else if(array[mid] < find) left = mid + 1;
	}
	
	// Not found
	return -1;
}
