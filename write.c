#include <stdio.h>
#include <string.h>


typedef struct {
	char name[20];
	int age;
} Person;

Person newPerson(char *name, int age);
void displayPerson(Person p);

int main() {
	
	Person list[5];
	
	list[0] = newPerson("Kurt", 12);
	list[1] = newPerson("Zander", 21);
	list[2] = newPerson("Borromeo", 18);
	list[3] = newPerson("Zues", 20);
	list[4] = newPerson("Alnino", 35);
	
	
	
	FILE *fp;
	
	fp = fopen("person_file.txt", "wb");
	
	if(fp == NULL){
		return 1;
	}
	
	fwrite(list+2, sizeof(Person), 2, fp);
	
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
