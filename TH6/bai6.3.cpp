#include <stdio.h>
#include <stdlib.h>
int a[100];
int b[100];
int n,s;
void Print(){
	int sum=0;
	for(int i=0; i<n; i++){
		if(b[i]==0)
			sum+=a[i];
	}
	if(sum==s){
		for(int i=0; i<n; i++){
			if(b[i]==0)
				printf("%d ",a[i]);
		}
		printf("\n");
	}
}
void try1(int i){
	for(int j=0 ; j<=1; j++){
		b[i]=j;
		if(i<n-1)
			try1(i+1);
		else
			Print();
	}
}
int main(){
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap s: ");
	scanf("%d", &s);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	try1(0);
}
