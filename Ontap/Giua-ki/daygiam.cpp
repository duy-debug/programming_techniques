#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
	float sum=0;
    for(int i=1; i<argc; i++){
    	sum+=atof(argv[i]);
	}
	printf("Tong : %.2f", sum);
}
