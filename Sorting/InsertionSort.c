#include<stdio.h>

void insertionSortAscending(int array[], int nElement);
void insertionSortDescending(int array[], int nElement);
void printArray(int array[], int nElement);

int main(){
	int array[] = {5, 6, 3, 4, 2, 1, 0};
	int nElement = sizeof(array) / sizeof(array[0]);
	
	// Ascending
	insertionSortAscending(array, nElement);
	printf("Array after ascending sort: ");
	printArray(array, nElement);
	
	// Desending
	insertionSortDescending(array, nElement);
	printf("\nArray after descending sort: ");
	printArray(array, nElement);
	return 0;
}


void insertionSortAscending(int array[], int nElement){
	int i, j, temp;
	for(i = 1; i < nElement; i++){
		temp = array[i];
		j = i - 1;
		while(j >= 0 && array[j] > temp){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}	
}

void insertionSortDescending(int array[], int nElement){
	int i, j, temp;
	for(i = 1; i < nElement; i++){
		temp = array[i];
		j = i - 1;
		while(j >= 0 && array[j] < temp){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
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
