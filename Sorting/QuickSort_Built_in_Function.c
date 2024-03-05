#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compareFunction(const void* a, const void* b);
int compareFunction_2(const void* a, const void* b);
void printArray(char* array[], int nElement);

int main(){
	char* array[] = {"AB", "AA", "AAC", "BA", "BB", "BC"};
	int size = sizeof(array) / sizeof(array[0]);

	// Built in function from stdlib.h
	// Ascending
	qsort(array, size, sizeof(array[0]), compareFunction);
	printf("Array after ascending sort: ");
	printArray(array, size);
	
	// Descending
	qsort(array, size, sizeof(array[0]), compareFunction_2);
	printf("\nArray after descending sort: ");
	printArray(array, size);
	return 0;
}

int compareFunction(const void* a, const void* b){
	char* A = *((char**)a);
	char* B = *((char**)b);
	return strcmp(A, B);
}

int compareFunction_2(const void* a, const void* b){
	char* A = *((char**)a);
	char* B = *((char**)b);
	return strcmp(B, A);
}

void printArray(char* array[], int nElement){
	printf("[");
	for(int i = 0; i < nElement; i++){
		if(i == (nElement - 1)) printf("%s", array[i]);
		else printf("%s, ", array[i]);
	}
	printf("]");
}
