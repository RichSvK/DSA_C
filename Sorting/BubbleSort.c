#include <stdio.h>

void bubbleSortAscending(int array[], int nElement);
void bubbleSortDescending(int array[], int nElement);
void printArray(int array[], int nElement);

int main() {
	int array[] = {7, 1, 3, 9, 0, 2, 4, 5, 8};
	int nElement = (sizeof(array) / sizeof(array[0]));
	
	// Ascending
	bubbleSortAscending(array, nElement);
	printf("Array after ascending sort: ");
	printArray(array, nElement);
	
	// Desending
	bubbleSortDescending(array, nElement);
	printf("\nArray after descending sort: ");
	printArray(array, nElement);
	return 0;
}

void bubbleSortAscending(int array[], int nElement){
	nElement -= 1;
	int temp;
	for(int i = 0; i < nElement; i++){
		for(int j = 0; j < nElement - i; j++){
			// Swap
			if(array[j] > array[j + 1]){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}			
		}
	}
}

void bubbleSortDescending(int array[], int nElement){
	nElement -= 1;
	int temp;
	for(int i = 0; i < nElement; i++){
		for(int j = 0; j < nElement - i; j++){
			// Swap
			if(array[j] < array[j + 1]){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}			
		}
	}
}

void printArray(int array[], int nElement){
	printf("[");
	for(int i = 0; i < nElement; i++){
		if(i == (nElement - 1)) printf("%d", array[i]);
		else printf("%d, ", array[i]);
	}
	printf("]");
}
