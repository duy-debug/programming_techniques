#include <stdio.h>
int search_binary(int a[], int l, int r, int n, int x){
	if(l>r) return -1;
	int mid=(l+r)/2;
	if(a[mid]==x) return mid;
	if(a[mid]>x) 
		return search_binary(a,l,mid-1,n,x);
	else
		return search_binary(a,mid+1,r,n,x);
}
int main(){
	int a[100], n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int x;
	printf("Nhap x: ");
	scanf("%d", &x);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("Vi tri x la: %d", search_binary(a,0,n-1,n,x));
}
