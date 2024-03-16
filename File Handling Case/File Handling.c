#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Node with single linked list data structure
struct Student{
	unsigned int age;
	char* name;
	char* major;
	struct Student* next;
};

// For responsive table if the inserted data length is longer than the current width
struct TableStudentWidth{
	unsigned int noWidth;
	unsigned int ageWidth;
	unsigned int nameWidth;
	unsigned int majorWidth;
};

// Global Variable
struct Student* head = NULL;
struct Student* tail = NULL;
struct TableStudentWidth table;
unsigned int nData = 0;

// Function Prototype
void initializeWidth();
void updateTableWidth(unsigned int age, char name[], char major[]);
void readFile();
int mainMenu();
void addStudent();
void insert(struct Student* newNode);
void printStudent();
void deleteStudent();
void showStudentInfo(struct Student* node);
void save();

int main() {
	initializeWidth();
	int choice = 0;
	readFile();
	do{
		choice = mainMenu();
		switch(choice){
			case 1:
				addStudent();
				break;
				
			case 2:
				printStudent();
				break;

			case 3:
				deleteStudent();
				break;
			
			default:
				save();
				puts("Program Finished");
				return 0;				
		}
		printf("Press [Enter] to Continue...");
		getchar();
		
		// Flush input stream from stdin
		fflush(stdin);
	} while(choice != 4);
}

// Main Menu Function
int mainMenu(){
	int choice = 0;
	int valid = 1;
	char end = '\0';
	do{
		system("cls");
		puts("Main Menu");
		puts("1. Insert Data");
		puts("2. Print Data");
		puts("3. Delete Data");
		puts("4. Exit");
		printf(">> ");
		
		// If input is valid (integer), scanf will return 1 to valid
		valid = scanf("%d%c", &choice, &end);
		if(end != '\n') valid = 0;
		fflush(stdin);
	} while(valid == 0 || choice < 1 || choice > 4);
	return choice;
}

// Initialize table width
void initializeWidth(){
	// Table
	table.noWidth = strlen("No.");
	table.ageWidth = strlen("Age");
	table.nameWidth = strlen("Name");
	table.majorWidth = strlen("Major");
}

// Function to create node
struct Student* createNode(unsigned int age, char name[], char major[]){
	struct Student* newNode = (struct Student*) malloc(sizeof(struct Student));
	if(newNode == NULL){
		puts("Failed to allocate memory");
		return NULL;
	}
	newNode->age = age;
	newNode->name = (char*) malloc(sizeof(strlen(name)) + 1);
	newNode->major = (char*) malloc(sizeof(strlen(major)) + 1);
		
	if(newNode->name == NULL || newNode->major == NULL){
		printf("Failed to allocate memory");
		return NULL;
	}
	strcpy(newNode->name, name);
	strcpy(newNode->major, major);
	newNode->next = NULL;

	nData++;
	updateTableWidth(age, name, major);
	return newNode;
}

// Function to show Menu to add student
void addStudent(){
	char nameBuffer[201] = {'\0'};
	char majorBuffer[101] = {'\0'};
	unsigned int temp = 0;
	do{
		printf("Input name [1 - 200 Length]: ");
		scanf("%[^\n]", nameBuffer);
		getchar();
		temp = strlen(nameBuffer);
	} while(temp < 1 || temp > 200);
	
	do{
		printf("Input major [1 - 100 Length]: ");
		scanf("%[^\n]", majorBuffer);
		getchar();
		temp = strlen(majorBuffer);
	} while(temp < 1 || temp > 200);
	
	unsigned int age = 0;
	char end = '\n';
	do{
		printf("Input age: ");
		temp = scanf("%u%c", &age, &end);
		if(end != '\n') temp = 0;	
		fflush(stdin);
	} while(temp == 0 || age < 0 || age > 150);
	
	struct Student* newNode = createNode(age, nameBuffer, majorBuffer);
	if(newNode == NULL) {
		puts("Failed to insert data");
		return;
	}
	
	insert(newNode);
}

// Function to read file
void readFile(){
	FILE* fRead = fopen("Data/students.txt", "r");
	if(fRead == NULL){
		puts("There is no file");
		return;
	}
	
	char nameBuffer[200] = {'\0'};
	char majorBuffer[200] = {'\0'};
	unsigned int age = 0;
	
	// Skip header column
	fscanf(fRead, "%[^\n]\n", nameBuffer);
	struct Student* newNode = NULL;
	while(!feof(fRead)){		
		fscanf(fRead, "%[^;];%u;%[^\n]\n", nameBuffer, &age, majorBuffer);
		newNode = createNode(age, nameBuffer, majorBuffer);
		// If newNode is NULL then malloc failed to allocate memory
		if(newNode != NULL) insert(newNode);
	}
	fclose(fRead);
	return;
}

