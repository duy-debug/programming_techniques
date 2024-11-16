// Tong n so nguyen duong dau tien
#include <stdio.h>
int Sum(int l, int r){
	if(l==r) return l;
	int m=(l+r)/2;
	return Sum(l,m)+Sum(m+1,r);
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d", Sum(1,n));
}
