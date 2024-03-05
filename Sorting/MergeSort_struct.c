#include<stdio.h>
#include<string.h>

struct Student{
	int number;
	char name[21];
};

void mergeSortByString(int left, int right, struct Student array[]);
void mergeSortByInt(int left, int right, struct Student array[]);

int main(){
	struct Student listStudent[3] ={
		{1, "Richard"},
		{3, "Bob"},
		{2, "Alfa"}
	};
	
	int size = sizeof(listStudent) / sizeof(listStudent[0]);
	puts("listStudent after sort ascending by name:");
	mergeSortByString(0, size - 1, listStudent);
	for(int i = 0; i < size; i++) printf("%d %s\n", listStudent[i].number, listStudent[i].name);
	
	puts("\nlistStudent after sort ascending by number:");
	mergeSortByInt(0, size - 1, listStudent);
	for(int i = 0; i < size; i++) printf("%d %s\n", listStudent[i].number, listStudent[i].name);
	return 0;
}

void mergeSortByString(int left, int right, struct Student array[]){
	if(left >= right) return;
	int mid = (left + right) / 2;
	mergeSortByString(left, mid, array);
	mergeSortByString(mid + 1, right, array);
	
	struct Student tempArray[right - left + 1];
	int tempIndex = 0;
	int leftIndex = left;
	int rightIndex = mid + 1;
	while(leftIndex <= mid && rightIndex <= right){
		if(strcmp(array[leftIndex].name, array[rightIndex].name) < 0) tempArray[tempIndex++] = array[leftIndex++];
		else tempArray[tempIndex++] = array[rightIndex++];
	}
	
	while(leftIndex <= mid) tempArray[tempIndex++] = array[leftIndex++];
	for(int i = 0; i < tempIndex; i++) array[i + left] = tempArray[i];
}

void mergeSortByInt(int left, int right, struct Student array[]){
	if(left >= right) return;
	int mid = (left + right) / 2;
	mergeSortByInt(left, mid, array);
	mergeSortByInt(mid + 1, right, array);
	
	struct Student tempArray[right - left + 1];
	int tempIndex = 0;
	int leftIndex = left;
	int rightIndex = mid + 1;
	while(leftIndex <= mid && rightIndex <= right){
		if(array[leftIndex].number < array[rightIndex].number) tempArray[tempIndex++] = array[leftIndex++];
		else tempArray[tempIndex++] = array[rightIndex++];
	}
	
	while(leftIndex <= mid) tempArray[tempIndex++] = array[leftIndex++];
	for(int i = 0; i < tempIndex; i++) array[i + left] = tempArray[i];
}
