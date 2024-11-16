#include <stdio.h>
int SUM(int a[], int l, int r){
	if(l==r) return a[l];
	int m=(l+r)/2;
	return SUM(a,l,m)+SUM(a,m+1,r);
} 
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++){
		printf("Nhap phan tu thu %d: ", i);
		scanf("%d", &a[i]);
	}
	printf("Tong =%d", SUM(a,0,n-1));
}
