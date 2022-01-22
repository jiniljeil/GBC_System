#include <stdio.h>
#include <stdlib.h> 

// Use After Free 

int main(void) {
	char * buf; 
	char * buf2; 
	buf = (char *)malloc(sizeof(char) * 128) ; 
	
	gets(buf) ; 
	free(buf) ; 
	
	buf2 = (char *)malloc(sizeof(char) * 64) ; 

	printf("buf: %s\n", buf2) ; 
	return 0;  
} 	
