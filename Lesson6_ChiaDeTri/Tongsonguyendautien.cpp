#include <stdio.h>
int sum(int l, int r){
	if(l==r) return l;
	int mid=(l+r)/2;
	return sum(l,mid)+sum(mid+1,r);
}
int main(){
	int n;
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	}while(5<=n || n>=100);
	printf("Tong %d so nguyen duong dau tien: %d", n, sum(0,n));
}
