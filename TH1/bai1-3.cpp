#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    if(argc==4){
        int a=atoi(argv[1]);
        char c=*argv[2];
        int b=atoi(argv[3]);
		switch(c){
		    case '+': printf("%d + %d = %d", a,b,a+b); break;
		    case '-': printf("%d - %d = %d", a,b,a-b); break;
		    case '*': printf("%d * %d = %d", a,b,a*b); break;
		    case '/': if(b!=0)
		    printf("%d / %d = %d",a,b,a/b);
		    else
		    printf("Loi phep chia");
		}
    }
    else{
    	printf("Khong hop le");
	}
}
