#include <stdio.h>

void mergeSortDescending(int left, int right, int array[]);
void mergeSortAscending(int left, int right, int array[]);
void printArray(int array[], int nElement);

int main() {
	int array[] = {10, 3, 4, 5, 8, 123, 12, 100, 1};
	int size = sizeof(array) / sizeof(array[0]);
	
	mergeSortAscending(0, size - 1, array);
	printf("Array after ascending sort: ");
	printArray(array, size);
	
	mergeSortDescending(0, size - 1, array);
	printf("\nArray after descending sort: ");
	printArray(array, size);	
	return 0;
}

void mergeSortDescending(int left, int right, int array[]){
	if(left >= right) return;
	int mid = left + (right - left) / 2;
	mergeSortDescending(left, mid, array);
	mergeSortDescending(mid + 1, right, array);
	
	int tempArray[right - left + 1];
	int tempIndex = 0;
	int leftIndex = left;
	int rightIndex = mid + 1;
	while(leftIndex <= mid && rightIndex <= right){
		if(array[leftIndex] > array[rightIndex]) tempArray[tempIndex++] = array[leftIndex++];
		else tempArray[tempIndex++] = array[rightIndex++];
	}
	
	while(leftIndex <= mid) tempArray[tempIndex++] = array[leftIndex++];
	for(int i = 0; i < tempIndex; i++) array[i + left] = tempArray[i];
}

// Sort Ascending
void mergeSortAscending(int left, int right, int array[]){
	if(left >= right) return;
	int mid = left + (right - left) / 2;
	
	mergeSortAscending(left, mid, array);
	mergeSortAscending(mid + 1, right, array);
	
	int tempArray[right - left + 1];
	int tempIndex = 0;
	int leftIndex = left;
	int rightIndex = mid + 1;
	while(leftIndex <= mid && rightIndex <= right){
		if(array[leftIndex] < array[rightIndex]) tempArray[tempIndex++] = array[leftIndex++];
		else tempArray[tempIndex++] = array[rightIndex++];
	}
	
	while(leftIndex <= mid) tempArray[tempIndex++] = array[leftIndex++];
	for(int i = 0; i < tempIndex; i++) array[i + left] = tempArray[i];
}

void printArray(int array[], int nElement) {
	for(int i = 0; i < nElement; i++) printf("%d ", array[i]);
}
