//Liet ke tat ca cac hoan vi cua day {1,2,3...n}
#include <stdio.h>
int n=3;
int a[1000];
int check[1000]={0};
void Print(){
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void try1(int i){
	for(int j=0; j<n; j++){
		if(!check[j]){
			a[i]=j;
			check[j] = 1;
		if(i==n-1)
			Print();
		else
			try1(i+1);
		check[j]=0;
		}
	}
}
int main(){
	try1(0);
}
