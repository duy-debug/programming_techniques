#include <stdio.h>
int luythua(int l, int r, int a, int n){
	if(l==r) return a;
	int m=(l+r)/2;
	return luythua(l,m,a,n)*luythua(m+1,r,a,n);
}
int main(){
	int a,n;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("%d^%d=%d",a,n,luythua(0,n-1,a,n));
}
