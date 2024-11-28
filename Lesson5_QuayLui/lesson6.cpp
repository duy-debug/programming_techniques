#include <stdio.h>
void Print(int x[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", x[i]);
	}
	printf("\n");
}
void try1(int i, int x[], int n){
	for(int j=0; j<=1; j++){
		x[i]=j;
		if(i==n-1)
			Print(x,n);
		else 
			try1(i+1,x,n);
	}
}
int main(){
	int n, x[100];;
	printf("Nhap n: ");
	scanf("%d", &n);
	try1(0,x,n);
	
}
