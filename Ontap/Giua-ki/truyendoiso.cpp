#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
	for(int i=1; i<argc-1; i++){
		if(atof(argv[i])>atof(argv[i+1])){
			printf("Day khong tang dan!");
			return 0;
		}
	}
	printf("Day tang dan!");
	return 0;
}
