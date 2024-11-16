#include <stdio.h>
int s(int l, int r){
	if(l==r) return l*l;
	int mid=(l+r)/2;
	return s(l,mid)+s(mid+1,r);
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("S = %d", s(0,n));
}
