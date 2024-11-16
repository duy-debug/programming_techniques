#include <stdio.h>
int Tong(int n){
	if(n==0) return 0;
	else return n+Tong(n-1);
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Tong S(%d)= %d", n, Tong(n));
}
