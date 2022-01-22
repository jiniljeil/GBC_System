#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct { 
	char name[12] ; 
	void (*print) (void*) ; 
} test; 

void printName(test * t) 
{ 
	printf("printName: %s\n", t->name) ; 
}

void uaf() { 
	printf("Use After Free");  
}

int main(void) { 
	test * t ;
	char * string ; 
	
	t = malloc(128) ; 
	
	strcpy(t->name, "John"); 
	t->print = (void *)printName; 
	
	t->print(t); 
	free(t) ; 
	
	string = malloc(128) ; 
	scanf("%s", string) ; 
	
	t->print(t);  
	
	return 0; 
} 
