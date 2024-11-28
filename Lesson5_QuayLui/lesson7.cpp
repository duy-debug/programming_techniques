//Liet ke tat ca tap con co k phan tu tu tap {1,2,3,...,n}
//1 2 3 4
//k=2
//{1,2}, {1,3}, {1,4}, {2,3}...
#include <stdio.h>
int n=4, k=2;
int a[1000];
void Print(){
	int cnt=0;
	for(int i=0; i<n; i++){
		if(a[i]==0)
			cnt++; 
	}
	if(cnt==k){
		for(int i=0; i<n; i++){
			if(a[i]==0)
				printf("%d ",i+1);
		}
		printf("\n");
	}
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
/*
cach 2:
#include <stdio.h>
int n, x[100], k;
void Print(){
	for(int i=1; i<=k; i++){
		printf("%d", x[i]);
	}
	printf("\n");
}
void try1(int i){
	for(int j=x[i-1]+1; j<=n-k+i; j++){
		x[i]=j;
		if(i==k)
			Print();
		else 
			try1(i+1);
	}
}
int main(){
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap k: ");
	scanf("%d", &k);
	x[0]=0;
	try1(1);
}
*/
int main(){
	try1(0);
}
