#include <stdio.h>
#include <stdlib.h>	
int main(int argc, char *argv[]) {
	if( argc>=3 && argc<11){
		int i, s=0;
		for(i=1; i<argc-1; i++){
			s+=atoi(argv[i]);
			printf("tong day so la %d", s);
		}
	}
}