// Function to update table width
void updateTableWidth(unsigned int age, char name[], char major[]){
	// Update number width
	unsigned int width = 0;
	int temp = nData;
	while(temp != 0){
		temp /= 10;
		width++;
	}
	if(table.noWidth < width) table.noWidth = width;
	
	// Update Name Width
	width = strlen(name);
	if(table.nameWidth < width) table.nameWidth = width;
	
	
	// Update Age length
	width = 0;
	temp = age;
	while(temp != 0){
		temp /= 10;
		width++;
	}
	if(table.ageWidth < width) table.ageWidth = width;
	
	// Update Major length
	width = strlen(major);
	if(table.majorWidth < width) table.majorWidth = width;
}

// Function to insert node
void insert(struct Student* newNode){
	if(head == NULL){
		head = tail = newNode;
		return;
	}
	
	// Sort node ascending by age
	if(newNode->age >= tail->age) {
		// Push Tail
		tail->next = newNode;
		tail = newNode;		
	} else if(newNode->age <= head->age){
		// Push head
		newNode->next = head;
		head = newNode;
	} else{
		struct Student* curr = head;
		while(curr->next->age < newNode->age){
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
}

// Function to Print all student
void printStudent(){
	if(head == NULL){
		puts("There is no student");
		return;
	}
	
	struct Student* curr = head;
	puts("Student List:");
	int temp = table.noWidth + table.majorWidth + table.nameWidth + table.ageWidth + 13;
	int i;
	
	// Table Header
	for(i = 0; i < temp; i++) printf("=");
	puts("");
	printf("| %-*s | %-*s | %-*s | %-*s |\n", table.noWidth, "No.", table.nameWidth, "Name", table.ageWidth, "Age", table.majorWidth, "Major");
	for(i = 0; i < temp; i++) printf("=");
	puts("");
	
	// Table body
	i = 1;
	while(curr != NULL){
		printf("| %-*d | %-*s | %-*d | %-*s |\n", table.noWidth, i++, table.nameWidth, curr->name, table.ageWidth, curr->age, table.majorWidth, curr->major);
		curr = curr->next;
	}
	
	// Table close
	for(i = 0; i < temp; i++) printf("=");
	puts("");
	return;
}

// Function to delete student
void deleteStudent(){
	if(head == NULL){
		puts("There is no student");
		return;
	}
	
	printStudent();
	int choice = 0;
	int valid = 1;
	char end = '\0';
	do{
		printf("Insert student number to be deleted [1 - %d]: ", nData);
		valid = scanf("%d%c", &choice, &end);
		if(end != '\n') valid = 0;
		fflush(stdin);
	} while(choice < 1 || choice > nData || valid == 0);
	
	char type = '\0';
	if(choice == 1){
		// Pop head
		showStudentInfo(head);
		do{
			printf("Do you want to delete this data? [y / n]: ");
			scanf("%c", &type);
			fflush(stdin);
		} while(type != 'y' && type != 'n');
		
		if(type == 'n'){
			puts("Deletion canceled");
			return;	
		}
		
		struct Student* temp = head->next;
		free(head);
		head = temp;
	} else{
		struct Student* curr = head;
		int position = 1;
		choice -= 1;
		while(position < choice){
			curr = curr->next;
			position++;
		}
		
		struct Student* deletedNode = curr->next;
		
		// Show student information to be deleted
		showStudentInfo(deletedNode);
		do{
			printf("Do you want to delete this data? [y / n]: ");
			scanf("%c", &type);
			fflush(stdin);
		} while(type != 'y' && type != 'n');
		
		if(type == 'n'){
			puts("Deletion canceled");
			return;	
		}
		
		// If the deleted node is the tail node
		if(deletedNode == tail){
			free(deletedNode);
			tail = curr;
			tail->next = NULL;
			nData--;
			return;
		}
		
		// If the deleted node is not the tail node
		curr->next = deletedNode->next;
		free(deletedNode);		
	}
	nData--;
}

// Function to show student info
void showStudentInfo(struct Student* node){
	puts("Student Data");
	printf("Name\t: %s\n", node->name);
	printf("Major\t: %s\n", node->major);
	printf("Age\t: %u\n", node->age);
}

// Function when the program is closed
void save(){
	FILE* fWriter = fopen("Data/students.txt", "w");
	
	// Write the column
	fprintf(fWriter, "name;age;major\n");
	
	// If all data is deleted
	if(head == NULL) return;
	
	struct Student* curr = head;
	while(curr != NULL){
		fprintf(fWriter, "%s;%u;%s\n", curr->name, curr->age, curr->major);
		curr = curr->next;
	}
	fclose(fWriter);
}
