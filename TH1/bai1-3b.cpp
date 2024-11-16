#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	if(argc>=2){
		float s=0;
		for(int i=1; i<argc; i++){
			s+=atof(argv[i]);
		}
		printf("TBC: %.3f", s/(argc-1));
	}
}
