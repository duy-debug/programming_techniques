#include <stdio.h>
inline int MIN(int x, int y, int z){
	int min=x;
	if(y<min)
		min=y;
	if(z<min)
		min=z;
	return min;
}
int main(){
	int a, b, c;
	printf("Nhap a: "); 
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	printf("Nhap c: ");
	scanf("%d", &c);
	printf("Gia tri nhat nho: %d", MIN(a,b,c));
}
