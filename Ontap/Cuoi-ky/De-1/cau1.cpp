#include <stdio.h>
#include <stdlib.h>
int n, a[100];
void readfile(char *s){
	FILE *f=fopen(s,"r");
	if(f==NULL){
		printf("Khong the doc file");
	}
	else{
		fscanf(f,"%d",&n);
		for(int i=0; i<n; i++){
			fscanf(f,"%d",&a[i]);
		}
		fclose(f);
	}
}
void Print(){
	printf("%d\n",n);
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}
// dem so luong so nguyen am nam o vi tri le
int dem(int a[], int n){
	if(n==0) return 0;
	if(n%2==1 && a[n]<0)
		return 1+dem(a,n-1);
	return dem(a,n-1); 
}
int main(){
	char *s="input1.txt";
	readfile(s);
	Print();
	printf("\nSo luong so nguyen am o vi tri le: %d", dem(a,n-1));
}
