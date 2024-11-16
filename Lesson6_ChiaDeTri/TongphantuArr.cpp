#include <stdio.h>
int S(int a[], int l, int r){
	if(l==r) return a[l];
	int mid=(l+r)/2;
	return S(a,l,mid)+S(a,mid+1,r);
}
int main(){
	int a[100], n;
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	}while(n<=5 || n>=100);
	for(int i=0; i<n ;i++){
		scanf("%d", &a[i]);
	}
	printf("Tong = %d", S(a,0,n-1));
}
