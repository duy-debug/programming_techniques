#include <stdio.h>
int n=3;
int a[1000];
void Print(){
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void try1(int i){
	for(int j=0; j<=1; j++){
		a[i]=j;
		if(i<n-1)
			try1(i+1);
		else
			Print();
	}
}
int main(){
	try1(0);
}
