#include<stdio.h>

int linearSearch(int array[], int find);

int main(){
	int array[] = {3, 1, 2, 4, 5, 10, 20};
	int nElement = sizeof(array) / sizeof(array[0]);

	int find = 1;
	printf("Index of number %d is %d\n", find, linearSearch(array, nElement, find));
	return 0;
}

int linearSearch(int array[], int nElement, int find){
	for(int i = 0; i < nElement; i++){
		if(array[i] == find) return i;
	}
	// Number not found
	return -1;
}
