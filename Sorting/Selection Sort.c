#include <stdio.h>

void selectionSortAscending(int array[], int nElement);
void selectionSortDescending(int array[], int nElement);
void printArray(int array[], int nElement);

int main() {
	int array[] = {2, 8, 5, 3, 9, 4, 1};
	int nElement = (sizeof(array) / sizeof(array[0]));
	
	selectionSortAscending(array, nElement);
	printf("Array after ascending sort: ");
	printArray(array, nElement);
	
	selectionSortDescending(array, nElement);
	printf("\nArray after descending sort: ");
	printArray(array, nElement);
	return 0;
}

void selectionSortAscending(int array[], int nElement){
	for(int i = 0; i < nElement - 1; i++){
		int minIndex = i;
		for(int j = i + 1; j < nElement; j++){
			if(array[minIndex] > array[j]) {
				minIndex = j;
			}			
		}
		
		// Swap
		if(minIndex != i){
			int temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}	
}

void selectionSortDescending(int array[], int nElement){
	for(int i = 0; i < nElement - 1; i++){
		int maxIndex = i;
		for(int j = i + 1; j < nElement; j++){
			if(array[maxIndex] < array[j]) {
				maxIndex = j;
			}			
		}
		
		// Swap
		if(maxIndex != i){
			int temp = array[i];
			array[i] = array[maxIndex];
			array[maxIndex] = temp;
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
