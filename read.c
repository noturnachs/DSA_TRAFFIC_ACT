#include <stdio.h>
#include <string.h>


typedef struct {
	char name[20];
	int age;
} Person;

Person newPerson(char *name, int age);
void displayPerson(Person p);

int main() {
	
	Person p;
	
	
	FILE *fp;
	
	fp = fopen("person_file.txt", "rb");
	
	if(fp == NULL){
		return 1;
	}
	
	while(fread(&p, sizeof(Person), 1, fp)) {
		displayPerson(p);
		printf("\n");
	}
	
	fclose(fp);
	
	return 0;
	
	
}


Person newPerson(char *name, int age){
	
	Person p;
	
	strcpy(p.name, name);
	p.age = age;
	
	return p;
}


void displayPerson(Person p){
	printf("%-15s - %d years old", p.name, p.age);
}
